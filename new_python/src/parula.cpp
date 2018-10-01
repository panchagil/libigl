//#include <tuple>
//#include <Eigen/Core>
//#include <Eigen/Sparse>
#include <npe.h>
//#include <pybind11/pybind11.h>
#include <igl/parula.h>


npe_function(parula)
npe_arg(z, dense_f64, dense_f32)
npe_arg(normalize, bool)

npe_begin_code()
using namespace std;

npe_Matrix_z c;
igl::parula(z, normalize, c);
return npe::move(c);

npe_end_code()



