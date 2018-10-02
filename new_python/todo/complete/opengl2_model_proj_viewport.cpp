#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/model_proj_viewport.h>

const char* ds_model_proj_viewport = R"igl_Qu8mg5v7(

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

 Collect the model-view, projection and viewport matrices
    
     Outputs:
       model  4x4 modelview matrix
       proj   4x4 projection matrix
       viewport  4x1 viewport vector
    
)igl_Qu8mg5v7";

npe_function(model_proj_viewport)
npe_doc(ds_model_proj_viewport)

npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 model;
    dense_f32 proj;
    dense_f32 viewport;
    igl::    opengl2::model_proj_viewport(model, proj, viewport);
    return std::make_tuple(    npe::move(model),
    npe::move(proj),
    npe::move(viewport));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 model;
    dense_f64 proj;
    dense_f64 viewport;
    igl::    opengl2::model_proj_viewport(model, proj, viewport);
    return std::make_tuple(    npe::move(model),     npe::move(proj),     npe::move(viewport));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


