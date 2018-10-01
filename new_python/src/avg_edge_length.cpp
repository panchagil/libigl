#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>

#include <igl/avg_edge_length.h>


npe_function(avg_edge_length)
npe_arg(v, dense_f64, dense_f32)
npe_arg(f, dense_i32)
npe_begin_code()
using namespace std;

return igl::avg_edge_length(v, f);


npe_end_code()


