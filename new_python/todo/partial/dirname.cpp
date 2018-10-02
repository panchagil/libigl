// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/dirname.h>

const char* ds_dirname = R"igl_Qu8mg5v7(

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

 Function like PHP's dirname: /etc/passwd --> /etc, 
   Input:
    path  string containing input path
   Returns string containing dirname (see php's dirname)
  
   See also: basename, pathinfo
)igl_Qu8mg5v7";

npe_function(dirname)
npe_doc(ds_dirname)

npe_arg(path, std::string &)



npe_begin_code()
using namespace std;



igl::dirname(path);

return

npe_end_code()


