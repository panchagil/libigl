// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/slice_mask.h>

const char* ds_slice_mask = R"igl_Qu8mg5v7(

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

 Act like the matlab X(row_mask,col_mask) operator, where
   row_mask, col_mask are non-negative integer indices.
   
   Inputs:
     X  m by n matrix
     R  m list of row bools
     C  n list of column bools
   Output:
     Y  #trues-in-R by #trues-in-C matrix
  
   See also: slice_mask
)igl_Qu8mg5v7";

npe_function(slice_mask)
npe_doc(ds_slice_mask)

npe_arg(x, Eigen::DenseBase<DerivedX> &)
npe_arg(r, Eigen::Array<bool, Eigen::Dynamic, 1> &)
npe_arg(c, Eigen::Array<bool, Eigen::Dynamic, 1> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 y;
    igl::slice_mask(x, r, c, y);
    return npe::move(y);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 y;
    igl::slice_mask(x, r, c, y);
    return npe::move(y);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/slice_mask.h>

const char* ds_slice_mask = R"igl_Qu8mg5v7(
See slice_mask for the documentation.
)igl_Qu8mg5v7";

npe_function(slice_mask)
npe_doc(ds_slice_mask)

npe_arg(x, Eigen::DenseBase<DerivedX> &)
npe_arg(r, Eigen::Array<bool, Eigen::Dynamic, 1> &)
npe_arg(dim, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 y;
    igl::slice_mask(x, r, dim, y);
    return npe::move(y);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 y;
    igl::slice_mask(x, r, dim, y);
    return npe::move(y);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/slice_mask.h>

const char* ds_slice_mask = R"igl_Qu8mg5v7(

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


   This templating is bad because the return type might not have the same
   size as `DerivedX`. This will probably only work if DerivedX has Dynamic
   as it's non-trivial sizes or if the number of rows in R happens to equal
   the number of rows in `DerivedX`.
)igl_Qu8mg5v7";

npe_function(slice_mask)
npe_doc(ds_slice_mask)

npe_arg(x, Eigen::DenseBase<DerivedX> &)
npe_arg(r, Eigen::Array<bool, Eigen::Dynamic, 1> &)
npe_arg(c, Eigen::Array<bool, Eigen::Dynamic, 1> &)



npe_begin_code()
using namespace std;



igl::slice_mask(x, r, c);

return

npe_end_code()
#include <igl/slice_mask.h>

const char* ds_slice_mask = R"igl_Qu8mg5v7(
See slice_mask for the documentation.
)igl_Qu8mg5v7";

npe_function(slice_mask)
npe_doc(ds_slice_mask)

npe_arg(x, Eigen::DenseBase<DerivedX> &)
npe_arg(r, Eigen::Array<bool, Eigen::Dynamic, 1> &)
npe_arg(dim, int)



npe_begin_code()
using namespace std;



igl::slice_mask(x, r, dim);

return

npe_end_code()
#include <igl/slice_mask.h>

const char* ds_slice_mask = R"igl_Qu8mg5v7(
See slice_mask for the documentation.
)igl_Qu8mg5v7";

npe_function(slice_mask)
npe_doc(ds_slice_mask)

npe_arg(x, Eigen::SparseMatrix<XType> &)
npe_arg(r, Eigen::Array<bool, Eigen::Dynamic, 1> &)
npe_arg(dim, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::SparseMatrix<YType> & y;
    igl::slice_mask(x, r, dim, y);
    return npe::move(y);
} else if (dtype.type() == npe::type_f64) {
    Eigen::SparseMatrix<YType> & y;
    igl::slice_mask(x, r, dim, y);
    return npe::move(y);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/slice_mask.h>

const char* ds_slice_mask = R"igl_Qu8mg5v7(
See slice_mask for the documentation.
)igl_Qu8mg5v7";

npe_function(slice_mask)
npe_doc(ds_slice_mask)

npe_arg(x, Eigen::SparseMatrix<XType> &)
npe_arg(r, Eigen::Array<bool, Eigen::Dynamic, 1> &)
npe_arg(c, Eigen::Array<bool, Eigen::Dynamic, 1> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::SparseMatrix<YType> & y;
    igl::slice_mask(x, r, c, y);
    return npe::move(y);
} else if (dtype.type() == npe::type_f64) {
    Eigen::SparseMatrix<YType> & y;
    igl::slice_mask(x, r, c, y);
    return npe::move(y);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


