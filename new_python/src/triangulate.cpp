// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <pybind11/pybind11.h>

#include <igl/triangle/triangulate.h>


npe_function(triangulate)
npe_arg(v, dense_f64, dense_f32)
npe_arg(e, dense_i32)
npe_arg(h, dense_f64, dense_f32)
npe_default_arg(flags, std::string, "a0.005q")

npe_begin_code()
using namespace std;

Eigen::Matrix<std::double_t, Eigen::Dynamic, Eigen::Dynamic> v2;
Eigen::Matrix<std::int32_t, Eigen::Dynamic, Eigen::Dynamic> f2;

igl::triangle::triangulate(v, e, h, flags, v2, f2);

return std::make_tuple(npe::move(v2), npe::move(f2));

npe_end_code()



