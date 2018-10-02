// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/print_ijv.h>

const char* ds_print_ijv = R"igl_Qu8mg5v7(

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

 Prints a 3 column matrix representing [I,J,V] = find(X). That is, each
   row is the row index, column index and value for each non zero entry. Each
   row is printed on a new line
  
   Templates:
     T  should be a eigen sparse matrix primitive type like int or double
   Input:
     X  m by n matrix whose entries are to be sorted
     offset  optional offset for I and J indices {0}
)igl_Qu8mg5v7";

npe_function(print_ijv)
npe_doc(ds_print_ijv)

npe_arg(x, Sparse_f64)
npe_arg(offset, int)



npe_begin_code()
using namespace std;



igl::print_ijv(x, offset);

return

npe_end_code()


