// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/ray_sphere_intersect.h>

const char* ds_ray_sphere_intersect = R"igl_Qu8mg5v7(

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

 Compute the intersection between a ray from O in direction D and a sphere
   centered at C with radius r
  
   Inputs:
     o  origin of ray
     d  direction of ray
     c  center of sphere
     r  radius of sphere
   Outputs:
     t0  parameterization of first hit (set only if exists) so that hit
      position = o + t0*d
     t1  parameterization of second hit (set only if exists)
     
   Returns the number of hits
)igl_Qu8mg5v7";

npe_function(ray_sphere_intersect)
npe_doc(ds_ray_sphere_intersect)

npe_arg(o, dense_f64)
npe_arg(d, dense_f64)
npe_arg(c, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    r_type r;
    t_type & t0;
    t_type & t1;
    igl::ray_sphere_intersect(o, d, c, r, t0, t1);
    return std::make_tuple(    npe::move(r),
    npe::move(t0),
    npe::move(t1));
} else if (dtype.type() == npe::type_f64) {
    r_type r;
    t_type & t0;
    t_type & t1;
    igl::ray_sphere_intersect(o, d, c, r, t0, t1);
    return std::make_tuple(    npe::move(r),     npe::move(t0),     npe::move(t1));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


