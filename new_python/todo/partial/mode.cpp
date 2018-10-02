// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/mode.h>

const char* ds_mode = R"igl_Qu8mg5v7(

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

 Takes mode of coefficients in a matrix along a given dension
  
   Templates:
     T  should be a eigen matrix primitive type like int or double
   Inputs:
     X  m by n original matrix
     d  dension along which to take mode, m or n
   Outputs:
     M  vector containing mode along dension d, if d==1 then this will be a
       n-long vector if d==2 then this will be a m-long vector
)igl_Qu8mg5v7";

npe_function(mode)
npe_doc(ds_mode)

npe_arg(x, Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> &)
npe_arg(d, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::Matrix<T, Eigen::Dynamic, 1> & m;
    igl::mode(x, d, m);
    return npe::move(m);
} else if (dtype.type() == npe::type_f64) {
    Eigen::Matrix<T, Eigen::Dynamic, 1> & m;
    igl::mode(x, d, m);
    return npe::move(m);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


