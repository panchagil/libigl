#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/is_border_vertex.h>

const char* ds_is_border_vertex = R"igl_Qu8mg5v7(

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

 Determine vertices on open boundary of a (manifold) mesh with triangle
   faces F
  
   Inputs:
     V  #V by dim list of vertex positions 
     F  #F by 3 list of triangle indices
   Returns #V vector of bools revealing whether vertices are on boundary
  
   Known Bugs: - does not depend on V
               - assumes mesh is edge manifold
   
)igl_Qu8mg5v7";

npe_function(is_border_vertex)
npe_doc(ds_is_border_vertex)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)



npe_begin_code()
using namespace std;



igl::is_border_vertex(v, f);

return

npe_end_code()


