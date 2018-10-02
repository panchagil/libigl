// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/hsv_to_rgb.h>

const char* ds_hsv_to_rgb = R"igl_Qu8mg5v7(
See hsv_to_rgb for the documentation.
)igl_Qu8mg5v7";

npe_function(hsv_to_rgb)
npe_doc(ds_hsv_to_rgb)

npe_arg(h, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 r;
    igl::hsv_to_rgb(h, r);
    return npe::move(r);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 r;
    igl::hsv_to_rgb(h, r);
    return npe::move(r);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/hsv_to_rgb.h>

const char* ds_hsv_to_rgb = R"igl_Qu8mg5v7(

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
     h  hue value (degrees: [0,360])
     s  saturation value ([0,1])
     v  value value ([0,1])
   Outputs:
     r  red value ([0,1]) 
     g  green value ([0,1])
     b  blue value ([0,1])
)igl_Qu8mg5v7";

npe_function(hsv_to_rgb)
npe_doc(ds_hsv_to_rgb)

npe_arg(hsv, T *)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    T * rgb;
    igl::hsv_to_rgb(hsv, rgb);
    return npe::move(rgb);
} else if (dtype.type() == npe::type_f64) {
    T * rgb;
    igl::hsv_to_rgb(hsv, rgb);
    return npe::move(rgb);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/hsv_to_rgb.h>

const char* ds_hsv_to_rgb = R"igl_Qu8mg5v7(
See hsv_to_rgb for the documentation.
)igl_Qu8mg5v7";

npe_function(hsv_to_rgb)
npe_doc(ds_hsv_to_rgb)

npe_arg(h, T &)
npe_arg(s, T &)
npe_arg(v, T &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    T & r;
    T & g;
    T & b;
    igl::hsv_to_rgb(h, s, v, r, g, b);
    return std::make_tuple(    npe::move(r),
    npe::move(g),
    npe::move(b));
} else if (dtype.type() == npe::type_f64) {
    T & r;
    T & g;
    T & b;
    igl::hsv_to_rgb(h, s, v, r, g, b);
    return std::make_tuple(    npe::move(r),     npe::move(g),     npe::move(b));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


