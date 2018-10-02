// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/file_exists.h>

const char* ds_file_exists = R"igl_Qu8mg5v7(

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

 Check if a file or directory exists like PHP's file_exists function:
   http:php.net/manual/en/function.file-exists.php
   Input:
     filename  path to file
   Returns true if file exists and is readable and false if file doesn't
   exist or *is not readable*
)igl_Qu8mg5v7";

npe_function(file_exists)
npe_doc(ds_file_exists)

npe_arg(filename, std::string)



npe_begin_code()
using namespace std;



igl::file_exists(filename);

return

npe_end_code()


