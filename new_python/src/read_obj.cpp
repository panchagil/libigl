#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <igl/readOBJ.h>

npe_function(read_obj)
npe_arg(str, std::string)
//npe_default_arg(read_normals, bool, true)
npe_doc("A function which computes \n various values from input matrices")
npe_begin_code()
using namespace std;

Eigen::Matrix<std::double_t, Eigen::Dynamic, Eigen::Dynamic> v;
Eigen::Matrix<std::int32_t, Eigen::Dynamic, Eigen::Dynamic> f;
Eigen::Matrix<std::double_t, Eigen::Dynamic, Eigen::Dynamic> n;
Eigen::Matrix<std::double_t, Eigen::Dynamic, Eigen::Dynamic> tc;
Eigen::Matrix<std::int32_t, Eigen::Dynamic, Eigen::Dynamic> ftc;
Eigen::Matrix<std::int32_t, Eigen::Dynamic, Eigen::Dynamic> fn;
bool ret;


//if (read_normals) {
//    ret = igl::readOBJ(str, v, f, n);
//}
//else {
ret = igl::readOBJ(str, v, tc, n, f, ftc, fn);
//}
if (!ret) {
    throw std::invalid_argument("File '" + str + "' not found.");
}
return std::make_tuple(npe::move(v), npe::move(f), npe::move(n));

npe_end_code()
