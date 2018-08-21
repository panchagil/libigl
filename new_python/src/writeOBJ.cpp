#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <igl/writeOBJ.h>


npe_function(writeOBJ)
npe_arg(str, std::string)
npe_default_arg(v, dense_f64, dense_f32, pybind11::array_t<double>())
npe_default_arg(f, dense_i64, dense_i32, pybind11::array_t<int>())

npe_begin_code()
using namespace std;

bool ret = igl::writeOBJ(str, v, f);

return ret;

npe_end_code()
