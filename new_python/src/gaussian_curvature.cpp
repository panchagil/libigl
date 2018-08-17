//#include <tuple>
#include <Eigen/Core>
//#include <Eigen/Sparse>
#include <npe.h>
#include <pybind11/pybind11.h>

#include <igl/gaussian_curvature.h>


npe_function(gaussian_curvature)
npe_arg(v, dense_f64, dense_f32)
npe_arg(f, dense_i64, dense_i32)

npe_begin_code()
using namespace std;

Eigen::Matrix<std::double_t, Eigen::Dynamic, Eigen::Dynamic> k;
igl::gaussian_curvature(v, f, k);
return NPE_MOVE_DENSE(k);

npe_end_code()


