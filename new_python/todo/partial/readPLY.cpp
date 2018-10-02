// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/readPLY.h>

const char* ds_read_ply = R"igl_Qu8mg5v7(

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

 Read a mesh from a .ply file. 
  
   Inputs:
     filename  path to .ply file
   Outputs:
     V  #V by 3 list of vertex positions
     F  #F list of lists of triangle indices
     N  #V by 3 list of vertex normals
     UV  #V by 2 list of vertex texture coordinates
   Returns true iff success
)igl_Qu8mg5v7";

npe_function(read_ply)
npe_doc(ds_read_ply)

npe_arg(filename, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<Vtype> > & v;
    std::vector<std::vector<Ftype> > & f;
    std::vector<std::vector<Ntype> > & n;
    std::vector<std::vector<UVtype> > & uv;
    igl::readPLY(filename, v, f, n, uv);
    return std::make_tuple(    npe::move(v),
    npe::move(f),
    npe::move(n),
    npe::move(uv));
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<Vtype> > & v;
    std::vector<std::vector<Ftype> > & f;
    std::vector<std::vector<Ntype> > & n;
    std::vector<std::vector<UVtype> > & uv;
    igl::readPLY(filename, v, f, n, uv);
    return std::make_tuple(    npe::move(v),     npe::move(f),     npe::move(n),     npe::move(uv));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/readPLY.h>

const char* ds_read_ply = R"igl_Qu8mg5v7(
See readPLY for the documentation.
)igl_Qu8mg5v7";

npe_function(read_ply)
npe_doc(ds_read_ply)

npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    FILE * ply_file;
    std::vector<std::vector<Vtype> > & v;
    std::vector<std::vector<Ftype> > & f;
    std::vector<std::vector<Ntype> > & n;
    std::vector<std::vector<UVtype> > & uv;
    igl::readPLY(ply_file, v, f, n, uv);
    return std::make_tuple(    npe::move(ply_file),
    npe::move(v),
    npe::move(f),
    npe::move(n),
    npe::move(uv));
} else if (dtype.type() == npe::type_f64) {
    FILE * ply_file;
    std::vector<std::vector<Vtype> > & v;
    std::vector<std::vector<Ftype> > & f;
    std::vector<std::vector<Ntype> > & n;
    std::vector<std::vector<UVtype> > & uv;
    igl::readPLY(ply_file, v, f, n, uv);
    return std::make_tuple(    npe::move(ply_file),     npe::move(v),     npe::move(f),     npe::move(n),     npe::move(uv));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/readPLY.h>

const char* ds_read_ply = R"igl_Qu8mg5v7(
See readPLY for the documentation.
)igl_Qu8mg5v7";

npe_function(read_ply)
npe_doc(ds_read_ply)

npe_arg(filename, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v;
    dense_i32 f;
    dense_f32 n;
    dense_f32 uv;
    igl::readPLY(filename, v, f, n, uv);
    return std::make_tuple(    npe::move(v),
    npe::move(f),
    npe::move(n),
    npe::move(uv));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v;
    dense_i32 f;
    dense_f64 n;
    dense_f64 uv;
    igl::readPLY(filename, v, f, n, uv);
    return std::make_tuple(    npe::move(v),     npe::move(f),     npe::move(n),     npe::move(uv));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/readPLY.h>

const char* ds_read_ply = R"igl_Qu8mg5v7(
See readPLY for the documentation.
)igl_Qu8mg5v7";

npe_function(read_ply)
npe_doc(ds_read_ply)

npe_arg(filename, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v;
    dense_i32 f;
    igl::readPLY(filename, v, f);
    return std::make_tuple(    npe::move(v),
    npe::move(f));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v;
    dense_i32 f;
    igl::readPLY(filename, v, f);
    return std::make_tuple(    npe::move(v),     npe::move(f));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


