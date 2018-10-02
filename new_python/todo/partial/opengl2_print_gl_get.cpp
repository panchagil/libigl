// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/print_gl_get.h>

const char* ds_print_gl_get = R"igl_Qu8mg5v7(

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

 Prints the value of pname found by issuing glGet*(pname,*)
     Inputs:
       pname  enum key to gl parameter
)igl_Qu8mg5v7";

npe_function(print_gl_get)
npe_doc(ds_print_gl_get)

npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    GLenum pname;
    igl::    opengl2::print_gl_get(pname);
    return npe::move(pname);
} else if (dtype.type() == npe::type_f64) {
    GLenum pname;
    igl::    opengl2::print_gl_get(pname);
    return npe::move(pname);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


