#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>

#include <igl/cotmatrix.h>


npe_function(cotmatrix)
npe_arg(v, dense_f64, dense_f32)
npe_arg(f, dense_i32)
npe_begin_code()
using namespace std;

Sparse_f64 l;
igl::cotmatrix(v, f, l);
return npe::move(l);

npe_end_code()


