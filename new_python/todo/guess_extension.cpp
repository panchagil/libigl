// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/guess_extension.h>

const char* ds_guess_extension = R"igl_Qu8mg5v7(

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

 Given a file pointer at the beginning of a "mesh" file, try to guess the
   extension of the file format it comes from. The file pointer is rewound on
   return.
  
   Inputs:
     fp  file pointer (see output)
   Outputs:
     fp  file pointer rewound 
     guess  extension as string. One of "mesh",{"obj"},"off","ply","stl", or
       "wrl"
  
)igl_Qu8mg5v7";

npe_function(guess_extension)
npe_doc(ds_guess_extension)

npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    FILE * fp;
    std::string & guess;
    igl::guess_extension(fp, guess);
    return std::make_tuple(    npe::move(fp),
    npe::move(guess));
} else if (dtype.type() == npe::type_f64) {
    FILE * fp;
    std::string & guess;
    igl::guess_extension(fp, guess);
    return std::make_tuple(    npe::move(fp),     npe::move(guess));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/guess_extension.h>

const char* ds_guess_extension = R"igl_Qu8mg5v7(
See guess_extension for the documentation.
)igl_Qu8mg5v7";

npe_function(guess_extension)
npe_doc(ds_guess_extension)

npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    FILE * fp;
    igl::guess_extension(fp);
    return npe::move(fp);
} else if (dtype.type() == npe::type_f64) {
    FILE * fp;
    igl::guess_extension(fp);
    return npe::move(fp);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


