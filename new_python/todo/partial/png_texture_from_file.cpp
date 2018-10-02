// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/texture_from_file.h>

const char* ds_texture_from_file = R"igl_Qu8mg5v7(

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

 Read an image from an image file and use it as a texture. Officially,
     only <del>.tga and</del> .png are supported. Any filetype read by
     ImageMagick's `convert` will work via an unsafe system call.
    
     Input:
      filename  path to image file
     Output:
      id  of generated openGL texture
     Returns true on success, false on failure
)igl_Qu8mg5v7";

npe_function(texture_from_file)
npe_doc(ds_texture_from_file)

npe_arg(filename, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    int & id;
    igl::    png::texture_from_file(filename, id);
    return npe::move(id);
} else if (dtype.type() == npe::type_f64) {
    int & id;
    igl::    png::texture_from_file(filename, id);
    return npe::move(id);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


