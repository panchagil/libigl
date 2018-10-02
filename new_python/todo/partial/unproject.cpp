// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/unproject.h>

const char* ds_unproject = R"igl_Qu8mg5v7(

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

 Eigen reimplementation of gluUnproject
  
   Inputs:
     win  #P by 3 or 3-vector (#P=1) of screen space x, y, and z coordinates
     model  4x4 model-view matrix
     proj  4x4 projection matrix
     viewport  4-long viewport vector
   Outputs:
     scene  #P by 3 or 3-vector (#P=1) the unprojected x, y, and z coordinates
)igl_Qu8mg5v7";

npe_function(unproject)
npe_doc(ds_unproject)

npe_arg(win, dense_f64)
npe_arg(model, dense_f64)
npe_arg(proj, dense_f64)
npe_arg(viewport, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 scene;
    igl::unproject(win, model, proj, viewport, scene);
    return npe::move(scene);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 scene;
    igl::unproject(win, model, proj, viewport, scene);
    return npe::move(scene);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/unproject.h>

const char* ds_unproject = R"igl_Qu8mg5v7(
See unproject for the documentation.
)igl_Qu8mg5v7";

npe_function(unproject)
npe_doc(ds_unproject)

npe_arg(win, Eigen::Matrix<Scalar, 3, 1> &)
npe_arg(model, Eigen::Matrix<Scalar, 4, 4> &)
npe_arg(proj, Eigen::Matrix<Scalar, 4, 4> &)
npe_arg(viewport, Eigen::Matrix<Scalar, 4, 1> &)



npe_begin_code()
using namespace std;



igl::unproject(win, model, proj, viewport);

return

npe_end_code()


