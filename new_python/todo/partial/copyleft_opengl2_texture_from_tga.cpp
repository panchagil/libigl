// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/texture_from_tga.h>

const char* ds_texture_from_tga = R"igl_Qu8mg5v7(

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

 Read an image from a .tga file and use it as a texture
    
     Input:
      tga_file  path to .tga file
     Output:
      id  of generated openGL texture
     Returns true on success, false on failure
)igl_Qu8mg5v7";

npe_function(texture_from_tga)
npe_doc(ds_texture_from_tga)

npe_arg(tga_file, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    GLuint & id;
    igl::    opengl::texture_from_tga(tga_file, id);
    return npe::move(id);
} else if (dtype.type() == npe::type_f64) {
    GLuint & id;
    igl::    opengl::texture_from_tga(tga_file, id);
    return npe::move(id);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


