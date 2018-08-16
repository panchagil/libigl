#include <npe.h>
#include <igl/edges.h>
#include <exception>

npe_function(edges)
npe_arg(f, dense_i32, dense_i64)
npe_default_arg(dtype, pybind11::object, pybind11::none())
npe_begin_code()

typedef npe::detail::NumpyTypeChar TypeChar;
TypeChar out_typechar;
if (dtype.is_none()) {
  out_typechar = TypeChar(pybind11::dtype::of<npe_Scalar_f>().type());
} else {
  out_typechar = TypeChar(pybind11::dtype::from_args(dtype).type());
}

switch(out_typechar) {
  case npe::detail::NumpyTypeChar::char_i32:
  {
    Eigen::Matrix<std::int32_t, Eigen::Dynamic, Eigen::Dynamic> E;
    igl::edges(f, E);
    return NPE_MOVE_DENSE(E);
  }
  case npe::detail::NumpyTypeChar::char_i64:
  {
    Eigen::Matrix<std::int64_t, Eigen::Dynamic, Eigen::Dynamic> E;
    igl::edges(f, E);
    return NPE_MOVE_DENSE(E);
  }
  default:
    throw std::runtime_error("Bad dtype. Only int32 and int64 are supported.");
}

npe_end_code()
