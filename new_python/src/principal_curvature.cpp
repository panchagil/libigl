#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <igl/principal_curvature.h>


npe_function(principal_curvature)
npe_arg(v, dense_f64, dense_f32)
npe_arg(f, dense_i32)
npe_default_arg(radius, int, 5)
npe_default_arg(useKring, bool, true)


npe_begin_code()
using namespace std;

npe_Matrix_v pd1;
npe_Matrix_v pd2;
npe_Matrix_v pv1;
npe_Matrix_v pv2;

igl::principal_curvature(v, f, pd1, pd2, pv1, pv2, radius, useKring);
return std::make_tuple(npe::move(pd1), npe::move(pd2), npe::move(pv1), npe::move(pv2));

npe_end_code()


