//#include <tuple>
//#include <Eigen/Core>
//#include <Eigen/Sparse>
#include <npe.h>
//#include <pybind11/pybind11.h>
#include <igl/jet.h>


npe_function(jet)
npe_arg(z, dense_f64, dense_f32)
npe_arg(normalize, bool)

npe_begin_code()
using namespace std;

Eigen::Matrix<std::double_t, Eigen::Dynamic, Eigen::Dynamic> c;
igl::jet(z, normalize, c);
return npe::move(c);

npe_end_code()



