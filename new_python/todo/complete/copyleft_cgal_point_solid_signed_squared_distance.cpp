#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/point_solid_signed_squared_distance.h>

const char* ds_point_solid_signed_squared_distance = R"igl_Qu8mg5v7(

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

 POINT_SOLID_SIGNED_SQUARED_DISTANCE Given a set of points (Q) and the
       boundary mesh (VB,FB) of a solid (as defined in [Zhou et al. 2016],
       determine the signed squared distance for each point q in Q so that d(q,B) is
       negative if inside and positive if outside.
      
       Inputs:
         Q  #Q by 3 list of query point positions
         VB  #VB by 3 list of mesh vertex positions of B
         FB  #FB by 3 list of mesh triangle indices into VB
       Outputs:
         D
)igl_Qu8mg5v7";

npe_function(point_solid_signed_squared_distance)
npe_doc(ds_point_solid_signed_squared_distance)

npe_arg(q, dense_f64)
npe_arg(vb, dense_f64)
npe_arg(fb, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 d;
    igl::    copyleft::    cgal::point_solid_signed_squared_distance(q, vb, fb, d);
    return npe::move(d);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 d;
    igl::    copyleft::    cgal::point_solid_signed_squared_distance(q, vb, fb, d);
    return npe::move(d);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


