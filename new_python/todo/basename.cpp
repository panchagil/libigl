// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/basename.h>

const char* ds_basename = R"igl_Qu8mg5v7(

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

 Function like PHP's basename: /etc/sudoers.d --> sudoers.d
   Input:
    path  string containing input path
   Returns string containing basename (see php's basename)
  
   See also: dirname, pathinfo
)igl_Qu8mg5v7";

npe_function(basename)
npe_doc(ds_basename)

npe_arg(path, std::string &)



npe_begin_code()
using namespace std;



igl::basename(path);

return

npe_end_code()


