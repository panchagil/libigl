#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/CANONICAL_VIEW_QUAT.h>

const char* ds_canonical_view_quat = R"igl_Qu8mg5v7(

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

 Return element [i][j] of the corresponding CANONICAL_VIEW_QUAT_* of the
   given templated type
   Inputs:
     i  index of quaternion
     j  index of coordinate in quaternion i
   Returns values of CANONICAL_VIEW_QUAT_*[i][j]
)igl_Qu8mg5v7";

npe_function(canonical_view_quat)
npe_doc(ds_canonical_view_quat)

npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    int i;
    int j;
    igl::CANONICAL_VIEW_QUAT(i, j);
    return std::make_tuple(    npe::move(i),
    npe::move(j));
} else if (dtype.type() == npe::type_f64) {
    int i;
    int j;
    igl::CANONICAL_VIEW_QUAT(i, j);
    return std::make_tuple(    npe::move(i),     npe::move(j));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/CANONICAL_VIEW_QUAT.h>

const char* ds_canonical_view_quat = R"igl_Qu8mg5v7(

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

 Template specializations for float and double
)igl_Qu8mg5v7";

npe_function(canonical_view_quat)
npe_doc(ds_canonical_view_quat)

npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    int i;
    int j;
    igl::CANONICAL_VIEW_QUAT(i, j);
    return std::make_tuple(    npe::move(i),
    npe::move(j));
} else if (dtype.type() == npe::type_f64) {
    int i;
    int j;
    igl::CANONICAL_VIEW_QUAT(i, j);
    return std::make_tuple(    npe::move(i),     npe::move(j));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/CANONICAL_VIEW_QUAT.h>

const char* ds_canonical_view_quat = R"igl_Qu8mg5v7(
See CANONICAL_VIEW_QUAT for the documentation.
)igl_Qu8mg5v7";

npe_function(canonical_view_quat)
npe_doc(ds_canonical_view_quat)

npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    int i;
    int j;
    igl::CANONICAL_VIEW_QUAT(i, j);
    return std::make_tuple(    npe::move(i),
    npe::move(j));
} else if (dtype.type() == npe::type_f64) {
    int i;
    int j;
    igl::CANONICAL_VIEW_QUAT(i, j);
    return std::make_tuple(    npe::move(i),     npe::move(j));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


