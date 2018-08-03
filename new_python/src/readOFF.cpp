#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <numpyeigen_utils.h>
#include <igl/readOFF.h>

npe_function("read_off")
npe_arg("str", "std::string")
npe_begin_code()

using namespace std;


Eigen::Matrix<std::double_t, Eigen::Dynamic, Eigen::Dynamic> V;
Eigen::Matrix<std::int32_t, Eigen::Dynamic, Eigen::Dynamic> F;

bool ret = igl::readOFF(str, V, F);
if (!ret) {
    throw std::invalid_argument("File '" + str + "' not found.");
}
return std::make_tuple(NPE_MOVE_DENSE(V), NPE_MOVE_DENSE(F));

npe_end_code()
