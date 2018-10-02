#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/directed_edge_parents.h>

const char* ds_directed_edge_parents = R"igl_Qu8mg5v7(

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

 Recover "parents" (preceding edges) in a tree given just directed edges.
  
   Inputs:
     E  #E by 2 list of directed edges
   Outputs:
     P  #E list of parent indices into E (-1) means root
  
)igl_Qu8mg5v7";

npe_function(directed_edge_parents)
npe_doc(ds_directed_edge_parents)

npe_arg(e, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 p;
    igl::directed_edge_parents(e, p);
    return npe::move(p);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 p;
    igl::directed_edge_parents(e, p);
    return npe::move(p);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


