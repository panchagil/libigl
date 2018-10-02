// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/slice.h>

const char* ds_slice = R"igl_Qu8mg5v7(

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

 Act like the matlab X(row_indices,col_indices) operator, where
   row_indices, col_indices are non-negative integer indices.
   
   Inputs:
     X  m by n matrix
     R  list of row indices
     C  list of column indices
   Output:
     Y  #R by #C matrix
  
   See also: slice_mask
)igl_Qu8mg5v7";

npe_function(slice)
npe_doc(ds_slice)

npe_arg(x, Eigen::SparseMatrix<TX> &)
npe_arg(r, Eigen::Matrix<int, Eigen::Dynamic, 1> &)
npe_arg(c, Eigen::Matrix<int, Eigen::Dynamic, 1> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::SparseMatrix<TY> & y;
    igl::slice(x, r, c, y);
    return npe::move(y);
} else if (dtype.type() == npe::type_f64) {
    Eigen::SparseMatrix<TY> & y;
    igl::slice(x, r, c, y);
    return npe::move(y);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/slice.h>

const char* ds_slice = R"igl_Qu8mg5v7(

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

npe_function(slice)
npe_doc(ds_slice)

npe_arg(x, MatX &)
npe_arg(r, Eigen::DenseBase<DerivedR> &)
npe_arg(dim, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::SparseMatrix<double>& y;
    igl::slice(x, r, dim, y);
    return npe::move(y);
} else if (dtype.type() == npe::type_f64) {
    Eigen::SparseMatrix<double>& y;
    igl::slice(x, r, dim, y);
    return npe::move(y);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/slice.h>

const char* ds_slice = R"igl_Qu8mg5v7(
See slice for the documentation.
)igl_Qu8mg5v7";

npe_function(slice)
npe_doc(ds_slice)

npe_arg(x, Eigen::DenseBase<DerivedX> &)
npe_arg(r, Eigen::DenseBase<DerivedR> &)
npe_arg(c, Eigen::DenseBase<DerivedC> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 y;
    igl::slice(x, r, c, y);
    return npe::move(y);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 y;
    igl::slice(x, r, c, y);
    return npe::move(y);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/slice.h>

const char* ds_slice = R"igl_Qu8mg5v7(
See slice for the documentation.
)igl_Qu8mg5v7";

npe_function(slice)
npe_doc(ds_slice)

npe_arg(x, Eigen::DenseBase<DerivedX> &)
npe_arg(r, Eigen::Matrix<int, Eigen::Dynamic, 1> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 y;
    igl::slice(x, r, y);
    return npe::move(y);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 y;
    igl::slice(x, r, y);
    return npe::move(y);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/slice.h>

const char* ds_slice = R"igl_Qu8mg5v7(

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

 VectorXi Y = slice(X,R);
  
   This templating is bad because the return type might not have the same
   size as `DerivedX`. This will probably only work if DerivedX has Dynamic
   as it's non-trivial sizes or if the number of rows in R happens to equal
   the number of rows in `DerivedX`.
)igl_Qu8mg5v7";

npe_function(slice)
npe_doc(ds_slice)

npe_arg(x, Eigen::DenseBase<DerivedX> &)
npe_arg(r, Eigen::Matrix<int, Eigen::Dynamic, 1> &)



npe_begin_code()
using namespace std;



igl::slice(x, r);

return

npe_end_code()
#include <igl/slice.h>

const char* ds_slice = R"igl_Qu8mg5v7(
See slice for the documentation.
)igl_Qu8mg5v7";

npe_function(slice)
npe_doc(ds_slice)

npe_arg(x, Eigen::DenseBase<DerivedX> &)
npe_arg(r, Eigen::Matrix<int, Eigen::Dynamic, 1> &)
npe_arg(dim, int)



npe_begin_code()
using namespace std;



igl::slice(x, r, dim);

return

npe_end_code()


