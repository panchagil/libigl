// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/remove_duplicates.h>

const char* ds_remove_duplicates = R"igl_Qu8mg5v7(

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

  template <typename T, typename S>
  IGL_INLINE void remove_duplicates(
                                   const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> &V,
                                   const Eigen::Matrix<S, Eigen::Dynamic, Eigen::Dynamic> &F,
                                   Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> &NV,
                                   Eigen::Matrix<S, Eigen::Dynamic, Eigen::Dynamic> &NF,
                                   Eigen::Matrix<S, Eigen::Dynamic, 1> &I,
                                   const double epsilon = 2.2204e-15);
)igl_Qu8mg5v7";

npe_function(remove_duplicates)
npe_doc(ds_remove_duplicates)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(epsilon, double)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 nv;
    dense_f32 nf;
    Eigen::Matrix<typename DerivedF::Scalar, Eigen::Dynamic, 1> & i;
    igl::remove_duplicates(v, f, epsilon, nv, nf, i);
    return std::make_tuple(    npe::move(nv),
    npe::move(nf),
    npe::move(i));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 nv;
    dense_f64 nf;
    Eigen::Matrix<typename DerivedF::Scalar, Eigen::Dynamic, 1> & i;
    igl::remove_duplicates(v, f, epsilon, nv, nf, i);
    return std::make_tuple(    npe::move(nv),     npe::move(nf),     npe::move(i));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


