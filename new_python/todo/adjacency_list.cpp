// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/adjacency_list.h>

const char* ds_adjacency_list = R"igl_Qu8mg5v7(

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

 Variant that accepts polygonal faces. 
   Each element of F is a set of indices of a polygonal face.
)igl_Qu8mg5v7";

npe_function(adjacency_list)
npe_doc(ds_adjacency_list)

npe_arg(f, std::vector<std::vector<int> > &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<int> > & a;
    igl::adjacency_list(f, a);
    return npe::move(a);
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<int> > & a;
    igl::adjacency_list(f, a);
    return npe::move(a);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/adjacency_list.h>

const char* ds_adjacency_list = R"igl_Qu8mg5v7(

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

 Constructs the graph adjacency list of a given mesh (V,F)
   Templates:
     T  should be a eigen sparse matrix primitive type like int or double
   Inputs:
     F       #F by dim list of mesh faces (must be triangles)
     sorted  flag that indicates if the list should be sorted counter-clockwise
   Outputs: 
     A  vector<vector<T> > containing at row i the adjacent vertices of vertex i
  
   Example:
      Mesh in (V,F)
     vector<vector<double> > A;
     adjacency_list(F,A);
  
   See also: edges, cotmatrix, diag
)igl_Qu8mg5v7";

npe_function(adjacency_list)
npe_doc(ds_adjacency_list)

npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<IndexVector> > & a;
    bool sorted;
    igl::adjacency_list(f, a, sorted);
    return std::make_tuple(    npe::move(a),
    npe::move(sorted));
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<IndexVector> > & a;
    bool sorted;
    igl::adjacency_list(f, a, sorted);
    return std::make_tuple(    npe::move(a),     npe::move(sorted));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


