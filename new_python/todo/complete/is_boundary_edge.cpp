#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/is_boundary_edge.h>

const char* ds_is_boundary_edge = R"igl_Qu8mg5v7(

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

  IS_BOUNDARY_EDGE Determine for each edge E if it is a "boundary edge" in F.
    Boundary edges are undirected edges which occur only once.
   
    Inputs:
      E  #E by 2 list of edges
      F  #F by 3 list of triangles
    Outputs:
      B  #E list bools. true iff unoriented edge occurs exactly once in F
        (non-manifold and non-existant edges will be false)
   
)igl_Qu8mg5v7";

npe_function(is_boundary_edge)
npe_doc(ds_is_boundary_edge)

npe_arg(e, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 b;
    igl::is_boundary_edge(e, f, b);
    return npe::move(b);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 b;
    igl::is_boundary_edge(e, f, b);
    return npe::move(b);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/is_boundary_edge.h>

const char* ds_is_boundary_edge = R"igl_Qu8mg5v7(

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

 Wrapper where Edges should also be computed from F
     E  #E by 2 list of edges
     EMAP  #F*3 list of indices mapping allE to E
)igl_Qu8mg5v7";

npe_function(is_boundary_edge)
npe_doc(ds_is_boundary_edge)

npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 b;
    dense_f32 e;
    dense_f32 emap;
    igl::is_boundary_edge(f, b, e, emap);
    return std::make_tuple(    npe::move(b),
    npe::move(e),
    npe::move(emap));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 b;
    dense_f64 e;
    dense_f64 emap;
    igl::is_boundary_edge(f, b, e, emap);
    return std::make_tuple(    npe::move(b),     npe::move(e),     npe::move(emap));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


