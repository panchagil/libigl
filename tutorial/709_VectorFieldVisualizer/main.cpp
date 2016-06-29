#include <igl/barycenter.h>
#include <igl/edge_topology.h>
#include <igl/per_face_normals.h>
#include <igl/per_vertex_normals.h>
#include <igl/polyvector_field_matchings.h>
#include <igl/read_triangle_mesh.h>
#include <igl/readOFF.h>
#include <igl/slice.h>
#include <igl/copyleft/comiso/nrosy.h>
#include <igl/sort_vectors_ccw.h>
#include <igl/triangle_triangle_adjacency.h>
#include <igl/viewer/Viewer.h>

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>

#include "parula.h"

// Mesh
Eigen::MatrixXd V;
Eigen::MatrixXi F;

// Face normals
Eigen::MatrixXd FN;

// Topology
Eigen::MatrixXi E, E2F, F2E, TT;

// Constrained faces id
Eigen::VectorXi b;

// Constrained faces representative vector
Eigen::MatrixXd bc;

// Final Output
Eigen::MatrixXd field;

// matchings across interior edges
Eigen::MatrixXi match_ab, match_ba;

std::vector <Eigen::MatrixXd> start_point;
std::vector <Eigen::MatrixXd> end_point;
std::vector <Eigen::VectorXi> current_face;
//face where end_point is
std::vector <Eigen::VectorXi> prev_face;
//face where end_point is
Eigen::MatrixXi prev_m;//face where end_point is


int nsamples;
double percentage = 0.3;

bool treat_as_symmetric = true;
//field degree
int degree;
//field half degree (=degree if field is not symmetric)
int half_degree;

double eps = 1e-6;
int anim_t = 0;
int anim_t_dir = 1;


bool pre_draw(igl::viewer::Viewer &viewer)
{
    using namespace Eigen;

    if (!viewer.core.is_animating)
        return false;

    for (int i = 0; i < start_point.size(); ++i)
    {
        start_point[i] = end_point[i];
        for (int j = 0; j < nsamples; ++j)
        {
            int fi = current_face[i][j];
            if (fi == -1)
                continue;
            int fi_prev = prev_face[i][j];

            const Eigen::RowVectorXd &frame = field.row(fi);
            int m = -1;
            if (fi == fi_prev)
            {
                assert(anim_t == 0);
                m = i;
            }
            else
            {
                int ei = -1;
                for (int k = 0; k < 3; ++k)
                    if (TT(fi_prev, k) == fi)
                    {
                        ei = F2E(fi_prev, k);
                        break;
                    }

                int prev_match = prev_m(j, i);
                if (treat_as_symmetric)
                    prev_match = prev_match % half_degree;
                if (E2F(ei, 0) == fi_prev)
                    m = match_ab(ei, prev_match);
                else
                    m = match_ba(ei, prev_match);

                if (treat_as_symmetric) if (prev_m(j, i) >= half_degree)
                    m = (m + half_degree) % degree;

            }
            prev_m(j, i) = m;

            //intersect all three edges with the vector direction
            // http://stackoverflow.com/questions/563198/how-do-you-detect-where-two-line-segments-intersect
            // the starting point of the vector
            const Eigen::RowVector3d &p = start_point[i].row(j);
            // the direction where we are trying to go
            const Eigen::RowVector3d &r = frame.block(0, 3 * m, 1, 3);

            // cross with edges
            int suitable_edges = 0;
            double t;
            int next_face;
            for (int k = 0; k < 3; ++k)
            {
                next_face = TT(fi, k);
                //first vertex of edge
                const Eigen::RowVector3d &v0 = V.row(F(fi, k));
                //second vertex of edge
                const Eigen::RowVector3d &v1 = V.row(F(fi, (k + 1) % 3));

                // starting point of the edge segment
                const Eigen::RowVector3d &q = v0;
                // direction of the edge segment (so that only parameter values 0<=t<=1
                // will be points in the edge)
                Eigen::RowVector3d s = v1 - v0;

                Eigen::RowVector3d c = r.cross(s);
                // if directions are parallel, they will never cross
                if (c.norm() <= eps)
                    continue;

                int sign;
                // point along the edge (k,k+1)
                Eigen::RowVector3d t1 = (q - p).cross(r);
                double u = t1.norm() / c.norm();
                sign = ((t1.dot(c)) > 0) ? 1 : -1;
                u = u * sign;
                // if we are out of the edge
                if ((u - 1.) > eps || u < -eps)
                    continue;

                Eigen::RowVector3d t2 = (q - p).cross(s);
                sign = ((t2.dot(c)) > 0) ? 1 : -1;
                t = t2.norm() / c.norm();
                t = t * sign;
                //if we are moving in the opposite direction of the vector
                if (t < -eps)
                    continue;
                //if we are not moving at all
                if (fabs(t) < eps)
                    continue;
                suitable_edges++;
                end_point[i].row(j) = p + t * r;
                current_face[i][j] = next_face;
                prev_face[i][j] = fi;
            }
        }
    }
    for (int i = 0; i < start_point.size(); ++i)
    {
        Eigen::RowVector3d color = Eigen::RowVector3d::Zero();
        double value = ((anim_t) % 100) / 100.;

        if (value > 0.5)
            value = 1 - value;
        value = value / 0.5;
        //parula
        int index = 255 * value;
        color[0] = parula_values[index][0];
        color[1] = parula_values[index][1];
        color[2] = parula_values[index][2];
        viewer.data.add_edges(start_point[i], end_point[i], color);
    }
    anim_t += anim_t_dir;

    return false;
}

bool key_down(igl::viewer::Viewer &viewer, unsigned char key, int modifier)
{
    if (key == ' ')
    {
        viewer.core.is_animating = !viewer.core.is_animating;
        return true;
    }
    return false;
}

int main(int argc, char *argv[])
{
    using namespace Eigen;
    using namespace std;


    // Load a mesh in OFF format
    igl::readOFF(TUTORIAL_SHARED_PATH
    "/bumpy.off", V, F);
    igl::per_face_normals(V, F, FN);
    igl::edge_topology(V, F, E, F2E, E2F);
    igl::triangle_triangle_adjacency(F, TT);

    // Create Vector Field
    // #F x 3N matrix where N is the number of vectors per face
    Eigen::MatrixXd temp_field;

    Eigen::VectorXi b;
    Eigen::MatrixXd bc;
    Eigen::VectorXd S; // unused

    b.resize(1);
    b << 0;
    bc.resize(1, 3);
    bc << 1, 1, 1;
    igl::copyleft::comiso::nrosy(V, F, b, bc, VectorXi(), VectorXd(), MatrixXd(), 1, 0.5, temp_field, S);


    // degree of vector field
    half_degree = temp_field.cols() / 3;
    if (treat_as_symmetric)
        degree = half_degree * 2;
    else
        degree = half_degree;

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

    // Match vector fields of different elements
    Eigen::VectorXd curl;
    igl::polyvector_field_matchings(field, V, F, false, match_ab, match_ba, curl);


    // Create samples to start the field rendering
    Eigen::VectorXi samples;

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
    start_point.assign(degree, BC_sample);
    end_point = start_point;

    current_face.assign(degree, samples);
    prev_face = current_face;

    prev_m.setZero(nsamples, degree);
    for (int i = 0; i < nsamples; ++i)
        for (int j = 0; j < degree; ++j)
            prev_m(i, j) = j;


    // Viewer Settings
    igl::viewer::Viewer viewer;
    viewer.data.set_mesh(V, F);
    viewer.callback_pre_draw = &pre_draw;
    viewer.callback_key_down = &key_down;

    viewer.core.show_lines = false;

    viewer.core.is_animating = false;
    viewer.core.animation_max_fps = 30.;

    // Paint mesh grayish
    Eigen::MatrixXd C;
    C.setConstant(viewer.data.V.rows(), 3, .9);
    viewer.data.set_colors(C);


    // Draw vector field
    Eigen::MatrixXd VN;
    igl::per_vertex_normals(V, F, VN);

    for (int i = 0; i < degree; ++i)
    {
        Eigen::MatrixXd v, v1 = field.block(0, i * 3, F.rows(), 3);
        igl::slice(v1, samples, 1, v);
        viewer.data.add_edges(BC_sample,
                              BC_sample + 0.059 * v,
                              Eigen::RowVector3d::Constant(i / degree));
    }

    cout <<
    "Press [space] to toggle animation" << endl;
    viewer.launch();
}



