// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/any_of.h>

const char* ds_any_of = R"igl_Qu8mg5v7(

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

 Wrapper for STL `any_of` for matrix types
  
   Inputs:
     S  matrix
   Returns whether any entries are true
  
   Seems that Eigen (now) implements this for `Eigen::Array` 
)igl_Qu8mg5v7";

npe_function(any_of)
npe_doc(ds_any_of)

npe_arg(s, Mat &)



npe_begin_code()
using namespace std;



igl::any_of(s);

return

npe_end_code()


