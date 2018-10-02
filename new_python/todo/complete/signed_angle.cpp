#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/signed_angle.h>

const char* ds_signed_angle = R"igl_Qu8mg5v7(

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

 Compute the signed angle subtended by the oriented 3d triangle (A,B,C) at some point P
   
   Inputs:
     A  2D position of corner 
     B  2D position of corner 
     P  2D position of query point
     returns signed angle
)igl_Qu8mg5v7";

npe_function(signed_angle)
npe_doc(ds_signed_angle)

npe_arg(a, dense_f64)
npe_arg(b, dense_f64)
npe_arg(p, dense_f64)



npe_begin_code()
using namespace std;



igl::signed_angle(a, b, p);

return

npe_end_code()


