#include <Eigen/Core>
#include <Eigen/Sparse>
#include <numpyeigen_utils.h>
#include <numpyeigen_typedefs.h>
#include <igl/adjacency_matrix.h>
#include <pybind11/pybind11.h>
#include <iostream>
#include <exception>

npe_function("adjacency_matrix")
npe_arg("f", "type_i32", "type_i64")
npe_default_arg("dtype", "pybind11::object", "pybind11::none()")
npe_begin_code()

npe::Map_f F((npe::Scalar_f*)f.data(), f.shape()[0], f.shape()[1]);

typedef numpyeigen::detail::NumpyTypeChar TypeChar;
TypeChar out_typechar;
if (dtype.is_none()) {
  out_typechar = TypeChar(pybind11::dtype::of<npe::Scalar_f>().type());
} else {
  out_typechar = TypeChar(pybind11::dtype::from_args(dtype).type());
}

switch(out_typechar) {
  case numpyeigen::detail::NumpyTypeChar::char_f32:
  {
    Eigen::SparseMatrix<std::int32_t> A;
    igl::adjacency_matrix(F, A);
    return NPE_MOVE_SPARSE(A);
  }
  case numpyeigen::detail::NumpyTypeChar::char_f64:
  {
    Eigen::SparseMatrix<std::int64_t> A;
    igl::adjacency_matrix(F, A);
    return NPE_MOVE_SPARSE(A);
  }
  default:
    throw std::runtime_error("Bad dtype. Only float32 and float64 are supported.");
}

npe_end_code()
