#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe_utils.h>
#include <typedefs.h>

#include <igl/massmatrix.h>


npe_function(massmatrix)
npe_arg(v, dense_f64) // TODO adding dense_f32 gives an error here, see https://stackoverflow.com/questions/23946658/error-mixing-types-with-eigen-matrices
npe_arg(f, dense_i32)
npe_default_arg(type, int, 0) //TODO"const igl::MassMatrixType"

npe_begin_code()
using namespace std;

Sparse_f64 m;
igl::massmatrix(v, f, igl::MassMatrixType(type), m);
return npe::move(m);

npe_end_code()


