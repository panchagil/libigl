// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/is_file.h>

const char* ds_is_file = R"igl_Qu8mg5v7(

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

 Act like php's is_file function
   http:php.net/manual/en/function.is-file.php
   Tells whether the given filename is a regular file.
   Input:
     filename  Path to the file. If filename is a relative filename, it will
       be checked relative to the current working directory. 
   Returns TRUE if the filename exists and is a regular file, FALSE
   otherwise.
)igl_Qu8mg5v7";

npe_function(is_file)
npe_doc(ds_is_file)

npe_arg(filename, char *)



npe_begin_code()
using namespace std;



igl::is_file(filename);

return

npe_end_code()


