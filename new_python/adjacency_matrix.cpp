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
npe_arg("dtype", "pybind11::object")
npe_begin_code()

npe::Map_f F((npe::Scalar_f*)f.data(), f.shape()[0], f.shape()[1]);

switch(pybind11::dtype::from_args(dtype).type()) {
  case numpyeigen::detail::NumpyTypeChar::char_f32:
  {
    Eigen::SparseMatrix<float> A;
    igl::adjacency_matrix(F, A);
    return NPE_MOVE_SPARSE(A);
  }
  case numpyeigen::detail::NumpyTypeChar::char_f64:
  {
    Eigen::SparseMatrix<double> A;
    igl::adjacency_matrix(F, A);
    return NPE_MOVE_SPARSE(A);
  }
  default:
    throw std::runtime_error("Bad dtype. Only float32 and float64 are supported.");
}

npe_end_code()
