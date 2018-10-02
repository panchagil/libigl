// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/is_stl.h>

const char* ds_is_stl = R"igl_Qu8mg5v7(

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

 Given a file pointer, determine if it contains an .stl file and then
   rewind it.
   
   Inputs:
     stl_file  pointer to file 
   Outputs:
     is_ascii  flag whether stl is ascii
   Returns  whether stl_file is an .stl file
)igl_Qu8mg5v7";

npe_function(is_stl)
npe_doc(ds_is_stl)

npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    FILE * stl_file;
    bool & is_ascii;
    igl::is_stl(stl_file, is_ascii);
    return std::make_tuple(    npe::move(stl_file),
    npe::move(is_ascii));
} else if (dtype.type() == npe::type_f64) {
    FILE * stl_file;
    bool & is_ascii;
    igl::is_stl(stl_file, is_ascii);
    return std::make_tuple(    npe::move(stl_file),     npe::move(is_ascii));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/is_stl.h>

const char* ds_is_stl = R"igl_Qu8mg5v7(
See is_stl for the documentation.
)igl_Qu8mg5v7";

npe_function(is_stl)
npe_doc(ds_is_stl)

npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    FILE * stl_file;
    igl::is_stl(stl_file);
    return npe::move(stl_file);
} else if (dtype.type() == npe::type_f64) {
    FILE * stl_file;
    igl::is_stl(stl_file);
    return npe::move(stl_file);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


