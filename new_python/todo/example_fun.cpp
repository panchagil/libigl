// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/example_fun.h>

const char* ds_example_fun = R"igl_Qu8mg5v7(

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

 This is an example of a function, it takes a templated parameter and
   shovels it into cout
  
   Templates:
     T  type that supports
   Input:
     input  some input of a Printable type
   Returns true for the sake of returning something
)igl_Qu8mg5v7";

npe_function(example_fun)
npe_doc(ds_example_fun)

npe_arg(input, Printable &)



npe_begin_code()
using namespace std;



igl::example_fun(input);

return

npe_end_code()


