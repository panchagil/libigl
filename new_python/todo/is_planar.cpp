// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/is_planar.h>

const char* ds_is_planar = R"igl_Qu8mg5v7(

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

 Determine if a set of points lies on the XY plane
  
   Inputs:
     V  #V by dim list of vertex positions
   Return true if a mesh has constant value of 0 in z coordinate
  
   Known bugs: Doesn't determine if vertex is flat if it doesn't lie on the
   XY plane.
)igl_Qu8mg5v7";

npe_function(is_planar)
npe_doc(ds_is_planar)

npe_arg(v, Eigen::MatrixXd &)



npe_begin_code()
using namespace std;



igl::is_planar(v);

return

npe_end_code()


