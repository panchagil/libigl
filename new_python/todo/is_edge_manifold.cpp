#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/is_edge_manifold.h>

const char* ds_is_edge_manifold = R"igl_Qu8mg5v7(

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

 check if the mesh is edge-manifold
  
   Inputs:
     V  #V by dim list of mesh vertex positions **unneeded**
     F  #F by 3 list of triangle indices
   Returns whether mesh is edge manifold.
  
   Known Bugs:
    Does not check for non-manifold vertices
  
   See also: is_vertex_manifold
)igl_Qu8mg5v7";

npe_function(is_edge_manifold)
npe_doc(ds_is_edge_manifold)

npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 bf;
    dense_f32 e;
    dense_f32 emap;
    dense_f32 be;
    igl::is_edge_manifold(f, bf, e, emap, be);
    return std::make_tuple(    npe::move(bf),
    npe::move(e),
    npe::move(emap),
    npe::move(be));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 bf;
    dense_f64 e;
    dense_f64 emap;
    dense_f64 be;
    igl::is_edge_manifold(f, bf, e, emap, be);
    return std::make_tuple(    npe::move(bf),     npe::move(e),     npe::move(emap),     npe::move(be));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/is_edge_manifold.h>

const char* ds_is_edge_manifold = R"igl_Qu8mg5v7(
See is_edge_manifold for the documentation.
)igl_Qu8mg5v7";

npe_function(is_edge_manifold)
npe_doc(ds_is_edge_manifold)

npe_arg(f, dense_i32)



npe_begin_code()
using namespace std;



igl::is_edge_manifold(f);

return

npe_end_code()


