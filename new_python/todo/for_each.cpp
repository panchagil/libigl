// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/for_each.h>

const char* ds_for_each = R"igl_Qu8mg5v7(

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

 FOR_EACH  Call a given function for each non-zero (i.e., explicit value
   might actually be ==0) in a Sparse Matrix A _in order (of storage)_. This is
   useless unless func has _side-effects_.
  
   Inputs:
     A  m by n SparseMatrix
     func  function handle with prototype "compatible with" `void (Index i,
       Index j, Scalar & v)`. Return values will be ignored.
  
   See also: std::for_each
)igl_Qu8mg5v7";

npe_function(for_each)
npe_doc(ds_for_each)

npe_arg(a, Eigen::SparseMatrix<AType> &)
npe_arg(func, Func &)



npe_begin_code()
using namespace std;



igl::for_each(a, func);

return

npe_end_code()
#include <igl/for_each.h>

const char* ds_for_each = R"igl_Qu8mg5v7(
See for_each for the documentation.
)igl_Qu8mg5v7";

npe_function(for_each)
npe_doc(ds_for_each)

npe_arg(a, Eigen::DenseBase<DerivedA> &)
npe_arg(func, Func &)



npe_begin_code()
using namespace std;



igl::for_each(a, func);

return

npe_end_code()
#include <igl/for_each.h>

const char* ds_for_each = R"igl_Qu8mg5v7(

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

 FOR_EACH  Call a given function for each non-zero (i.e., explicit value
   might actually be ==0) in a Sparse Matrix A _in order (of storage)_. This is
   useless unless func has _side-effects_.
  
   Inputs:
     A  m by n SparseMatrix
     func  function handle with prototype "compatible with" `void (Index i,
       Index j, Scalar & v)`. Return values will be ignored.
  
   See also: std::for_each
)igl_Qu8mg5v7";

npe_function(for_each)
npe_doc(ds_for_each)

npe_arg(a, Eigen::SparseMatrix<AType> &)
npe_arg(func, Func &)



npe_begin_code()
using namespace std;



igl::for_each(a, func);

return

npe_end_code()
#include <igl/for_each.h>

const char* ds_for_each = R"igl_Qu8mg5v7(
See for_each for the documentation.
)igl_Qu8mg5v7";

npe_function(for_each)
npe_doc(ds_for_each)

npe_arg(a, Eigen::DenseBase<DerivedA> &)
npe_arg(func, Func &)



npe_begin_code()
using namespace std;



igl::for_each(a, func);

return

npe_end_code()


