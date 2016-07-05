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
#include <igl/trace_streamlines.h>
#include <igl/parula.h>

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>



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

    igl::trace_streamlines(V, F, TT, F2E, E2F, field, match_ab, match_ba, start_point, end_point, current_face, prev_m);

    for (int i = 0; i < start_point.size(); ++i)
    {
        Eigen::RowVector3d color = Eigen::RowVector3d::Zero();
        double value = ((anim_t) % 100) / 100.;

        if (value > 0.5)
            value = 1 - value;
        value = value / 0.5;
        igl::parula(value, color[0], color[1], color[2]);
//        //parula
//        int index = 255 * value;
//        color[0] = parula_values[index][0];
//        color[1] = parula_values[index][1];
//        color[2] = parula_values[index][2];
        viewer.data.add_edges(start_point[i], end_point[i], color);
    }
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
    bc.resize(1, 6);
    bc << 1, 0, 0;

    igl::copyleft::comiso::nrosy(V, F, b, bc, VectorXi(), VectorXd(), MatrixXd(), 1, 0.5, temp_field, S);

    Eigen::VectorXi samples;
    igl::initialize_seeds(V, F, temp_field, treat_as_symmetric, field, samples, start_point, end_point, current_face, prev_m);
    degree = field.cols() / 3;

    // Match vector fields of different elements
    Eigen::VectorXd curl;
    igl::polyvector_field_matchings(field, V, F, false, match_ab, match_ba, curl);


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
                              Eigen::RowVector3d::Constant(i / degree));
    }

    cout <<
    "Press [space] to toggle animation" << endl;
    viewer.launch();
}



