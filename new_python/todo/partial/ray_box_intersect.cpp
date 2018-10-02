// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/ray_box_intersect.h>

const char* ds_ray_box_intersect = R"igl_Qu8mg5v7(

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

 Determine whether a ray origin+t*dir and box intersect within the ray's parameterized
   range (t0,t1)
  
   Inputs:
     source  3-vector origin of ray
     dir  3-vector direction of ray
     box  axis aligned box
     t0  hit only if hit.t less than t0
     t1  hit only if hit.t greater than t1
   Outputs:
     tmin  minimum of interval of overlap within [t0,t1]
     tmax  maximum of interval of overlap within [t0,t1]
   Returns true if hit
)igl_Qu8mg5v7";

npe_function(ray_box_intersect)
npe_doc(ds_ray_box_intersect)

npe_arg(source, dense_f64)
npe_arg(dir, dense_f64)
npe_arg(box, Eigen::AlignedBox<Scalar, 3> &)
npe_arg(t0, Scalar &)
npe_arg(t1, Scalar &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Scalar & tmin;
    Scalar & tmax;
    igl::ray_box_intersect(source, dir, box, t0, t1, tmin, tmax);
    return std::make_tuple(    npe::move(tmin),
    npe::move(tmax));
} else if (dtype.type() == npe::type_f64) {
    Scalar & tmin;
    Scalar & tmax;
    igl::ray_box_intersect(source, dir, box, t0, t1, tmin, tmax);
    return std::make_tuple(    npe::move(tmin),     npe::move(tmax));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


