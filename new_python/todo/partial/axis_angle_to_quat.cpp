// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/axis_angle_to_quat.h>

const char* ds_axis_angle_to_quat = R"igl_Qu8mg5v7(

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

 Convert axis angle representation of a rotation to a quaternion
   A Quaternion, q, is defined here as an arrays of four scalars (x,y,z,w),
   such that q = x*i + y*j + z*k + w
   Inputs:
     axis  3d vector
     angle  scalar
   Outputs:
     quaternion
)igl_Qu8mg5v7";

npe_function(axis_angle_to_quat)
npe_doc(ds_axis_angle_to_quat)

npe_arg(axis, Q_type *)
npe_arg(angle, Q_type)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Q_type * out;
    igl::axis_angle_to_quat(axis, angle, out);
    return npe::move(out);
} else if (dtype.type() == npe::type_f64) {
    Q_type * out;
    igl::axis_angle_to_quat(axis, angle, out);
    return npe::move(out);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


