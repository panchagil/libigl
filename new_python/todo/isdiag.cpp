#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/isdiag.h>

const char* ds_isdiag = R"igl_Qu8mg5v7(

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

 Determine if a given matrix is diagonal: all non-zeros lie on the
   main diagonal.
  
   Inputs:
     A  m by n sparse matrix
   Returns true iff and only if the matrix is diagonal.
)igl_Qu8mg5v7";

npe_function(isdiag)
npe_doc(ds_isdiag)

npe_arg(a, Sparse_f64)



npe_begin_code()
using namespace std;



igl::isdiag(a);

return

npe_end_code()


