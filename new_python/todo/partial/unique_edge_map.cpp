// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/unique_edge_map.h>

const char* ds_unique_edge_map = R"igl_Qu8mg5v7(

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

 Construct relationships between facet "half"-(or rather "viewed")-edges E
   to unique edges of the mesh seen as a graph.
  
   Inputs:
     F  #F by 3  list of simplices
   Outputs:
     E  #F*3 by 2 list of all of directed edges
     uE  #uE by 2 list of unique undirected edges
     EMAP #F*3 list of indices into uE, mapping each directed edge to unique
       undirected edge
     uE2E  #uE list of lists of indices into E of coexisting edges
)igl_Qu8mg5v7";

npe_function(unique_edge_map)
npe_doc(ds_unique_edge_map)

npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 e;
    dense_f32 u_e;
    dense_f32 emap;
    std::vector<std::vector<uE2EType> > & u_e2_e;
    igl::unique_edge_map(f, e, u_e, emap, u_e2_e);
    return std::make_tuple(    npe::move(e),
    npe::move(u_e),
    npe::move(emap),
    npe::move(u_e2_e));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 e;
    dense_f64 u_e;
    dense_f64 emap;
    std::vector<std::vector<uE2EType> > & u_e2_e;
    igl::unique_edge_map(f, e, u_e, emap, u_e2_e);
    return std::make_tuple(    npe::move(e),     npe::move(u_e),     npe::move(emap),     npe::move(u_e2_e));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


