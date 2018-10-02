#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/unproject_ray.h>

const char* ds_unproject_ray = R"igl_Qu8mg5v7(

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

 Construct a ray (source point + direction vector) given a screen space
   positions (e.g. mouse) and a model-view projection constellation.
  
   Inputs:
     pos  2d screen-space position (x,y) 
     model  4x4 model-view matrix
     proj  4x4 projection matrix
     viewport  4-long viewport vector
   Outputs:
     s  source of ray (pos unprojected with z=0)
  /  dir  direction of ray (d - s) where d is pos unprojected with z=1
   
)igl_Qu8mg5v7";

npe_function(unproject_ray)
npe_doc(ds_unproject_ray)

npe_arg(pos, dense_f64)
npe_arg(model, dense_f64)
npe_arg(proj, dense_f64)
npe_arg(viewport, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 s;
    dense_f32 dir;
    igl::unproject_ray(pos, model, proj, viewport, s, dir);
    return std::make_tuple(    npe::move(s),
    npe::move(dir));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 s;
    dense_f64 dir;
    igl::unproject_ray(pos, model, proj, viewport, s, dir);
    return std::make_tuple(    npe::move(s),     npe::move(dir));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


