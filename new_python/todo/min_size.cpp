// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/min_size.h>

const char* ds_min_size = R"igl_Qu8mg5v7(

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

 Determine min size of lists in a vector
   Template:
     T  some list type object that implements .size()
   Inputs:
     V  vector of list types T
   Returns min .size() found in V, returns -1 if V is empty
)igl_Qu8mg5v7";

npe_function(min_size)
npe_doc(ds_min_size)

npe_arg(v, std::vector<T> &)



npe_begin_code()
using namespace std;



igl::min_size(v);

return

npe_end_code()


