#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/peel_outer_hull_layers.h>

const char* ds_peel_outer_hull_layers = R"igl_Qu8mg5v7(

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

 Computes necessary generic information for boolean operations by
       successively "peeling" off the "outer hull" of a mesh (V,F) resulting from
       "resolving" all (self-)intersections.
      
       Inputs:
         V  #V by 3 list of vertex positions
         F  #F by 3 list of triangle indices into V
       Outputs:
         I  #F list of which peel Iation a facet belongs 
         flip  #F list of whether a facet's orientation was flipped when facet
           "peeled" into its associated outer hull layer.
       Returns number of peels
)igl_Qu8mg5v7";

npe_function(peel_outer_hull_layers)
npe_doc(ds_peel_outer_hull_layers)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 i;
    dense_f32 flip;
    igl::    copyleft::    cgal::peel_outer_hull_layers(v, f, i, flip);
    return std::make_tuple(    npe::move(i),
    npe::move(flip));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 i;
    dense_f64 flip;
    igl::    copyleft::    cgal::peel_outer_hull_layers(v, f, i, flip);
    return std::make_tuple(    npe::move(i),     npe::move(flip));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


