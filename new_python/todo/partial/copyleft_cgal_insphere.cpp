// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/insphere.h>

const char* ds_insphere = R"igl_Qu8mg5v7(

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
         pa,pb,pc,pd,pe  3D points.
       Output:
         1 if pe is inside of the oriented sphere formed by pa,pb,pc,pd.
         0 if pe is co-spherical with pa,pb,pc,pd.
        -1 if pe is outside of the oriented sphere formed by pa,pb,pc,pd.
)igl_Qu8mg5v7";

npe_function(insphere)
npe_doc(ds_insphere)

npe_arg(pa, Scalar [3])
npe_arg(pb, Scalar [3])
npe_arg(pc, Scalar [3])
npe_arg(pd, Scalar [3])
npe_arg(pe, Scalar [3])



npe_begin_code()
using namespace std;



igl::copyleft::cgal::insphere(pa, pb, pc, pd, pe);

return

npe_end_code()


