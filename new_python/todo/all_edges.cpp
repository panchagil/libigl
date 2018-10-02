#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/all_edges.h>

const char* ds_all_edges = R"igl_Qu8mg5v7(

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

 Deprecated: call oriented_facets instead.
  
   ALL_EDGES Determines all "directed edges" of a given set of simplices. For
   a manifold mesh, this computes all of the half-edges
  
   Inputs:
     F  #F by simplex_size list of "faces"
   Outputs:
     E  #E by simplex_size-1  list of edges
  
   Note: this is not the same as igl::edges because this includes every
   directed edge including repeats (meaning interior edges on a surface will
   show up once for each direction and non-manifold edges may appear more than
   once for each direction).
)igl_Qu8mg5v7";

npe_function(all_edges)
npe_doc(ds_all_edges)

npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 e;
    igl::all_edges(f, e);
    return npe::move(e);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 e;
    igl::all_edges(f, e);
    return npe::move(e);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


