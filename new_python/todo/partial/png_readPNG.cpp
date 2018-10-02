// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/readPNG.h>

const char* ds_read_png = R"igl_Qu8mg5v7(

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

 Read an image from a .png file into 4 memory buffers
    
     Input:
      png_file  path to .png file
     Output:
      R,G,B,A texture channels
     Returns true on success, false on failure
    
)igl_Qu8mg5v7";

npe_function(read_png)
npe_doc(ds_read_png)

npe_arg(png_file, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::Matrix<unsigned char, Eigen::Dynamic, Eigen::Dynamic> r;
    Eigen::Matrix<unsigned char, Eigen::Dynamic, Eigen::Dynamic> g;
    Eigen::Matrix<unsigned char, Eigen::Dynamic, Eigen::Dynamic> b;
    Eigen::Matrix<unsigned char, Eigen::Dynamic, Eigen::Dynamic> a;
    igl::    png::readPNG(png_file, r, g, b, a);
    return std::make_tuple(    npe::move(r),
    npe::move(g),
    npe::move(b),
    npe::move(a));
} else if (dtype.type() == npe::type_f64) {
    Eigen::Matrix<unsigned char, Eigen::Dynamic, Eigen::Dynamic> r;
    Eigen::Matrix<unsigned char, Eigen::Dynamic, Eigen::Dynamic> g;
    Eigen::Matrix<unsigned char, Eigen::Dynamic, Eigen::Dynamic> b;
    Eigen::Matrix<unsigned char, Eigen::Dynamic, Eigen::Dynamic> a;
    igl::    png::readPNG(png_file, r, g, b, a);
    return std::make_tuple(    npe::move(r),     npe::move(g),     npe::move(b),     npe::move(a));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


