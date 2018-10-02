// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/slice_cached_precompute.h>

const char* ds_slice_cached_precompute = R"igl_Qu8mg5v7(

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

  Fast version
   static VectorXi data;  static or saved in a global state
   if (data.size() == 0)
     igl::slice_cached_precompute(L,in,in,data,L_sliced);
   else
     igl::slice_cached(L,data,L_sliced);
)igl_Qu8mg5v7";

npe_function(slice_cached_precompute)
npe_doc(ds_slice_cached_precompute)

npe_arg(x, Eigen::SparseMatrix<TX> &)
npe_arg(r, Eigen::Matrix<int, Eigen::Dynamic, 1> &)
npe_arg(c, Eigen::Matrix<int, Eigen::Dynamic, 1> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 data;
    Eigen::SparseMatrix<TY> & y;
    igl::slice_cached_precompute(x, r, c, data, y);
    return std::make_tuple(    npe::move(data),
    npe::move(y));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 data;
    Eigen::SparseMatrix<TY> & y;
    igl::slice_cached_precompute(x, r, c, data, y);
    return std::make_tuple(    npe::move(data),     npe::move(y));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/slice_cached.h>

const char* ds_slice_cached = R"igl_Qu8mg5v7(
See slice_cached for the documentation.
)igl_Qu8mg5v7";

npe_function(slice_cached)
npe_doc(ds_slice_cached)

npe_arg(x, Eigen::SparseMatrix<TX> &)
npe_arg(data, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::SparseMatrix<TY> & y;
    igl::slice_cached(x, data, y);
    return npe::move(y);
} else if (dtype.type() == npe::type_f64) {
    Eigen::SparseMatrix<TY> & y;
    igl::slice_cached(x, data, y);
    return npe::move(y);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


