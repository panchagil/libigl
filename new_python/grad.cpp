#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <numpyeigen_utils.h>
#include <igl/grad.h>

npe_function("grad")
npe_arg("v", "type_f64", "type_f32")
npe_arg("f", "type_i64", "type_i32")
npe_begin_code()

using namespace std;

npe::Map_v V((npe::Scalar_v*)v.data(), v.shape()[0], v.shape()[1]);
npe::Map_f F((npe::Scalar_f*)f.data(), f.shape()[0], f.shape()[1]);

Eigen::SparseMatrix<npe::Scalar_v> G;
igl::grad(V, F, G);

return NPE_MOVE_SPARSE(G);

npe_end_code()


