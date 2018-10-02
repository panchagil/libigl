// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/group_sum_matrix.h>

const char* ds_group_sum_matrix = R"igl_Qu8mg5v7(

Parameters
----------

dtype : data-type of the returned objects, optional. Default is `float64`.
(All integer return types are `int32` by default.)

Returns
-------


See also
--------


Notes
-----
None

Examples
--------

 GROUP_SUM_MATRIX Builds a matrix A such that A*V computes the sum of
   vertices in each group specified by G
  
   group_sum_matrix(G,k,A);
   
   Templates:
     T  should be a eigen sparse matrix primitive type like int or double
   Inputs:
     G  #V list of group indices (0 to k-1) for each vertex, such that vertex i 
       is assigned to group G(i)
     k  #groups, good choice is max(G)+1
   Outputs:
     A  #groups by #V sparse matrix such that A*V = group_sums
  
)igl_Qu8mg5v7";

npe_function(group_sum_matrix)
npe_doc(ds_group_sum_matrix)

npe_arg(g, Eigen::Matrix<int, Eigen::Dynamic, 1> &)
npe_arg(k, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Sparse_f32 a;
    igl::group_sum_matrix(g, k, a);
    return npe::move(a);
} else if (dtype.type() == npe::type_f64) {
    Sparse_f64 a;
    igl::group_sum_matrix(g, k, a);
    return npe::move(a);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/group_sum_matrix.h>

const char* ds_group_sum_matrix = R"igl_Qu8mg5v7(

Parameters
----------

dtype : data-type of the returned objects, optional. Default is `float64`.
(All integer return types are `int32` by default.)

Returns
-------


See also
--------


Notes
-----
None

Examples
--------

 Wrapper with k = max(G)+1
)igl_Qu8mg5v7";

npe_function(group_sum_matrix)
npe_doc(ds_group_sum_matrix)

npe_arg(g, Eigen::Matrix<int, Eigen::Dynamic, 1> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Sparse_f32 a;
    igl::group_sum_matrix(g, a);
    return npe::move(a);
} else if (dtype.type() == npe::type_f64) {
    Sparse_f64 a;
    igl::group_sum_matrix(g, a);
    return npe::move(a);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


