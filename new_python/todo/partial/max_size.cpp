// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/max_size.h>

const char* ds_max_size = R"igl_Qu8mg5v7(

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

 Determine max size of lists in a vector
   Template:
     T  some list type object that implements .size()
   Inputs:
     V  vector of list types T
   Returns max .size() found in V, returns -1 if V is empty
)igl_Qu8mg5v7";

npe_function(max_size)
npe_doc(ds_max_size)

npe_arg(v, std::vector<T> &)



npe_begin_code()
using namespace std;



igl::max_size(v);

return

npe_end_code()


