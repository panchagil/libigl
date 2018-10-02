// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/view_axis.h>

const char* ds_view_axis = R"igl_Qu8mg5v7(
See view_axis for the documentation.
)igl_Qu8mg5v7";

npe_function(view_axis)
npe_doc(ds_view_axis)

npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v;
    igl::    opengl2::view_axis(v);
    return npe::move(v);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v;
    igl::    opengl2::view_axis(v);
    return npe::move(v);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/view_axis.h>

const char* ds_view_axis = R"igl_Qu8mg5v7(

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

 Determines the view axis or depth axis of the current gl matrix
     Inputs:
       mv pointer to modelview matrix
     Outputs:
       x  pointer to x-coordinate in scene coordinates of the un-normalized
         viewing axis 
       y  pointer to y-coordinate in scene coordinates of the un-normalized
         viewing axis 
       z  pointer to z-coordinate in scene coordinates of the un-normalized
         viewing axis
    
     Note: View axis is returned *UN-normalized*
)igl_Qu8mg5v7";

npe_function(view_axis)
npe_doc(ds_view_axis)

npe_arg(mv, double *)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    double * x;
    double * y;
    double * z;
    igl::    opengl2::view_axis(mv, x, y, z);
    return std::make_tuple(    npe::move(x),
    npe::move(y),
    npe::move(z));
} else if (dtype.type() == npe::type_f64) {
    double * x;
    double * y;
    double * z;
    igl::    opengl2::view_axis(mv, x, y, z);
    return std::make_tuple(    npe::move(x),     npe::move(y),     npe::move(z));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/view_axis.h>

const char* ds_view_axis = R"igl_Qu8mg5v7(

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

 Extract mv from current GL state.
)igl_Qu8mg5v7";

npe_function(view_axis)
npe_doc(ds_view_axis)

npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    double * x;
    double * y;
    double * z;
    igl::    opengl2::view_axis(x, y, z);
    return std::make_tuple(    npe::move(x),
    npe::move(y),
    npe::move(z));
} else if (dtype.type() == npe::type_f64) {
    double * x;
    double * y;
    double * z;
    igl::    opengl2::view_axis(x, y, z);
    return std::make_tuple(    npe::move(x),     npe::move(y),     npe::move(z));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


