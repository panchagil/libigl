// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/file_contents_as_string.h>

const char* ds_file_contents_as_string = R"igl_Qu8mg5v7(

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

 Read a files contents as plain text into a given string
   Inputs:
     file_name  path to file to be read
   Outputs:
     content  output string containing contents of the given file
   Returns true on succes, false on error
)igl_Qu8mg5v7";

npe_function(file_contents_as_string)
npe_doc(ds_file_contents_as_string)

npe_arg(file_name, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::string & content;
    igl::file_contents_as_string(file_name, content);
    return npe::move(content);
} else if (dtype.type() == npe::type_f64) {
    std::string & content;
    igl::file_contents_as_string(file_name, content);
    return npe::move(content);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/file_contents_as_string.h>

const char* ds_file_contents_as_string = R"igl_Qu8mg5v7(
See file_contents_as_string for the documentation.
)igl_Qu8mg5v7";

npe_function(file_contents_as_string)
npe_doc(ds_file_contents_as_string)

npe_arg(file_name, std::string)



npe_begin_code()
using namespace std;



igl::file_contents_as_string(file_name);

return

npe_end_code()


