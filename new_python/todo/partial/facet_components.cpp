// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/facet_components.h>

const char* ds_facet_components = R"igl_Qu8mg5v7(

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

 Compute connected components of facets based on edge-edge adjacency.
  
   Inputs:
     F  #F by 3 list of triangle indices
   Outputs:
     C  #F list of connected component ids
)igl_Qu8mg5v7";

npe_function(facet_components)
npe_doc(ds_facet_components)

npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 c;
    igl::facet_components(f, c);
    return npe::move(c);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 c;
    igl::facet_components(f, c);
    return npe::move(c);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/facet_components.h>

const char* ds_facet_components = R"igl_Qu8mg5v7(

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
     TT  #TT by 3 list of list of adjacency triangles (see
     triangle_triangle_adjacency.h)
   Outputs:
     C  #F list of connected component ids
     counts #C list of number of facets in each components
)igl_Qu8mg5v7";

npe_function(facet_components)
npe_doc(ds_facet_components)

npe_arg(tt, std::vector<std::vector<std::vector<TTIndex> > > &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 c;
    dense_f32 counts;
    igl::facet_components(tt, c, counts);
    return std::make_tuple(    npe::move(c),
    npe::move(counts));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 c;
    dense_f64 counts;
    igl::facet_components(tt, c, counts);
    return std::make_tuple(    npe::move(c),     npe::move(counts));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


