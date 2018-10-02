// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/normalize_quat.h>

const char* ds_normalize_quat = R"igl_Qu8mg5v7(

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

 Normalize a quaternion
   A Quaternion, q, is defined here as an arrays of four scalars (x,y,z,w),
   such that q = x*i + y*j + z*k + w
   Inputs:
     q  input quaternion
   Outputs:
     out  result of normalization, allowed to be same as q
   Returns true on success, false if len(q) < EPS
)igl_Qu8mg5v7";

npe_function(normalize_quat)
npe_doc(ds_normalize_quat)

npe_arg(q, Q_type *)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Q_type * out;
    igl::normalize_quat(q, out);
    return npe::move(out);
} else if (dtype.type() == npe::type_f64) {
    Q_type * out;
    igl::normalize_quat(q, out);
    return npe::move(out);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


