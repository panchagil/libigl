// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/is_dir.h>

const char* ds_is_dir = R"igl_Qu8mg5v7(

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

 Act like php's is_dir function
   http:php.net/manual/en/function.is-dir.php
   Tells whether the given filename is a directory.
   Input:
     filename  Path to the file. If filename is a relative filename, it will
       be checked relative to the current working directory. 
   Returns TRUE if the filename exists and is a directory, FALSE
   otherwise.
)igl_Qu8mg5v7";

npe_function(is_dir)
npe_doc(ds_is_dir)

npe_arg(filename, char *)



npe_begin_code()
using namespace std;



igl::is_dir(filename);

return

npe_end_code()


