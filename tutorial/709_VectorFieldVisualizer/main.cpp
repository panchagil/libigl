#include <igl/barycenter.h>
#include <igl/edge_topology.h>
#include <igl/local_basis.h>
#include <igl/parula.h>
#include <igl/per_face_normals.h>
#include <igl/per_vertex_normals.h>
#include <igl/polyvector_field_matchings.h>
#include <igl/read_triangle_mesh.h>
#include <igl/readOFF.h>
#include <igl/slice.h>
#include <igl/sort_vectors_ccw.h>
#include <igl/trace_streamlines.h>
#include <igl/triangle_triangle_adjacency.h>
#include <igl/copyleft/comiso/nrosy.h>
#include <igl/viewer/Viewer.h>

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>


// Mesh
Eigen::MatrixXd V;
Eigen::MatrixXi F;

// Topology
Eigen::MatrixXi E, E2F, F2E, TT;


// vector field
Eigen::MatrixXd field;
int degree;         // degree of the vector field
int half_degree;    // degree/2 if treat_as_symmetric
bool treat_as_symmetric = true;

// vector field direction matching across interior edges
Eigen::MatrixXi match_ab, match_ba;

// sample tracing status
Eigen::MatrixXd start_point;
Eigen::MatrixXd end_point;
Eigen::MatrixXi current_face;       // face where end_point is
Eigen::MatrixXi current_direction;  // field direction for end_point

int anim_t = 0;
int anim_t_dir = 1;


void representative_to_nrosy(
        const Eigen::MatrixXd &V,
        const Eigen::MatrixXi &F,
        const Eigen::MatrixXd &R,
        const int N,
        Eigen::MatrixXd &Y)
{
    using namespace Eigen;
    using namespace std;
    MatrixXd B1, B2, B3;

    igl::local_basis(V, F, B1, B2, B3);

    Y.resize(F.rows(), 3 * N);
    for (unsigned i = 0; i < F.rows(); ++i)
    {
        double x = R.row(i) * B1.row(i).transpose();
        double y = R.row(i) * B2.row(i).transpose();
        double angle = atan2(y, x);

        for (unsigned j = 0; j < N; ++j)
        {
            double anglej = angle + M_PI * double(j) / double(N);
            double xj = cos(anglej);
            double yj = sin(anglej);
            Y.block(i, j * 3, 1, 3) = xj * B1.row(i) + yj * B2.row(i);
        }
    }
}

bool pre_draw(igl::viewer::Viewer &viewer)
{
    using namespace Eigen;

    if (!viewer.core.is_animating)
        return false;

    igl::trace_streamlines(V, F, TT, F2E, E2F, field, match_ab, match_ba,
                           start_point, end_point, current_face, current_direction);

    Eigen::RowVector3d color = Eigen::RowVector3d::Zero();
    double value = ((anim_t) % 100) / 100.;

    if (value > 0.5)
        value = 1 - value;
    value = value / 0.5;
    igl::parula(value, color[0], color[1], color[2]);
    viewer.data.add_edges(start_point, end_point, color);

    anim_t += anim_t_dir;
    start_point = end_point;
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
    igl::readOFF(TUTORIAL_SHARED_PATH "/bumpy.off", V, F);

    igl::edge_topology(V, F, E, F2E, E2F);
    igl::triangle_triangle_adjacency(F, TT);

    // Create a Vector Field
    Eigen::VectorXi b;
    Eigen::MatrixXd bc;
    Eigen::VectorXd S; // unused

    b.resize(1);
    b << 0;
    bc.resize(1, 3);
    bc << 1, 1, 1;

    half_degree = 3;
    treat_as_symmetric = true;

    Eigen::MatrixXd temp_field, temp_field2;
    igl::copyleft::comiso::nrosy(V, F, b, bc, VectorXi(), VectorXd(), MatrixXd(), 1, 0.5, temp_field, S);
    representative_to_nrosy(V, F, temp_field, half_degree, temp_field2);


    igl::trace_polyvector_field_sort(V, F, temp_field2, treat_as_symmetric, field, match_ab, match_ba);
    degree = field.cols() / 3;

    Eigen::VectorXi samples;
    igl::trace_seeds(V, F, degree, samples,
                     start_point, end_point, current_face, current_direction);

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

    Eigen::MatrixXd BC, BC_sample;
    igl::barycenter(V, F, BC);
    igl::slice(BC, samples, 1, BC_sample);

    for (int i = 0; i < degree; ++i)
    {
        Eigen::MatrixXd v, v1 = field.block(0, i * 3, F.rows(), 3);
        igl::slice(v1, samples, 1, v);
        viewer.data.add_edges(BC_sample,
                              BC_sample + 0.059 * v,
                              Eigen::RowVector3d::Constant(1.0f * i / degree));
    }

    cout <<
    "Press [space] to toggle animation" << endl;
    viewer.launch();
}



