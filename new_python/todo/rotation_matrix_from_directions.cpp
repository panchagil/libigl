// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/rotation_matrix_from_directions.h>

const char* ds_rotation_matrix_from_directions = R"igl_Qu8mg5v7(

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

 Given 2 vectors centered on origin calculate the rotation matrix from
   first to the second
  
   Inputs:
     v0  3D column vector
     v1  3D column vector
   Output:
     3 by 3 rotation matrix that takes v0 to v1
  
)igl_Qu8mg5v7";

npe_function(rotation_matrix_from_directions)
npe_doc(ds_rotation_matrix_from_directions)

npe_arg(v0, Eigen::Matrix<Scalar, 3, 1>)
npe_arg(v1, Eigen::Matrix<Scalar, 3, 1>)



npe_begin_code()
using namespace std;



igl::rotation_matrix_from_directions(v0, v1);

return

npe_end_code()


