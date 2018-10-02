// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/texture_from_png.h>

const char* ds_texture_from_png = R"igl_Qu8mg5v7(

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

 Read an image from a .png file and use it as a texture
    
     Input:
      png_file  path to .png file
      flip  whether to flip the image vertically (A --> ∀)
     Output:
      id  of generated openGL texture
     Returns true on success, false on failure
)igl_Qu8mg5v7";

npe_function(texture_from_png)
npe_doc(ds_texture_from_png)

npe_arg(png_file, std::string)
npe_arg(flip, bool)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    int & id;
    igl::    png::texture_from_png(png_file, flip, id);
    return npe::move(id);
} else if (dtype.type() == npe::type_f64) {
    int & id;
    igl::    png::texture_from_png(png_file, flip, id);
    return npe::move(id);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/texture_from_png.h>

const char* ds_texture_from_png = R"igl_Qu8mg5v7(
See texture_from_png for the documentation.
)igl_Qu8mg5v7";

npe_function(texture_from_png)
npe_doc(ds_texture_from_png)

npe_arg(png_file, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    int & id;
    igl::    png::texture_from_png(png_file, id);
    return npe::move(id);
} else if (dtype.type() == npe::type_f64) {
    int & id;
    igl::    png::texture_from_png(png_file, id);
    return npe::move(id);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/texture_from_png.h>

const char* ds_texture_from_png = R"igl_Qu8mg5v7(

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

 Read an image from a .png file and use it as a texture
    
     Input:
      png_file  path to .png file
     Output:
      R,G,B,A texture channels
     Returns true on success, false on failure
    
     Todo: this is an inappropriate function name. This is really just
     reading a png.... Not necessarily as a texture.
)igl_Qu8mg5v7";

npe_function(texture_from_png)
npe_doc(ds_texture_from_png)

npe_arg(png_file, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    int & r;
    int & g;
    int & b;
    int & a;
    igl::    png::texture_from_png(png_file, r, g, b, a);
    return std::make_tuple(    npe::move(r),
    npe::move(g),
    npe::move(b),
    npe::move(a));
} else if (dtype.type() == npe::type_f64) {
    int & r;
    int & g;
    int & b;
    int & a;
    igl::    png::texture_from_png(png_file, r, g, b, a);
    return std::make_tuple(    npe::move(r),     npe::move(g),     npe::move(b),     npe::move(a));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


