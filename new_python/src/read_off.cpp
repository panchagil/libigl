#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>

#include <igl/readOFF.h>

const char* ds_read_off = R"igl_Qu8mg5v7(
Read a mesh from an ascii off file, filling in vertex positions, normals
and texture coordinates. Mesh may have faces of any number of degree.

Parameters
----------
filename : string, path to .off file
dtype : data-type of the returned objects, optional. Default is `float64`.
        (All integer return types are `int32` by default.)

Returns
-------
v : array of vertex positions #v by 3
f : #f list of face indices into vertex positions
n : list of vertex normals #v by 3

See also
--------
read_triangle_mesh, read_obj

Notes
-----
None

Examples
--------
>>> v, f, n, c = read_off("my_model.off")
)igl_Qu8mg5v7";

npe_function(read_off)
npe_doc(ds_read_off)

npe_arg(filename, std::string)
npe_default_arg(read_normals, bool, true)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;

if (dtype.type() == npe::type_f32) {
    Dense_f32 v, n; 
    Dense_i32 f;
    bool ret;
    if (read_normals) {
        ret = igl::readOFF(filename, v, f, n);
    }
    else {
        ret = igl::readOFF(filename, v, f);
    }

    if (!ret) {
        throw std::invalid_argument("File '" + filename + "' not found.");
    }

    return std::make_tuple(npe::move(v), npe::move(f), npe::move(n));
} else if (dtype.type() == npe::type_f64) {
    Dense_f64 v, n; 
    Dense_i32 f;
    bool ret;
    if (read_normals) {
        ret = igl::readOFF(filename, v, f, n);
    }
    else {
        ret = igl::readOFF(filename, v, f);
    }

    if (!ret) {
        throw std::invalid_argument("File '" + filename + "' not found.");
    }

    return std::make_tuple(npe::move(v), npe::move(f), npe::move(n));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
