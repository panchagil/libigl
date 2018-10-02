#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/barycenter.h>

const char* ds_barycenter = R"igl_Qu8mg5v7(

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

 Computes the barycenter of every simplex
  
   Inputs:
     V  #V x dim matrix of vertex coordinates
     F  #F x simplex_size  matrix of indices of simplex corners into V
   Output:
     BC  #F x dim matrix of 3d vertices
  
)igl_Qu8mg5v7";

npe_function(barycenter)
npe_doc(ds_barycenter)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 bc;
    igl::barycenter(v, f, bc);
    return npe::move(bc);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 bc;
    igl::barycenter(v, f, bc);
    return npe::move(bc);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


