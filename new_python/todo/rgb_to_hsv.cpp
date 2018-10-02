// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/rgb_to_hsv.h>

const char* ds_rgb_to_hsv = R"igl_Qu8mg5v7(
See rgb_to_hsv for the documentation.
)igl_Qu8mg5v7";

npe_function(rgb_to_hsv)
npe_doc(ds_rgb_to_hsv)

npe_arg(r, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 h;
    igl::rgb_to_hsv(r, h);
    return npe::move(h);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 h;
    igl::rgb_to_hsv(r, h);
    return npe::move(h);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/rgb_to_hsv.h>

const char* ds_rgb_to_hsv = R"igl_Qu8mg5v7(

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

 Convert RGB to HSV
  
   Inputs:
     r  red value ([0,1]) 
     g  green value ([0,1])
     b  blue value ([0,1])
   Outputs:
     h  hue value (degrees: [0,360])
     s  saturation value ([0,1])
     v  value value ([0,1])
)igl_Qu8mg5v7";

npe_function(rgb_to_hsv)
npe_doc(ds_rgb_to_hsv)

npe_arg(rgb, R *)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    H * hsv;
    igl::rgb_to_hsv(rgb, hsv);
    return npe::move(hsv);
} else if (dtype.type() == npe::type_f64) {
    H * hsv;
    igl::rgb_to_hsv(rgb, hsv);
    return npe::move(hsv);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


