// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/readOFF.h>

const char* ds_read_off = R"igl_Qu8mg5v7(

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

 Read a mesh from an ascii OFF file, filling in vertex positions, normals
   and texture coordinates. Mesh may have faces of any number of degree
  
   Templates:
     Scalar  type for positions and vectors (will be read as double and cast
       to Scalar)
     Index  type for indices (will be read as int and cast to Index)
   Inputs:
    str  path to .obj file
   Outputs:
     V  double matrix of vertex positions  #V by 3
     F  #F list of face indices into vertex positions
     N  list of vertex normals #V by 3
     C  list of rgb color values per vertex #V by 3
   Returns true on success, false on errors
)igl_Qu8mg5v7";

npe_function(read_off)
npe_doc(ds_read_off)

npe_arg(off_file_name, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<double> > & v;
    std::vector<std::vector<int> > & f;
    std::vector<std::vector<double> > & n;
    std::vector<std::vector<double> > & c;
    igl::readOFF(off_file_name, v, f, n, c);
    return std::make_tuple(    npe::move(v),
    npe::move(f),
    npe::move(n),
    npe::move(c));
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<double> > & v;
    std::vector<std::vector<int> > & f;
    std::vector<std::vector<double> > & n;
    std::vector<std::vector<double> > & c;
    igl::readOFF(off_file_name, v, f, n, c);
    return std::make_tuple(    npe::move(v),     npe::move(f),     npe::move(n),     npe::move(c));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/readOFF.h>

const char* ds_read_off = R"igl_Qu8mg5v7(

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
     off_file  pointer to already opened .off file 
   Outputs:
     off_file  closed file
)igl_Qu8mg5v7";

npe_function(read_off)
npe_doc(ds_read_off)

npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    FILE * off_file;
    std::vector<std::vector<double> > & v;
    std::vector<std::vector<int> > & f;
    std::vector<std::vector<double> > & n;
    std::vector<std::vector<double> > & c;
    igl::readOFF(off_file, v, f, n, c);
    return std::make_tuple(    npe::move(off_file),
    npe::move(v),
    npe::move(f),
    npe::move(n),
    npe::move(c));
} else if (dtype.type() == npe::type_f64) {
    FILE * off_file;
    std::vector<std::vector<double> > & v;
    std::vector<std::vector<int> > & f;
    std::vector<std::vector<double> > & n;
    std::vector<std::vector<double> > & c;
    igl::readOFF(off_file, v, f, n, c);
    return std::make_tuple(    npe::move(off_file),     npe::move(v),     npe::move(f),     npe::move(n),     npe::move(c));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/readOFF.h>

const char* ds_read_off = R"igl_Qu8mg5v7(

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

 read mesh from a ascii off file
   Inputs:
     str  path to .off file
   Outputs:
     V  eigen double matrix #V by 3
     F  eigen int matrix #F by 3
)igl_Qu8mg5v7";

npe_function(read_off)
npe_doc(ds_read_off)

npe_arg(str, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v;
    dense_i32 f;
    igl::readOFF(str, v, f);
    return std::make_tuple(    npe::move(v),
    npe::move(f));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v;
    dense_i32 f;
    igl::readOFF(str, v, f);
    return std::make_tuple(    npe::move(v),     npe::move(f));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/readOFF.h>

const char* ds_read_off = R"igl_Qu8mg5v7(
See readOFF for the documentation.
)igl_Qu8mg5v7";

npe_function(read_off)
npe_doc(ds_read_off)

npe_arg(str, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v;
    dense_i32 f;
    dense_f32 n;
    igl::readOFF(str, v, f, n);
    return std::make_tuple(    npe::move(v),
    npe::move(f),
    npe::move(n));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v;
    dense_i32 f;
    dense_f64 n;
    igl::readOFF(str, v, f, n);
    return std::make_tuple(    npe::move(v),     npe::move(f),     npe::move(n));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


