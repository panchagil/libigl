#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <igl/grad.h>

npe_function(grad)
npe_arg(v, dense_f64, dense_f32)
npe_arg(f, dense_i64, dense_i32)
npe_default_arg(uniform, bool, false)
npe_begin_code()
using namespace std;

Eigen::SparseMatrix<npe_Scalar_v> G;
igl::grad(v, f, g, uniform);

return NPE_MOVE_SPARSE(g);

npe_end_code()


