#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/solid_angle.h>

const char* ds_solid_angle = R"igl_Qu8mg5v7(

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

 Compute the signed solid angle subtended by the oriented 3d triangle (A,B,C) at some point P
   
   Inputs:
     A  3D position of corner 
     B  3D position of corner 
     C  3D position of corner 
     P  3D position of query point
   Returns signed solid angle
)igl_Qu8mg5v7";

npe_function(solid_angle)
npe_doc(ds_solid_angle)

npe_arg(a, dense_f64)
npe_arg(b, dense_f64)
npe_arg(c, dense_f64)
npe_arg(p, dense_f64)



npe_begin_code()
using namespace std;



igl::solid_angle(a, b, c, p);

return

npe_end_code()


