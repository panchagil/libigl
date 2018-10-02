// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/readSTL.h>

const char* ds_read_stl = R"igl_Qu8mg5v7(

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

 Read a mesh from an ascii/binary stl file.
  
   Templates:
     Scalar  type for positions and vectors (will be read as double and cast
       to Scalar)
   Inputs:
     filename path to .stl file
   Outputs:
     V  double matrix of vertex positions  #V*3 by 3
     F  index matrix of triangle indices #F by 3
     N  double matrix of surface normals #F by 3
   Returns true on success, false on errors
  
   Example:
     bool success = readSTL(filename,temp_V,F,N);
     remove_duplicate_vertices(temp_V,0,V,SVI,SVJ);
     for_each(F.data(),F.data()+F.size(),[&SVJ](int & f){f=SVJ(f);});
     writeOBJ("Downloads/cat.obj",V,F);
)igl_Qu8mg5v7";

npe_function(read_stl)
npe_doc(ds_read_stl)

npe_arg(filename, std::string &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v;
    dense_i32 f;
    dense_f32 n;
    igl::readSTL(filename, v, f, n);
    return std::make_tuple(    npe::move(v),
    npe::move(f),
    npe::move(n));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v;
    dense_i32 f;
    dense_f64 n;
    igl::readSTL(filename, v, f, n);
    return std::make_tuple(    npe::move(v),     npe::move(f),     npe::move(n));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/readSTL.h>

const char* ds_read_stl = R"igl_Qu8mg5v7(

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
     stl_file  pointer to already opened .stl file 
   Outputs:
     stl_file  closed file
)igl_Qu8mg5v7";

npe_function(read_stl)
npe_doc(ds_read_stl)

npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    FILE * stl_file;
    std::vector<std::vector<TypeV> > & v;
    std::vector<std::vector<TypeF> > & f;
    std::vector<std::vector<TypeN> > & n;
    igl::readSTL(stl_file, v, f, n);
    return std::make_tuple(    npe::move(stl_file),
    npe::move(v),
    npe::move(f),
    npe::move(n));
} else if (dtype.type() == npe::type_f64) {
    FILE * stl_file;
    std::vector<std::vector<TypeV> > & v;
    std::vector<std::vector<TypeF> > & f;
    std::vector<std::vector<TypeN> > & n;
    igl::readSTL(stl_file, v, f, n);
    return std::make_tuple(    npe::move(stl_file),     npe::move(v),     npe::move(f),     npe::move(n));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/readSTL.h>

const char* ds_read_stl = R"igl_Qu8mg5v7(
See readSTL for the documentation.
)igl_Qu8mg5v7";

npe_function(read_stl)
npe_doc(ds_read_stl)

npe_arg(filename, std::string &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<TypeV> > & v;
    std::vector<std::vector<TypeF> > & f;
    std::vector<std::vector<TypeN> > & n;
    igl::readSTL(filename, v, f, n);
    return std::make_tuple(    npe::move(v),
    npe::move(f),
    npe::move(n));
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<TypeV> > & v;
    std::vector<std::vector<TypeF> > & f;
    std::vector<std::vector<TypeN> > & n;
    igl::readSTL(filename, v, f, n);
    return std::make_tuple(    npe::move(v),     npe::move(f),     npe::move(n));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


