// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/mexErrMsgTxt.h>

const char* ds_mex_err_msg_txt = R"igl_Qu8mg5v7(

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

 Wrapper for mexErrMsgTxt that only calls error if test fails
)igl_Qu8mg5v7";

npe_function(mex_err_msg_txt)
npe_doc(ds_mex_err_msg_txt)

npe_arg(message, char *)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    bool test;
    igl::    matlab::mexErrMsgTxt(message, test);
    return npe::move(test);
} else if (dtype.type() == npe::type_f64) {
    bool test;
    igl::    matlab::mexErrMsgTxt(message, test);
    return npe::move(test);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


