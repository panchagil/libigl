// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/snap_to_fixed_up.h>

const char* ds_snap_to_fixed_up = R"igl_Qu8mg5v7(

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

 Snap an arbitrary rotation to a rotation resulting from a rotation about
   the y-axis then the x-axis (maintaining fixed up like
   two_axis_valuator_fixed_up.)
  
   Inputs:
     q  General rotation as quaternion
   Outputs:
     s the resulting rotation (as quaternion)
  
   See also: two_axis_valuator_fixed_up
)igl_Qu8mg5v7";

npe_function(snap_to_fixed_up)
npe_doc(ds_snap_to_fixed_up)

npe_arg(q, Eigen::Quaternion<Qtype> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::Quaternion<Qtype> & s;
    igl::snap_to_fixed_up(q, s);
    return npe::move(s);
} else if (dtype.type() == npe::type_f64) {
    Eigen::Quaternion<Qtype> & s;
    igl::snap_to_fixed_up(q, s);
    return npe::move(s);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


