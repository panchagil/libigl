// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/writeDAE.h>

const char* ds_write_dae = R"igl_Qu8mg5v7(

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

 Write a mesh to a Collada .dae scene file. The resulting scene contains
     a single "geometry" suitable for solid operaions (boolean union,
     intersection, etc.) in SketchUp.
    
     Inputs:
       filename  path to .dae file
       V  #V by 3 list of vertex positions
       F  #F by 3 list of face indices
     Returns true iff success
    
)igl_Qu8mg5v7";

npe_function(write_dae)
npe_doc(ds_write_dae)

npe_arg(filename, std::string &)
npe_arg(v, dense_f64)
npe_arg(f, dense_i32)



npe_begin_code()
using namespace std;



igl::xml::writeDAE(filename, v, f);

return

npe_end_code()


