// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/point_in_circle.h>

const char* ds_point_in_circle = R"igl_Qu8mg5v7(

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

 Determine if 2d point is in a circle
   Inputs:
     qx  x-coordinate of query point
     qy  y-coordinate of query point
     cx  x-coordinate of circle center
     cy  y-coordinate of circle center
     r  radius of circle
   Returns true if query point is in circle, false otherwise
)igl_Qu8mg5v7";

npe_function(point_in_circle)
npe_doc(ds_point_in_circle)

npe_arg(qx, double)
npe_arg(qy, double)
npe_arg(cx, double)
npe_arg(cy, double)
npe_arg(r, double)



npe_begin_code()
using namespace std;



igl::point_in_circle(qx, qy, cx, cy, r);

return

npe_end_code()


