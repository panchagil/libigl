#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <igl/readOFF.h>

npe_function(readOFF)
npe_arg(str, std::string)
npe_default_arg(read_normals, bool, true)
npe_doc("A function which computes \n various values from input matrices")
npe_begin_code()
using namespace std;

Eigen::Matrix<std::double_t, Eigen::Dynamic, Eigen::Dynamic> v;
Eigen::Matrix<std::int32_t, Eigen::Dynamic, Eigen::Dynamic> f;
Eigen::Matrix<std::double_t, Eigen::Dynamic, Eigen::Dynamic> n;
bool ret;


if (read_normals) {
    ret = igl::readOFF(str, v, f, n);
}
else {
    ret = igl::readOFF(str, v, f);
}
if (!ret) {
    throw std::invalid_argument("File '" + str + "' not found.");
}
return std::make_tuple(npe::move(v), npe::move(f), npe::move(n));

npe_end_code()
