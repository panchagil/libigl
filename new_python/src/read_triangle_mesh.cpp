#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <igl/read_triangle_mesh.h>

npe_function(read_triangle_mesh)
npe_arg(str, std::string)

npe_begin_code()
using namespace std;

Eigen::Matrix<std::double_t, Eigen::Dynamic, Eigen::Dynamic> v;
Eigen::Matrix<std::int32_t, Eigen::Dynamic, Eigen::Dynamic> f;

igl::read_triangle_mesh(str, v, f);
return std::make_tuple(npe::move(v), npe::move(f));

npe_end_code()

