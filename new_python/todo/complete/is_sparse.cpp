#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/is_sparse.h>

const char* ds_is_sparse = R"igl_Qu8mg5v7(

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

 Determine if a matrix A is sparse
  
   Template:
     T,DerivedA defines scalar type
   Inputs:
     A  matrix in question
   Returns true if A is represented with a sparse matrix
)igl_Qu8mg5v7";

npe_function(is_sparse)
npe_doc(ds_is_sparse)

npe_arg(a, Sparse_f64)



npe_begin_code()
using namespace std;



igl::is_sparse(a);

return

npe_end_code()
#include <igl/is_sparse.h>

const char* ds_is_sparse = R"igl_Qu8mg5v7(
See is_sparse for the documentation.
)igl_Qu8mg5v7";

npe_function(is_sparse)
npe_doc(ds_is_sparse)

npe_arg(a, dense_f64)



npe_begin_code()
using namespace std;



igl::is_sparse(a);

return

npe_end_code()


