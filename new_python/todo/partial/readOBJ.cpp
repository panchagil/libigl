// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/readOBJ.h>

const char* ds_read_obj = R"igl_Qu8mg5v7(

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

 Read a mesh from an ascii obj file, filling in vertex positions, normals
   and texture coordinates. Mesh may have faces of any number of degree
  
   Templates:
     Scalar  type for positions and vectors (will be read as double and cast
       to Scalar)
     Index  type for indices (will be read as int and cast to Index)
   Inputs:
    str  path to .obj file
   Outputs:
     V  double matrix of vertex positions  #V by 3
     TC  double matrix of texture coordinats #TC by 2
     N  double matrix of corner normals #N by 3
     F  #F list of face indices into vertex positions
     FTC  #F list of face indices into vertex texture coordinates
     FN  #F list of face indices into vertex normals
   Returns true on success, false on errors
)igl_Qu8mg5v7";

npe_function(read_obj)
npe_doc(ds_read_obj)

npe_arg(obj_file_name, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<double> > & v;
    std::vector<std::vector<double> > & tc;
    std::vector<std::vector<double> > & n;
    std::vector<std::vector<int> > & f;
    std::vector<std::vector<int> > & ftc;
    std::vector<std::vector<int> > & fn;
    igl::readOBJ(obj_file_name, v, tc, n, f, ftc, fn);
    return std::make_tuple(    npe::move(v),
    npe::move(tc),
    npe::move(n),
    npe::move(f),
    npe::move(ftc),
    npe::move(fn));
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<double> > & v;
    std::vector<std::vector<double> > & tc;
    std::vector<std::vector<double> > & n;
    std::vector<std::vector<int> > & f;
    std::vector<std::vector<int> > & ftc;
    std::vector<std::vector<int> > & fn;
    igl::readOBJ(obj_file_name, v, tc, n, f, ftc, fn);
    return std::make_tuple(    npe::move(v),     npe::move(tc),     npe::move(n),     npe::move(f),     npe::move(ftc),     npe::move(fn));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/readOBJ.h>

const char* ds_read_obj = R"igl_Qu8mg5v7(

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
     obj_file  pointer to already opened .obj file 
   Outputs:
     obj_file  closed file
)igl_Qu8mg5v7";

npe_function(read_obj)
npe_doc(ds_read_obj)

npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    FILE * obj_file;
    std::vector<std::vector<double> > & v;
    std::vector<std::vector<double> > & tc;
    std::vector<std::vector<double> > & n;
    std::vector<std::vector<int> > & f;
    std::vector<std::vector<int> > & ftc;
    std::vector<std::vector<int> > & fn;
    igl::readOBJ(obj_file, v, tc, n, f, ftc, fn);
    return std::make_tuple(    npe::move(obj_file),
    npe::move(v),
    npe::move(tc),
    npe::move(n),
    npe::move(f),
    npe::move(ftc),
    npe::move(fn));
} else if (dtype.type() == npe::type_f64) {
    FILE * obj_file;
    std::vector<std::vector<double> > & v;
    std::vector<std::vector<double> > & tc;
    std::vector<std::vector<double> > & n;
    std::vector<std::vector<int> > & f;
    std::vector<std::vector<int> > & ftc;
    std::vector<std::vector<int> > & fn;
    igl::readOBJ(obj_file, v, tc, n, f, ftc, fn);
    return std::make_tuple(    npe::move(obj_file),     npe::move(v),     npe::move(tc),     npe::move(n),     npe::move(f),     npe::move(ftc),     npe::move(fn));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/readOBJ.h>

const char* ds_read_obj = R"igl_Qu8mg5v7(

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

 Just V and F
)igl_Qu8mg5v7";

npe_function(read_obj)
npe_doc(ds_read_obj)

npe_arg(obj_file_name, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<double> > & v;
    std::vector<std::vector<int> > & f;
    igl::readOBJ(obj_file_name, v, f);
    return std::make_tuple(    npe::move(v),
    npe::move(f));
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<double> > & v;
    std::vector<std::vector<int> > & f;
    igl::readOBJ(obj_file_name, v, f);
    return std::make_tuple(    npe::move(v),     npe::move(f));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/readOBJ.h>

const char* ds_read_obj = R"igl_Qu8mg5v7(

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

 Eigen Wrappers. These will return true only if the data is perfectly
   "rectangular": All faces are the same degree, all have the same number of
   textures/normals etc.
)igl_Qu8mg5v7";

npe_function(read_obj)
npe_doc(ds_read_obj)

npe_arg(str, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v;
    dense_f32 tc;
    dense_f32 cn;
    dense_i32 f;
    dense_f32 ftc;
    dense_f32 fn;
    igl::readOBJ(str, v, tc, cn, f, ftc, fn);
    return std::make_tuple(    npe::move(v),
    npe::move(tc),
    npe::move(cn),
    npe::move(f),
    npe::move(ftc),
    npe::move(fn));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v;
    dense_f64 tc;
    dense_f64 cn;
    dense_i32 f;
    dense_f64 ftc;
    dense_f64 fn;
    igl::readOBJ(str, v, tc, cn, f, ftc, fn);
    return std::make_tuple(    npe::move(v),     npe::move(tc),     npe::move(cn),     npe::move(f),     npe::move(ftc),     npe::move(fn));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/readOBJ.h>

const char* ds_read_obj = R"igl_Qu8mg5v7(
See readOBJ for the documentation.
)igl_Qu8mg5v7";

npe_function(read_obj)
npe_doc(ds_read_obj)

npe_arg(str, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v;
    dense_i32 f;
    igl::readOBJ(str, v, f);
    return std::make_tuple(    npe::move(v),
    npe::move(f));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v;
    dense_i32 f;
    igl::readOBJ(str, v, f);
    return std::make_tuple(    npe::move(v),     npe::move(f));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


