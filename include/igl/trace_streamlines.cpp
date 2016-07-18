#include "trace_streamlines.h"
#include "sort_vectors_ccw.h"
#include "per_face_normals.h"
#include "polyvector_field_matchings.h"


#include <Eigen/Geometry>

template<typename DerivedSource, typename DerivedDir>
IGL_INLINE bool igl::segments_intersect(
        const Eigen::PlainObjectBase <DerivedSource> &p,
        const Eigen::PlainObjectBase <DerivedDir> &r,
        const Eigen::PlainObjectBase <DerivedSource> &q,
        const Eigen::PlainObjectBase <DerivedDir> &s,
        double &a_t,
        double &a_u,
        double eps
)
{
    // http://stackoverflow.com/questions/563198/how-do-you-detect-where-two-line-segments-intersect
    // Search intersection between two segments
    // p + t*r :  t \in [0,1]
    // q + u*s :  u \in [0,1]

    // p + t * r = q + u * s  // x s
    // t(r x s) = (q - p) x s
    // t = (q - p) x s / (r x s)

    // (r x s) ~ 0 --> directions are parallel, they will never cross
    Eigen::RowVector3d rxs = r.cross(s);
    if (rxs.norm() <= eps)
        return false;

    int sign;

    double u;
    // u = (q − p) × r / (r × s)
    Eigen::RowVector3d u1 = (q - p).cross(r);
    sign = ((u1.dot(rxs)) > 0) ? 1 : -1;
    u = u1.norm() / rxs.norm();
    u = u * sign;

    if ((u - 1.) > eps || u < -eps)
        return false;

    double t;
    // t = (q - p) x s / (r x s)
    Eigen::RowVector3d t1 = (q - p).cross(s);
    sign = ((t1.dot(rxs)) > 0) ? 1 : -1;
    t = t1.norm() / rxs.norm();
    t = t * sign;

    if (t < -eps || fabs(t) < eps)
        return false;

    a_t = t;
    a_u = u;

    return true;
};

template<typename DerivedV, typename DerivedF, typename DerivedS, typename DerivedM>
IGL_INLINE void igl::trace_streamlines(
        const Eigen::PlainObjectBase <DerivedV> &V,
        const Eigen::PlainObjectBase <DerivedF> &F,
        const Eigen::MatrixXi TT,
        const Eigen::MatrixXi &F2E,
        const Eigen::MatrixXi &E2F,
        const Eigen::PlainObjectBase <DerivedS> &field,
        const Eigen::PlainObjectBase <DerivedM> &match_ab,
        const Eigen::PlainObjectBase <DerivedM> &match_ba,
        Eigen::MatrixXd &start_point,
        Eigen::MatrixXd &end_point,
        Eigen::MatrixXi &face,
        Eigen::MatrixXi &direction
)
{
    using namespace Eigen;
    using namespace std;

    int degree = face.cols();
    int nsample = face.rows();

    for (int i = 0; i < degree; ++i)
    {
        for (int j = 0; j < nsample; ++j)
        {

            int f0 = face(j,i);
            if (f0 == -1) // reach boundary
                continue;
            int m0 = direction(j, i);

            // the starting point of the vector
            const Eigen::RowVector3d &p = start_point.row(j + nsample * i);
            // the direction where we are trying to go
            const Eigen::RowVector3d &r = field.block(f0, 3 * m0, 1, 3);


            // new state,
            int f1, m1;

            for (int k = 0; k < 3; ++k)
            {
                f1 = TT(f0, k);

                // edge vertices
                const Eigen::RowVector3d &q = V.row(F(f0, k));
                const Eigen::RowVector3d &qs = V.row(F(f0, (k + 1) % 3));
                // edge direction
                Eigen::RowVector3d s = qs - q;

                double u;
                double t;
                if (igl::segments_intersect(p, r, q, s, t, u))
                {
                    // point on next face
                    end_point.row(j + nsample * i) = p + t * r;
                    face(j,i) = f1;

                    // matching direction on next face
                    int e1 = F2E(f0, k);
                    if (E2F(e1, 0) == f0)
                        m1 = match_ab(e1, m0);
                    else
                        m1 = match_ba(e1, m0);

                    direction(j, i) = m1;
                    break;
                }

            }


        }
    }
}

template<typename DerivedV, typename DerivedF, typename DerivedS, typename DerivedM>
IGL_INLINE void igl::trace_polyvector_field_sort(
        const Eigen::PlainObjectBase<DerivedV>& V,
        const Eigen::PlainObjectBase<DerivedF>& F,
        const Eigen::PlainObjectBase<DerivedS>& temp_field,
        const bool treat_as_symmetric,
        Eigen::PlainObjectBase <DerivedS>& field,
        Eigen::PlainObjectBase <DerivedM> &match_ab,
        Eigen::PlainObjectBase <DerivedM> &match_ba
){
    int degree;
    int half_degree = temp_field.cols() / 3;
    if (treat_as_symmetric)
        degree = half_degree * 2;
    else
        degree = half_degree;

    Eigen::MatrixXd FN;
    igl::per_face_normals(V, F, FN);

    // Sort vectors ccw and project on the tangent plane
    Eigen::VectorXi order;
    Eigen::VectorXi inv_order_unused;
    Eigen::RowVectorXd sorted;

    field.setZero(F.rows(), degree * 3);
    for (unsigned i = 0; i < F.rows(); ++i)
    {
        const Eigen::RowVectorXd &n = FN.row(i);
        Eigen::RowVectorXd temp(1, degree * 3);
        if (treat_as_symmetric)
            temp << temp_field.row(i), -temp_field.row(i);
        else
            temp = temp_field.row(i);
        igl::sort_vectors_ccw(temp, n, order, true, sorted, false, inv_order_unused);

        // project vectors to tangent plane
        for (int j = 0; j < degree; ++j)
        {
            Eigen::RowVector3d pd = sorted.segment(j * 3, 3);
            pd = (pd - (n.dot(pd)) * n).normalized();
            field.block(i, j * 3, 1, 3) = pd;
        }
    }
    Eigen::VectorXd curl;
    igl::polyvector_field_matchings(field, V, F, false, match_ab, match_ba, curl);
}

IGL_INLINE void igl::trace_seeds(
        const Eigen::MatrixXd& V,
        const Eigen::MatrixXi& F,
        const int degree,
        Eigen::VectorXi& samples,
        Eigen::MatrixXd& start_point,
        Eigen::MatrixXd& end_point,
        Eigen::MatrixXi& face,
        Eigen::MatrixXi& direction
)
{
    int nsamples;
    double percentage = 0.3;

    if (F.rows() < 20)
    {
        nsamples = F.rows();
        samples.resize(nsamples, 1);
        for (int i = 0; i < nsamples; ++i)
            samples[i] = i;
    }
    else
    {
        nsamples = percentage * F.rows();
        Eigen::VectorXd r;
        r.setRandom(nsamples, 1);
        r = (1 + r.array()) / 2.;
        samples = (r.array() * F.rows()).cast<int>();
    }


    Eigen::MatrixXd BC, BC_sample;
    igl::barycenter(V, F, BC);
    igl::slice(BC, samples, 1, BC_sample);

    // initialize points for tracing vector field

    start_point = BC_sample.replicate(degree,1);
    end_point = start_point;

    face = samples.replicate(1, degree);

    direction.setZero(nsamples, degree);
    for (int i = 0; i < nsamples; ++i)
        for (int j = 0; j < degree; ++j)
            direction(i, j) = j;
}