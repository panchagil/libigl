// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/ambient_occlusion.h>

const char* ds_ambient_occlusion = R"igl_Qu8mg5v7(

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
      V  #V by 3 list of mesh vertex positions
      F  #F by 3 list of mesh face indices into V
)igl_Qu8mg5v7";

npe_function(ambient_occlusion)
npe_doc(ds_ambient_occlusion)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(p, dense_f64)
npe_arg(n, dense_f64)
npe_arg(num_samples, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 s;
    igl::ambient_occlusion(v, f, p, n, num_samples, s);
    return npe::move(s);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 s;
    igl::ambient_occlusion(v, f, p, n, num_samples, s);
    return npe::move(s);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/ambient_occlusion.h>

const char* ds_ambient_occlusion = R"igl_Qu8mg5v7(

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

 Compute ambient occlusion per given point
  
   Inputs:
      shoot_ray  function handle that outputs hits of a given ray against a
        mesh (embedded in function handles as captured variable/data)
      P  #P by 3 list of origin points
      N  #P by 3 list of origin normals
   Outputs:
      S  #P list of ambient occlusion values between 1 (fully occluded) and
        0 (not occluded)
  
)igl_Qu8mg5v7";

npe_function(ambient_occlusion)
npe_doc(ds_ambient_occlusion)

npe_arg(shoot_ray, std::function<bool (const Eigen::Vector3f &, const Eigen::Vector3f &)> &)
npe_arg(p, dense_f64)
npe_arg(n, dense_f64)
npe_arg(num_samples, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 s;
    igl::ambient_occlusion(shoot_ray, p, n, num_samples, s);
    return npe::move(s);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 s;
    igl::ambient_occlusion(shoot_ray, p, n, num_samples, s);
    return npe::move(s);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/ambient_occlusion.h>

const char* ds_ambient_occlusion = R"igl_Qu8mg5v7(

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
     AABB  axis-aligned bounding box hierarchy around (V,F)
)igl_Qu8mg5v7";

npe_function(ambient_occlusion)
npe_doc(ds_ambient_occlusion)

npe_arg(aabb, igl::AABB<DerivedV, DIM> &)
npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(p, dense_f64)
npe_arg(n, dense_f64)
npe_arg(num_samples, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 s;
    igl::ambient_occlusion(aabb, v, f, p, n, num_samples, s);
    return npe::move(s);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 s;
    igl::ambient_occlusion(aabb, v, f, p, n, num_samples, s);
    return npe::move(s);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


