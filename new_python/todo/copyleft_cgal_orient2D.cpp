// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/orient2D.h>

const char* ds_orient2_d = R"igl_Qu8mg5v7(

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

 Inputs:
         pa,pb,pc   2D points.
       Output:
         1 if pa,pb,pc are counterclockwise oriented.
         0 if pa,pb,pc are counterclockwise oriented.
        -1 if pa,pb,pc are clockwise oriented.
)igl_Qu8mg5v7";

npe_function(orient2_d)
npe_doc(ds_orient2_d)

npe_arg(pa, Scalar [2])
npe_arg(pb, Scalar [2])
npe_arg(pc, Scalar [2])



npe_begin_code()
using namespace std;



igl::copyleft::cgal::orient2D(pa, pb, pc);

return

npe_end_code()


