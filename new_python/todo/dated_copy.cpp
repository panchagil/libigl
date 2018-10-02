// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/dated_copy.h>

const char* ds_dated_copy = R"igl_Qu8mg5v7(

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

 Copy the given file to a new file with the same basename in `dir`
   directory with the current date and time as a suffix.
  
   Inputs:
     src_path  path to source file
     dir  directory of destination file
   Example:
     dated_copy("/path/to/foo","/bar/");
      copies /path/to/foo to /bar/foo-2013-12-12T18-10-56
)igl_Qu8mg5v7";

npe_function(dated_copy)
npe_doc(ds_dated_copy)

npe_arg(src_path, std::string &)
npe_arg(dir, std::string &)



npe_begin_code()
using namespace std;



igl::dated_copy(src_path, dir);

return

npe_end_code()
#include <igl/dated_copy.h>

const char* ds_dated_copy = R"igl_Qu8mg5v7(

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

 Wrapper using directory of source file
)igl_Qu8mg5v7";

npe_function(dated_copy)
npe_doc(ds_dated_copy)

npe_arg(src_path, std::string &)



npe_begin_code()
using namespace std;



igl::dated_copy(src_path);

return

npe_end_code()


