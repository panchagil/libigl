#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/squared_edge_lengths.h>

const char* ds_squared_edge_lengths = R"igl_Qu8mg5v7(

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

 Constructs a list of squared lengths of edges opposite each index in a face
   (triangle/tet) list
  
   Templates:
     DerivedV derived from vertex positions matrix type: i.e. MatrixXd
     DerivedF derived from face indices matrix type: i.e. MatrixXi
     DerivedL derived from edge lengths matrix type: i.e. MatrixXd
   Inputs:
     V  eigen matrix #V by 3
     F  #F by 2 list of mesh edges
      or
     F  #F by 3 list of mesh faces (must be triangles)
      or
     T  #T by 4 list of mesh elements (must be tets)
   Outputs:
     L  #F by {1|3|6} list of edge lengths squared
       for edges, column of lengths
       for triangles, columns correspond to edges [1,2],[2,0],[0,1]
       for tets, columns correspond to edges
       [3 0],[3 1],[3 2],[1 2],[2 0],[0 1]
  
)igl_Qu8mg5v7";

npe_function(squared_edge_lengths)
npe_doc(ds_squared_edge_lengths)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 l;
    igl::squared_edge_lengths(v, f, l);
    return npe::move(l);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 l;
    igl::squared_edge_lengths(v, f, l);
    return npe::move(l);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


