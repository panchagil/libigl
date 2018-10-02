// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/is_writable.h>

const char* ds_is_writable = R"igl_Qu8mg5v7(

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

 Check if a file exists *and* is writable like PHP's is_writable function:
   http:www.php.net/manual/en/function.is-writable.php
   Input:
     filename  path to file
   Returns true if file exists and is writable and false if file doesn't
   exist or *is not writable*
  
   Note: Windows version will not test group and user id
)igl_Qu8mg5v7";

npe_function(is_writable)
npe_doc(ds_is_writable)

npe_arg(filename, char *)



npe_begin_code()
using namespace std;



igl::is_writable(filename);

return

npe_end_code()


