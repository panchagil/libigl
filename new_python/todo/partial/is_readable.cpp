// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/is_readable.h>

const char* ds_is_readable = R"igl_Qu8mg5v7(

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

 Check if a file is reabable like PHP's is_readable function:
   http:www.php.net/manual/en/function.is-readable.php
   Input:
     filename  path to file
   Returns true if file exists and is readable and false if file doesn't
   exist or *is not readable*
  
   Note: Windows version will not check user or group ids
)igl_Qu8mg5v7";

npe_function(is_readable)
npe_doc(ds_is_readable)

npe_arg(filename, char *)



npe_begin_code()
using namespace std;



igl::is_readable(filename);

return

npe_end_code()


