// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/mat4_to_quat.h>

const char* ds_mat4_to_quat = R"igl_Qu8mg5v7(

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

 Convert a OpenGL (rotation) matrix to a quaternion
  
   Input:
     m  16-element opengl rotation matrix
   Output:
     q  4-element  quaternion (not normalized)
)igl_Qu8mg5v7";

npe_function(mat4_to_quat)
npe_doc(ds_mat4_to_quat)

npe_arg(m, Q_type *)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Q_type * q;
    igl::mat4_to_quat(m, q);
    return npe::move(q);
} else if (dtype.type() == npe::type_f64) {
    Q_type * q;
    igl::mat4_to_quat(m, q);
    return npe::move(q);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/mat3_to_quat.h>

const char* ds_mat3_to_quat = R"igl_Qu8mg5v7(

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

 Input:
     m  9-element opengl rotation matrix
)igl_Qu8mg5v7";

npe_function(mat3_to_quat)
npe_doc(ds_mat3_to_quat)

npe_arg(m, Q_type *)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Q_type * q;
    igl::mat3_to_quat(m, q);
    return npe::move(q);
} else if (dtype.type() == npe::type_f64) {
    Q_type * q;
    igl::mat3_to_quat(m, q);
    return npe::move(q);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


