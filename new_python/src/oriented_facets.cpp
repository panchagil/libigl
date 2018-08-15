#include <Eigen/Core>
#include <npe.h>
#include <igl/oriented_facets.h>
#include <pybind11/pybind11.h>
#include <exception>

npe_function(oriented_facets)
npe_arg(f, dense_i32, dense_i64)
npe_default_arg(dtype, pybind11::object, pybind11::dtype("int32"))
npe_begin_code()

switch(pybind11::dtype::from_args(dtype).type()) {
  case npe::detail::NumpyTypeChar::char_i32:
  {
    Eigen::Matrix<std::int32_t, Eigen::Dynamic, Eigen::Dynamic> E;
    igl::oriented_facets(f, E);
    return NPE_MOVE_DENSE(E);
  }
  case npe::detail::NumpyTypeChar::char_i64:
  {
    Eigen::Matrix<std::int64_t, Eigen::Dynamic, Eigen::Dynamic> E;
    igl::oriented_facets(f, E);
    return NPE_MOVE_DENSE(E);
  }
  default:
    throw std::runtime_error("Bad dtype. Only int32 and int64 are supported.");
}

npe_end_code()
