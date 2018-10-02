// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/readNODE.h>

const char* ds_read_node = R"igl_Qu8mg5v7(

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

 load a list of points from a .node file
  
   Templates:
     Scalar  type for positions and vectors (will be read as double and cast
       to Scalar)
     Index  type for indices (will be read as int and cast to Index)
   Input:
     node_file_name  path of .node file
   Outputs:
     V  double matrix of vertex positions  #V by dim
     I  list of indices (first tells whether 0 or 1 indexed)
)igl_Qu8mg5v7";

npe_function(read_node)
npe_doc(ds_read_node)

npe_arg(node_file_name, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<double> > & v;
    std::vector<std::vector<int> > & i;
    igl::readNODE(node_file_name, v, i);
    return std::make_tuple(    npe::move(v),
    npe::move(i));
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<double> > & v;
    std::vector<std::vector<int> > & i;
    igl::readNODE(node_file_name, v, i);
    return std::make_tuple(    npe::move(v),     npe::move(i));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/readNODE.h>

const char* ds_read_node = R"igl_Qu8mg5v7(

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
     node_file_name  path of .node file
   Outputs:
     V  eigen double matrix #V by dim
)igl_Qu8mg5v7";

npe_function(read_node)
npe_doc(ds_read_node)

npe_arg(node_file_name, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v;
    dense_f32 i;
    igl::readNODE(node_file_name, v, i);
    return std::make_tuple(    npe::move(v),
    npe::move(i));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v;
    dense_f64 i;
    igl::readNODE(node_file_name, v, i);
    return std::make_tuple(    npe::move(v),     npe::move(i));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


