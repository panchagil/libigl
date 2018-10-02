#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/gaussian_curvature.h>

const char* ds_gaussian_curvature = R"igl_Qu8mg5v7(

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

 Compute discrete local integral gaussian curvature (angle deficit, without
   averaging by local area).
  
   Inputs:
     V  #V by 3 eigen Matrix of mesh vertex 3D positions
     F  #F by 3 eigen Matrix of face (triangle) indices
   Output:
     K  #V by 1 eigen Matrix of discrete gaussian curvature values
  
)igl_Qu8mg5v7";

npe_function(gaussian_curvature)
npe_doc(ds_gaussian_curvature)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 k;
    igl::gaussian_curvature(v, f, k);
    return npe::move(k);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 k;
    igl::gaussian_curvature(v, f, k);
    return npe::move(k);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


