// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/dot.h>

const char* ds_dot = R"igl_Qu8mg5v7(

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

 Computes out = dot(a,b)
   Inputs:
     a  left 3d vector
     b  right 3d vector
   Returns scalar dot product
)igl_Qu8mg5v7";

npe_function(dot)
npe_doc(ds_dot)

npe_arg(a, double *)
npe_arg(b, double *)



npe_begin_code()
using namespace std;



igl::dot(a, b);

return

npe_end_code()


