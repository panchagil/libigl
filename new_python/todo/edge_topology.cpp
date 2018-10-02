// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/edge_topology.h>

const char* ds_edge_topology = R"igl_Qu8mg5v7(

Parameters
----------

dtype : data-type of the returned objects, optional. Default is `float64`.
(All integer return types are `int32` by default.)

Returns
-------


See also
--------


Notes
-----
None

Examples
--------

 Initialize Edges and their topological relations (assumes an edge-manifold
   mesh)
  
   Inputs:
     V  #V by dim list of mesh vertex positions (unused)
     F  #F by 3 list of triangle indices into V
   Outputs:
     EV  #Ex2 matrix storing the edge description as pair of indices to
         vertices
     FE  #Fx3 matrix storing the Triangle-Edge relation
     EF  #Ex2 matrix storing the Edge-Triangle relation
  
   TODO: This seems to be a inferior duplicate of edge_flaps.h:
     - unused input parameter V
     - roughly 2x slower than edge_flaps
     - outputs less information: edge_flaps reveals corner opposite edge
     - FE uses non-standard and ambiguous order: FE(f,c) is merely an edge
       incident on corner c of face f. In contrast, edge_flaps's EMAP(f,c)
       reveals the edge _opposite_ corner c of face f
)igl_Qu8mg5v7";

npe_function(edge_topology)
npe_doc(ds_edge_topology)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::MatrixXi & ev;
    Eigen::MatrixXi & fe;
    Eigen::MatrixXi & ef;
    igl::edge_topology(v, f, ev, fe, ef);
    return std::make_tuple(    npe::move(ev),
    npe::move(fe),
    npe::move(ef));
} else if (dtype.type() == npe::type_f64) {
    Eigen::MatrixXi & ev;
    Eigen::MatrixXi & fe;
    Eigen::MatrixXi & ef;
    igl::edge_topology(v, f, ev, fe, ef);
    return std::make_tuple(    npe::move(ev),     npe::move(fe),     npe::move(ef));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


