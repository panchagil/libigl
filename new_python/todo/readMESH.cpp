// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/readMESH.h>

const char* ds_read_mesh = R"igl_Qu8mg5v7(

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

 load a tetrahedral volume mesh from a .mesh file
  
   Templates:
     Scalar  type for positions and vectors (will be read as double and cast
       to Scalar)
     Index  type for indices (will be read as int and cast to Index)
   Input:
     mesh_file_name  path of .mesh file
   Outputs:
     V  double matrix of vertex positions  #V by 3
     T  #T list of tet indices into vertex positions
     F  #F list of face indices into vertex positions
  
   Known bugs: Holes and regions are not supported
)igl_Qu8mg5v7";

npe_function(read_mesh)
npe_doc(ds_read_mesh)

npe_arg(mesh_file_name, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<double> > & v;
    std::vector<std::vector<int> > & t;
    std::vector<std::vector<int> > & f;
    igl::readMESH(mesh_file_name, v, t, f);
    return std::make_tuple(    npe::move(v),
    npe::move(t),
    npe::move(f));
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<double> > & v;
    std::vector<std::vector<int> > & t;
    std::vector<std::vector<int> > & f;
    igl::readMESH(mesh_file_name, v, t, f);
    return std::make_tuple(    npe::move(v),     npe::move(t),     npe::move(f));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/readMESH.h>

const char* ds_read_mesh = R"igl_Qu8mg5v7(

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
     mesh_file  pointer to already opened .mesh file 
   Outputs:
     mesh_file  closed file
)igl_Qu8mg5v7";

npe_function(read_mesh)
npe_doc(ds_read_mesh)

npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    FILE * mesh_file;
    std::vector<std::vector<double> > & v;
    std::vector<std::vector<int> > & t;
    std::vector<std::vector<int> > & f;
    igl::readMESH(mesh_file, v, t, f);
    return std::make_tuple(    npe::move(mesh_file),
    npe::move(v),
    npe::move(t),
    npe::move(f));
} else if (dtype.type() == npe::type_f64) {
    FILE * mesh_file;
    std::vector<std::vector<double> > & v;
    std::vector<std::vector<int> > & t;
    std::vector<std::vector<int> > & f;
    igl::readMESH(mesh_file, v, t, f);
    return std::make_tuple(    npe::move(mesh_file),     npe::move(v),     npe::move(t),     npe::move(f));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/readMESH.h>

const char* ds_read_mesh = R"igl_Qu8mg5v7(

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

 Input:
     mesh_file_name  path of .mesh file
   Outputs:
     V  eigen double matrix #V by 3
     T  eigen int matrix #T by 4
     F  eigen int matrix #F by 3
)igl_Qu8mg5v7";

npe_function(read_mesh)
npe_doc(ds_read_mesh)

npe_arg(mesh_file_name, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v;
    dense_f32 t;
    dense_i32 f;
    igl::readMESH(mesh_file_name, v, t, f);
    return std::make_tuple(    npe::move(v),
    npe::move(t),
    npe::move(f));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v;
    dense_f64 t;
    dense_i32 f;
    igl::readMESH(mesh_file_name, v, t, f);
    return std::make_tuple(    npe::move(v),     npe::move(t),     npe::move(f));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/readMESH.h>

const char* ds_read_mesh = R"igl_Qu8mg5v7(

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
     mesh_file  pointer to already opened .mesh file 
   Outputs:
     mesh_file  closed file
)igl_Qu8mg5v7";

npe_function(read_mesh)
npe_doc(ds_read_mesh)

npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    FILE * mesh_file;
    dense_f32 v;
    dense_f32 t;
    dense_i32 f;
    igl::readMESH(mesh_file, v, t, f);
    return std::make_tuple(    npe::move(mesh_file),
    npe::move(v),
    npe::move(t),
    npe::move(f));
} else if (dtype.type() == npe::type_f64) {
    FILE * mesh_file;
    dense_f64 v;
    dense_f64 t;
    dense_i32 f;
    igl::readMESH(mesh_file, v, t, f);
    return std::make_tuple(    npe::move(mesh_file),     npe::move(v),     npe::move(t),     npe::move(f));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


