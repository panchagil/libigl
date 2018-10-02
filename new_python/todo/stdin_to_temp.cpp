// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/stdin_to_temp.h>

const char* ds_stdin_to_temp = R"igl_Qu8mg5v7(

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

 Write stdin/piped input to a temporary file which can than be preprocessed as it
   is (a normal file). This is often useful if you want to process stdin/piped
   with library functions that expect to be able to fseek(), rewind() etc..
  
   If your application is not using fseek(), rewind(), etc. but just reading
   from stdin then this will likely cause a bottle neck as it defeats the whole
   purpose of piping.
  
   Outputs:
     temp_file  pointer to temp file pointer, rewound to beginning of file so
       its ready to be read
   Return true only if no errors were found
  
   Note: Caller is responsible for closing the file (tmpfile() automatically
   unlinks the file so there is no need to remove/delete/unlink the file)
)igl_Qu8mg5v7";

npe_function(stdin_to_temp)
npe_doc(ds_stdin_to_temp)

npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    FILE ** temp_file;
    igl::stdin_to_temp(temp_file);
    return npe::move(temp_file);
} else if (dtype.type() == npe::type_f64) {
    FILE ** temp_file;
    igl::stdin_to_temp(temp_file);
    return npe::move(temp_file);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


