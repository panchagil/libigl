// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/is_symmetric.h>

const char* ds_is_symmetric = R"igl_Qu8mg5v7(
See is_symmetric for the documentation.
)igl_Qu8mg5v7";

npe_function(is_symmetric)
npe_doc(ds_is_symmetric)

npe_arg(a, dense_f64)



npe_begin_code()
using namespace std;



igl::is_symmetric(a);

return

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/is_symmetric.h>

const char* ds_is_symmetric = R"igl_Qu8mg5v7(

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

 Returns true if the given matrix is symmetric
   Inputs:
     A  m by m matrix
   Returns true if the matrix is square and symmetric
)igl_Qu8mg5v7";

npe_function(is_symmetric)
npe_doc(ds_is_symmetric)

npe_arg(a, Eigen::SparseMatrix<AT> &)



npe_begin_code()
using namespace std;



igl::is_symmetric(a);

return

npe_end_code()
#include <igl/is_symmetric.h>

const char* ds_is_symmetric = R"igl_Qu8mg5v7(

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

 Inputs:
     epsilon threshold on L1 difference between A and A'
)igl_Qu8mg5v7";

npe_function(is_symmetric)
npe_doc(ds_is_symmetric)

npe_arg(a, Eigen::SparseMatrix<AT> &)
npe_arg(epsilon, epsilonT)



npe_begin_code()
using namespace std;



igl::is_symmetric(a, epsilon);

return

npe_end_code()


