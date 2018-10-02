// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/quat_mult.h>

const char* ds_quat_mult = R"igl_Qu8mg5v7(

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

 Computes out = q1 * q2 with quaternion multiplication
   A Quaternion, q, is defined here as an arrays of four scalars (x,y,z,w),
   such that q = x*i + y*j + z*k + w
   Inputs:
     q1  left quaternion
     q2  right quaternion
   Outputs:
     out  result of multiplication
)igl_Qu8mg5v7";

npe_function(quat_mult)
npe_doc(ds_quat_mult)

npe_arg(q1, Q_type *)
npe_arg(q2, Q_type *)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Q_type * out;
    igl::quat_mult(q1, q2, out);
    return npe::move(out);
} else if (dtype.type() == npe::type_f64) {
    Q_type * out;
    igl::quat_mult(q1, q2, out);
    return npe::move(out);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


