// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/parallel_transport_angles.h>

const char* ds_parallel_transport_angles = R"igl_Qu8mg5v7(

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

 Inputs:
     V               #V by 3 list of mesh vertex coordinates
     F               #F by 3 list of mesh faces (must be triangles)
     FN              #F by 3 list of face normals
     E2F             #E by 2 list of the edge-to-face relation (e.g. computed
                     via igl::edge_topology)
     F2E             #F by 3 list of the face-to-edge relation (e.g. computed
                     via igl::edge_topology)
   Output:
     K               #E by 1 list of the parallel transport angles (zero
                     for all boundary edges)
  
)igl_Qu8mg5v7";

npe_function(parallel_transport_angles)
npe_doc(ds_parallel_transport_angles)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(fn, dense_f64)
npe_arg(e2_f, Eigen::MatrixXi &)
npe_arg(f2_e, Eigen::MatrixXi &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 k;
    igl::parallel_transport_angles(v, f, fn, e2_f, f2_e, k);
    return npe::move(k);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 k;
    igl::parallel_transport_angles(v, f, fn, e2_f, f2_e, k);
    return npe::move(k);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


