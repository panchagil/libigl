#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/look_at.h>

const char* ds_look_at = R"igl_Qu8mg5v7(

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

 Implementation of the deprecated gluLookAt function.
  
   Inputs:
     eye  3-vector of eye position
     center  3-vector of center reference point
     up  3-vector of up vector
   Outputs:
     R  4x4 rotation matrix
  
)igl_Qu8mg5v7";

npe_function(look_at)
npe_doc(ds_look_at)

npe_arg(eye, dense_f64)
npe_arg(center, dense_f64)
npe_arg(up, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 r;
    igl::look_at(eye, center, up, r);
    return npe::move(r);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 r;
    igl::look_at(eye, center, up, r);
    return npe::move(r);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


