// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/read_triangle_mesh.h>

const char* ds_read_triangle_mesh = R"igl_Qu8mg5v7(

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

 read mesh from an ascii file with automatic detection of file format.
   supported: obj, off, stl, wrl, ply, mesh)
   
   Templates:
     Scalar  type for positions and vectors (will be read as double and cast
       to Scalar)
     Index  type for indices (will be read as int and cast to Index)
   Inputs:
     str  path to file
   Outputs:
     V  eigen double matrix #V by 3
     F  eigen int matrix #F by 3
   Returns true iff success
)igl_Qu8mg5v7";

npe_function(read_triangle_mesh)
npe_doc(ds_read_triangle_mesh)

npe_arg(str, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<double> > & v;
    std::vector<std::vector<int> > & f;
    igl::read_triangle_mesh(str, v, f);
    return std::make_tuple(    npe::move(v),
    npe::move(f));
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<double> > & v;
    std::vector<std::vector<int> > & f;
    igl::read_triangle_mesh(str, v, f);
    return std::make_tuple(    npe::move(v),     npe::move(f));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/read_triangle_mesh.h>

const char* ds_read_triangle_mesh = R"igl_Qu8mg5v7(
See read_triangle_mesh for the documentation.
)igl_Qu8mg5v7";

npe_function(read_triangle_mesh)
npe_doc(ds_read_triangle_mesh)

npe_arg(str, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v;
    dense_i32 f;
    igl::read_triangle_mesh(str, v, f);
    return std::make_tuple(    npe::move(v),
    npe::move(f));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v;
    dense_i32 f;
    igl::read_triangle_mesh(str, v, f);
    return std::make_tuple(    npe::move(v),     npe::move(f));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/read_triangle_mesh.h>

const char* ds_read_triangle_mesh = R"igl_Qu8mg5v7(

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

 Outputs:
    dir  directory path (see pathinfo.h)
    base  base name (see pathinfo.h)
    ext  extension (see pathinfo.h)
    name  filename (see pathinfo.h)
)igl_Qu8mg5v7";

npe_function(read_triangle_mesh)
npe_doc(ds_read_triangle_mesh)

npe_arg(str, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v;
    dense_i32 f;
    std::string & dir;
    std::string & base;
    std::string & ext;
    std::string & name;
    igl::read_triangle_mesh(str, v, f, dir, base, ext, name);
    return std::make_tuple(    npe::move(v),
    npe::move(f),
    npe::move(dir),
    npe::move(base),
    npe::move(ext),
    npe::move(name));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v;
    dense_i32 f;
    std::string & dir;
    std::string & base;
    std::string & ext;
    std::string & name;
    igl::read_triangle_mesh(str, v, f, dir, base, ext, name);
    return std::make_tuple(    npe::move(v),     npe::move(f),     npe::move(dir),     npe::move(base),     npe::move(ext),     npe::move(name));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/read_triangle_mesh.h>

const char* ds_read_triangle_mesh = R"igl_Qu8mg5v7(

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

 Inputs:
     ext  file extension
     fp  pointer to already opened .ext file 
   Outputs:
     fp  closed file
)igl_Qu8mg5v7";

npe_function(read_triangle_mesh)
npe_doc(ds_read_triangle_mesh)

npe_arg(ext, std::string &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    FILE * fp;
    dense_f32 v;
    dense_i32 f;
    igl::read_triangle_mesh(ext, fp, v, f);
    return std::make_tuple(    npe::move(fp),
    npe::move(v),
    npe::move(f));
} else if (dtype.type() == npe::type_f64) {
    FILE * fp;
    dense_f64 v;
    dense_i32 f;
    igl::read_triangle_mesh(ext, fp, v, f);
    return std::make_tuple(    npe::move(fp),     npe::move(v),     npe::move(f));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


