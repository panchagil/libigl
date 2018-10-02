// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/outer_facet.h>

const char* ds_outer_facet = R"igl_Qu8mg5v7(

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

 Find a facet that is reachable from infinity without crossing any faces.
         Such facet is called "outer facet."
        
         Precondition: The input mesh must have all self-intersection resolved.  I.e
         there is no duplicated vertices, no overlapping edge and no intersecting
         faces (the only exception is there could be topologically duplicated faces).
         See cgal::remesh_self_intersections.h for how to obtain such input.
        
         This function differ from igl::outer_facet() in the fact this
         function is more robust because it does not rely on facet normals.
        
         Inputs:
           V  #V by 3 list of vertex positions
           F  #F by 3 list of triangle indices into V
           I  #I list of facets to consider
         Outputs:
           f  Index of the outer facet.
           flipped  true iff the normal of f points inwards.
)igl_Qu8mg5v7";

npe_function(outer_facet)
npe_doc(ds_outer_facet)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(i, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    IndexType & f;
    bool & flipped;
    igl::    copyleft::    cgal::outer_facet(v, f, i, f, flipped);
    return std::make_tuple(    npe::move(f),
    npe::move(flipped));
} else if (dtype.type() == npe::type_f64) {
    IndexType & f;
    bool & flipped;
    igl::    copyleft::    cgal::outer_facet(v, f, i, f, flipped);
    return std::make_tuple(    npe::move(f),     npe::move(flipped));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/outer_facet.h>

const char* ds_outer_facet = R"igl_Qu8mg5v7(

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

 Find a facet that is reachable from infinity without crossing any faces.
       Such facet is called "outer facet."
      
       Precondition: The input mesh must have all self-intersection resolved.
       I.e there is no duplicated vertices, no overlapping edge and no
       intersecting faces (the only exception is there could be topologically
       duplicated faces).  See cgal::remesh_self_intersections.h for how to
       obtain such input.
      
       Inputs:
         V  #V by 3 list of vertex positions
         F  #F by 3 list of triangle indices into V
         N  #N by 3 list of face normals
         I  #I list of facets to consider
       Outputs:
         f  Index of the outer facet.
         flipped  true iff the normal of f points inwards.
)igl_Qu8mg5v7";

npe_function(outer_facet)
npe_doc(ds_outer_facet)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(n, dense_f64)
npe_arg(i, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    IndexType & f;
    bool & flipped;
    igl::    copyleft::    cgal::outer_facet(v, f, n, i, f, flipped);
    return std::make_tuple(    npe::move(f),
    npe::move(flipped));
} else if (dtype.type() == npe::type_f64) {
    IndexType & f;
    bool & flipped;
    igl::    copyleft::    cgal::outer_facet(v, f, n, i, f, flipped);
    return std::make_tuple(    npe::move(f),     npe::move(flipped));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


