// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/trackball.h>

const char* ds_trackball = R"igl_Qu8mg5v7(

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

 Applies a trackball drag to identity
   Inputs:
     w  width of the trackball context
     h  height of the trackball context
     speed_factor  controls how fast the trackball feels, 1 is normal
     down_mouse_x  x position of mouse down
     down_mouse_y  y position of mouse down
     mouse_x  current x position of mouse
     mouse_y  current y position of mouse
   Outputs:
     quat  the resulting rotation (as quaternion)
)igl_Qu8mg5v7";

npe_function(trackball)
npe_doc(ds_trackball)

npe_arg(w, double)
npe_arg(h, double)
npe_arg(speed_factor, Q_type)
npe_arg(down_mouse_x, double)
npe_arg(down_mouse_y, double)
npe_arg(mouse_x, double)
npe_arg(mouse_y, double)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Q_type * quat;
    igl::trackball(w, h, speed_factor, down_mouse_x, down_mouse_y, mouse_x, mouse_y, quat);
    return npe::move(quat);
} else if (dtype.type() == npe::type_f64) {
    Q_type * quat;
    igl::trackball(w, h, speed_factor, down_mouse_x, down_mouse_y, mouse_x, mouse_y, quat);
    return npe::move(quat);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/trackball.h>

const char* ds_trackball = R"igl_Qu8mg5v7(

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

 Applies a trackball drag to a given rotation
   Inputs:
     w  width of the trackball context
     h  height of the trackball context
     speed_factor  controls how fast the trackball feels, 1 is normal
     down_quat  rotation at mouse down, i.e. the rotation we're applying the
       trackball motion to (as quaternion)
     down_mouse_x  x position of mouse down
     down_mouse_y  y position of mouse down
     mouse_x  current x position of mouse
     mouse_y  current y position of mouse
   Outputs:
     quat  the resulting rotation (as quaternion)
)igl_Qu8mg5v7";

npe_function(trackball)
npe_doc(ds_trackball)

npe_arg(w, double)
npe_arg(h, double)
npe_arg(speed_factor, Q_type)
npe_arg(down_quat, Q_type *)
npe_arg(down_mouse_x, double)
npe_arg(down_mouse_y, double)
npe_arg(mouse_x, double)
npe_arg(mouse_y, double)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Q_type * quat;
    igl::trackball(w, h, speed_factor, down_quat, down_mouse_x, down_mouse_y, mouse_x, mouse_y, quat);
    return npe::move(quat);
} else if (dtype.type() == npe::type_f64) {
    Q_type * quat;
    igl::trackball(w, h, speed_factor, down_quat, down_mouse_x, down_mouse_y, mouse_x, mouse_y, quat);
    return npe::move(quat);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/trackball.h>

const char* ds_trackball = R"igl_Qu8mg5v7(

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

 Eigen wrapper.
)igl_Qu8mg5v7";

npe_function(trackball)
npe_doc(ds_trackball)

npe_arg(w, double)
npe_arg(h, double)
npe_arg(speed_factor, double)
npe_arg(down_quat, Eigen::Quaternion<Scalardown_quat> &)
npe_arg(down_mouse_x, double)
npe_arg(down_mouse_y, double)
npe_arg(mouse_x, double)
npe_arg(mouse_y, double)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::Quaternion<Scalarquat> & quat;
    igl::trackball(w, h, speed_factor, down_quat, down_mouse_x, down_mouse_y, mouse_x, mouse_y, quat);
    return npe::move(quat);
} else if (dtype.type() == npe::type_f64) {
    Eigen::Quaternion<Scalarquat> & quat;
    igl::trackball(w, h, speed_factor, down_quat, down_mouse_x, down_mouse_y, mouse_x, mouse_y, quat);
    return npe::move(quat);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


