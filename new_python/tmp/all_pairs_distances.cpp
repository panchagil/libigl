#include <Eigen/Core>
#include <Eigen/Sparse>
#include <numpyeigen_utils.h>
#include <numpyeigen_typedefs.h>
#include <igl/all_pairs_distances.h>
#include <pybind11/pybind11.h>
#include <iostream>
#include <exception>

npe_function("all_pairs_distances")
npe_arg("u", "dense_f32", "dense_f64", "dense_c64", "dense_c128", "dense_i32", "dense_i64")
npe_arg("v", "dense_f32", "dense_f64", "dense_c64", "dense_c128", "dense_i32", "dense_i64")
npe_default_arg("squared", "bool", "true")
npe_default_arg("dtype", "pybind11::object", "pybind11::dtype(\"float64\")")

npe_begin_code()

npe::Map_u U((npe::Scalar_u*)u.data(), u.shape()[0], u.shape()[1]);
npe::Map_v V((npe::Scalar_v*)v.data(), v.shape()[0], v.shape()[1]);

typedef numpyeigen::detail::NumpyTypeChar TypeChar;
TypeChar out_typechar = TypeChar(pybind11::dtype::from_args(dtype).type());

switch(out_typechar) {
  case numpyeigen::detail::NumpyTypeChar::char_f32:
  {
    Eigen::Matrix<std::float_t, Eigen::Dynamic, Eigen::Dynamic> D;
    igl::all_pairs_distances(U, V, squared, D);
    return NPE_MOVE_DENSE(D);
  }
  case numpyeigen::detail::NumpyTypeChar::char_f64:
  {
    Eigen::Matrix<std::double_t, Eigen::Dynamic, Eigen::Dynamic> D;
    igl::all_pairs_distances(U, V, squared, D);
    return NPE_MOVE_DENSE(D);
  }
  default:
    throw std::runtime_error("Bad dtype. Only float32, and float64 are supported.");
}

npe_end_code()
