#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/read_triangle_mesh.h>

npe_function(read_triangle_mesh)
npe_arg(str, std::string)

npe_begin_code()
using namespace std;

Dense_f64 v;
Dense_i32 f;

igl::read_triangle_mesh(str, v, f);
return std::make_tuple(npe::move(v), npe::move(f));

npe_end_code()

