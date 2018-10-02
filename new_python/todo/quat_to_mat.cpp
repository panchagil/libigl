// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/quat_to_mat.h>

const char* ds_quat_to_mat = R"igl_Qu8mg5v7(

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

 Convert a quaternion to a 4x4 matrix
   A Quaternion, q, is defined here as an arrays of four scalars (x,y,z,w),
   such that q = x*i + y*j + z*k + w
   Input:
     quat  pointer to four elements of quaternion (x,y,z,w)  
   Output:
     mat  pointer to 16 elements of matrix
)igl_Qu8mg5v7";

npe_function(quat_to_mat)
npe_doc(ds_quat_to_mat)

npe_arg(quat, Q_type *)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Q_type * mat;
    igl::quat_to_mat(quat, mat);
    return npe::move(mat);
} else if (dtype.type() == npe::type_f64) {
    Q_type * mat;
    igl::quat_to_mat(quat, mat);
    return npe::move(mat);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


