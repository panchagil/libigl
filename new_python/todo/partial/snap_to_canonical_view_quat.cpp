// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/snap_to_canonical_view_quat.h>

const char* ds_snap_to_canonical_view_quat = R"igl_Qu8mg5v7(

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

 Snap the quaternion q to the nearest canonical view quaternion
   Input:
     q  quaternion to be snapped (also see Outputs)
     threshold  (optional) threshold:
       1.0 --> snap any input
       0.5 --> snap inputs somewhat close to canonical views
       0.0 --> snap no input
   Output:
     q  quaternion possibly set to nearest canonical view
   Return:
     true only if q was snapped to the nearest canonical view
)igl_Qu8mg5v7";

npe_function(snap_to_canonical_view_quat)
npe_doc(ds_snap_to_canonical_view_quat)

npe_arg(q, Q_type *)
npe_arg(threshold, Q_type)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Q_type * s;
    igl::snap_to_canonical_view_quat(q, threshold, s);
    return npe::move(s);
} else if (dtype.type() == npe::type_f64) {
    Q_type * s;
    igl::snap_to_canonical_view_quat(q, threshold, s);
    return npe::move(s);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/snap_to_canonical_view_quat.h>

const char* ds_snap_to_canonical_view_quat = R"igl_Qu8mg5v7(
See snap_to_canonical_view_quat for the documentation.
)igl_Qu8mg5v7";

npe_function(snap_to_canonical_view_quat)
npe_doc(ds_snap_to_canonical_view_quat)

npe_arg(q, Eigen::Quaternion<Scalarq> &)
npe_arg(threshold, double)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::Quaternion<Scalars> & s;
    igl::snap_to_canonical_view_quat(q, threshold, s);
    return npe::move(s);
} else if (dtype.type() == npe::type_f64) {
    Eigen::Quaternion<Scalars> & s;
    igl::snap_to_canonical_view_quat(q, threshold, s);
    return npe::move(s);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


