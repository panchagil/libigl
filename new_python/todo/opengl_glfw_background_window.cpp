// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/background_window.h>

const char* ds_background_window = R"igl_Qu8mg5v7(

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

 Create a background window with a valid core profile opengl context
       set to current.
      
       After you're finished with this window you may call
       `glfwDestroyWindow(window)`
      
       After you're finished with glfw you should call `glfwTerminate()`
      
       Outputs:
          window  pointer to glfw window
       Returns true iff success
)igl_Qu8mg5v7";

npe_function(background_window)
npe_doc(ds_background_window)

npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    int *& window;
    igl::    opengl::    glfw::background_window(window);
    return npe::move(window);
} else if (dtype.type() == npe::type_f64) {
    int *& window;
    igl::    opengl::    glfw::background_window(window);
    return npe::move(window);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


