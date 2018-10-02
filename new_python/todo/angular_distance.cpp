// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/angular_distance.h>

const char* ds_angular_distance = R"igl_Qu8mg5v7(

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

 The "angular distance" between two unit quaternions is the angle of the
   smallest rotation (treated as an Axis and Angle) that takes A to B.
  
   Inputs:
     A  unit quaternion
     B  unit quaternion
   Returns angular distance
)igl_Qu8mg5v7";

npe_function(angular_distance)
npe_doc(ds_angular_distance)

npe_arg(a, Eigen::Quaterniond &)
npe_arg(b, Eigen::Quaterniond &)



npe_begin_code()
using namespace std;



igl::angular_distance(a, b);

return

npe_end_code()


