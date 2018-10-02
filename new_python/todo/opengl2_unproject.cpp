// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/unproject.h>

const char* ds_unproject = R"igl_Qu8mg5v7(
See unproject for the documentation.
)igl_Qu8mg5v7";

npe_function(unproject)
npe_doc(ds_unproject)

npe_arg(win, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 obj;
    igl::    opengl2::unproject(win, obj);
    return npe::move(obj);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 obj;
    igl::    opengl2::unproject(win, obj);
    return npe::move(obj);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/unproject.h>

const char* ds_unproject = R"igl_Qu8mg5v7(
See unproject for the documentation.
)igl_Qu8mg5v7";

npe_function(unproject)
npe_doc(ds_unproject)

npe_arg(win, dense_f64)



npe_begin_code()
using namespace std;



igl::opengl2::unproject(win);

return

npe_end_code()






// INCOMPLETE BINDINGS ========================
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

 Wrapper for gluUnproject that uses the current GL_MODELVIEW_MATRIX,
     GL_PROJECTION_MATRIX, and GL_VIEWPORT
     Inputs:
       win*  screen space x, y, and z coordinates respectively
     Outputs:
       obj*  pointers to 3D objects' x, y, and z coordinates respectively
     Returns return value of gluUnProject call
)igl_Qu8mg5v7";

npe_function(unproject)
npe_doc(ds_unproject)

npe_arg(win_x, double)
npe_arg(win_y, double)
npe_arg(win_z, double)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    double * obj_x;
    double * obj_y;
    double * obj_z;
    igl::    opengl2::unproject(win_x, win_y, win_z, obj_x, obj_y, obj_z);
    return std::make_tuple(    npe::move(obj_x),
    npe::move(obj_y),
    npe::move(obj_z));
} else if (dtype.type() == npe::type_f64) {
    double * obj_x;
    double * obj_y;
    double * obj_z;
    igl::    opengl2::unproject(win_x, win_y, win_z, obj_x, obj_y, obj_z);
    return std::make_tuple(    npe::move(obj_x),     npe::move(obj_y),     npe::move(obj_z));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


