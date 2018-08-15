#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <igl/writeOBJ.h>

npe_function(write_obj)
npe_arg(str, std::string)
npe_arg(v, dense_f64, dense_f32)
npe_arg(f, dense_i64, dense_i32)
npe_begin_code()

using namespace std;

bool ret = igl::writeOBJ(str, v, f);

return ret;

npe_end_code()
