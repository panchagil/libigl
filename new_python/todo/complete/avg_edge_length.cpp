#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/avg_edge_length.h>

const char* ds_avg_edge_length = R"igl_Qu8mg5v7(

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

 Compute the average edge length for the given triangle mesh
   Templates:
     DerivedV derived from vertex positions matrix type: i.e. MatrixXd
     DerivedF derived from face indices matrix type: i.e. MatrixXi
     DerivedL derived from edge lengths matrix type: i.e. MatrixXd
   Inputs:
     V  eigen matrix #V by 3
     F  #F by simplex-size list of mesh faces (must be simplex)
   Outputs:
     l  average edge length
  
   See also: adjacency_matrix
)igl_Qu8mg5v7";

npe_function(avg_edge_length)
npe_doc(ds_avg_edge_length)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)



npe_begin_code()
using namespace std;



igl::avg_edge_length(v, f);

return

npe_end_code()


