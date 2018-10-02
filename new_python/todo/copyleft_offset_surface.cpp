// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/offset_surface.h>

const char* ds_offset_surface = R"igl_Qu8mg5v7(

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

 Compute a triangulated offset surface using matching cubes on a grid of
     signed distance values from the input triangle mesh.
    
     Inputs:
       V  #V by 3 list of mesh vertex positions
       F  #F by 3 list of mesh triangle indices into V
       isolevel  iso level to extract (signed distance: negative inside)
       s  number of grid cells along longest side (controls resolution)
       signed_distance_type  type of signing to use (see
         ../signed_distance.h)
     Outputs:
       SV  #SV by 3 list of output surface mesh vertex positions
       SF  #SF by 3 list of output mesh triangle indices into SV
       GV  #GV=side(0)*side(1)*side(2) by 3 list of grid cell centers
       side  list of number of grid cells in x, y, and z directions
       S  #GV by 3 list of signed distance values _near_ `isolevel` ("far"
         from `isolevel` these values are incorrect)
    
)igl_Qu8mg5v7";

npe_function(offset_surface)
npe_doc(ds_offset_surface)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(isolevel, isolevelType)
npe_arg(s, typename Derivedside::Scalar)
npe_arg(signed_distance_type, igl::SignedDistanceType &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 sv;
    dense_f32 sf;
    dense_f32 gv;
    dense_f32 side;
    dense_f32 s;
    igl::    copyleft::offset_surface(v, f, isolevel, s, signed_distance_type, sv, sf, gv, side, s);
    return std::make_tuple(    npe::move(sv),
    npe::move(sf),
    npe::move(gv),
    npe::move(side),
    npe::move(s));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 sv;
    dense_f64 sf;
    dense_f64 gv;
    dense_f64 side;
    dense_f64 s;
    igl::    copyleft::offset_surface(v, f, isolevel, s, signed_distance_type, sv, sf, gv, side, s);
    return std::make_tuple(    npe::move(sv),     npe::move(sf),     npe::move(gv),     npe::move(side),     npe::move(s));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


