#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/is_irregular_vertex.h>

const char* ds_is_irregular_vertex = R"igl_Qu8mg5v7(

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

 Determine if a vertex is irregular, i.e. it has more than 6 (triangles)
   or 4 (quads) incident edges. Vertices on the boundary are ignored.
  
   Inputs:
     V  #V by dim list of vertex positions
     F  #F by 3[4] list of triangle[quads] indices
   Returns #V vector of bools revealing whether vertices are singular
  
)igl_Qu8mg5v7";

npe_function(is_irregular_vertex)
npe_doc(ds_is_irregular_vertex)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)



npe_begin_code()
using namespace std;



igl::is_irregular_vertex(v, f);

return

npe_end_code()


