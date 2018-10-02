#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/edges.h>

const char* ds_edges = R"igl_Qu8mg5v7(

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

 Constructs a list of unique edges represented in a given mesh (V,F)
  
   Inputs:
     F  #F by 3 list of mesh faces (must be triangles)
     or
     T  #T x 4  matrix of indices of tet corners
   Outputs:
     E #E by 2 list of edges in no particular order
  
   See also: adjacency_matrix
)igl_Qu8mg5v7";

npe_function(edges)
npe_doc(ds_edges)

npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 e;
    igl::edges(f, e);
    return npe::move(e);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 e;
    igl::edges(f, e);
    return npe::move(e);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


