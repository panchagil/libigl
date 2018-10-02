// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/next_filename.h>

const char* ds_next_filename = R"igl_Qu8mg5v7(

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

 Find the file with the first filename of the form
   "prefix%0[zeros]dsuffix"
   
   Inputs:
     prefix  path to containing dir and filename prefix
     zeros number of leading zeros as if digit printed with printf
     suffix  suffix of filename and extension (should included dot)
   Outputs:
     next  path to next file
   Returns true if found, false if exceeding range in zeros
)igl_Qu8mg5v7";

npe_function(next_filename)
npe_doc(ds_next_filename)

npe_arg(prefix, std::string &)
npe_arg(zeros, int)
npe_arg(suffix, std::string &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::string & next;
    igl::next_filename(prefix, zeros, suffix, next);
    return npe::move(next);
} else if (dtype.type() == npe::type_f64) {
    std::string & next;
    igl::next_filename(prefix, zeros, suffix, next);
    return npe::move(next);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


