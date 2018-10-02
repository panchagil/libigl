// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/slice_into.h>

const char* ds_slice_into = R"igl_Qu8mg5v7(

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

 Act like the matlab Y(row_indices,col_indices) = X
   
   Inputs:
     X  xm by xn rhs matrix
     R  list of row indices
     C  list of column indices
     Y  ym by yn lhs matrix
   Output:
     Y  ym by yn lhs matrix, same as input but Y(R,C) = X
)igl_Qu8mg5v7";

npe_function(slice_into)
npe_doc(ds_slice_into)

npe_arg(x, Sparse_f64)
npe_arg(r, Eigen::Matrix<int, Eigen::Dynamic, 1> &)
npe_arg(c, Eigen::Matrix<int, Eigen::Dynamic, 1> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Sparse_f32 y;
    igl::slice_into(x, r, c, y);
    return npe::move(y);
} else if (dtype.type() == npe::type_f64) {
    Sparse_f64 y;
    igl::slice_into(x, r, c, y);
    return npe::move(y);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/slice_into.h>

const char* ds_slice_into = R"igl_Qu8mg5v7(
See slice_into for the documentation.
)igl_Qu8mg5v7";

npe_function(slice_into)
npe_doc(ds_slice_into)

npe_arg(x, Eigen::DenseBase<DerivedX> &)
npe_arg(r, Eigen::Matrix<int, Eigen::Dynamic, 1> &)
npe_arg(c, Eigen::Matrix<int, Eigen::Dynamic, 1> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 y;
    igl::slice_into(x, r, c, y);
    return npe::move(y);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 y;
    igl::slice_into(x, r, c, y);
    return npe::move(y);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/slice_into.h>

const char* ds_slice_into = R"igl_Qu8mg5v7(

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

 Wrapper to only slice in one direction
  
   Inputs:
     dim  dimension to slice in 1 or 2, dim=1 --> X(R,:), dim=2 --> X(:,R)
  
   Note: For now this is just a cheap wrapper.
)igl_Qu8mg5v7";

npe_function(slice_into)
npe_doc(ds_slice_into)

npe_arg(x, MatX &)
npe_arg(r, Eigen::Matrix<int, Eigen::Dynamic, 1> &)
npe_arg(dim, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::SparseMatrix<double>& y;
    igl::slice_into(x, r, dim, y);
    return npe::move(y);
} else if (dtype.type() == npe::type_f64) {
    Eigen::SparseMatrix<double>& y;
    igl::slice_into(x, r, dim, y);
    return npe::move(y);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/slice_into.h>

const char* ds_slice_into = R"igl_Qu8mg5v7(
See slice_into for the documentation.
)igl_Qu8mg5v7";

npe_function(slice_into)
npe_doc(ds_slice_into)

npe_arg(x, Eigen::DenseBase<DerivedX> &)
npe_arg(r, Eigen::Matrix<int, Eigen::Dynamic, 1> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 y;
    igl::slice_into(x, r, y);
    return npe::move(y);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 y;
    igl::slice_into(x, r, y);
    return npe::move(y);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


