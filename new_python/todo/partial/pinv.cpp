// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/pinv.h>

const char* ds_pinv = R"igl_Qu8mg5v7(

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

 Wrapper using default tol
)igl_Qu8mg5v7";

npe_function(pinv)
npe_doc(ds_pinv)

npe_arg(a, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 x;
    igl::pinv(a, x);
    return npe::move(x);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 x;
    igl::pinv(a, x);
    return npe::move(x);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/pinv.h>

const char* ds_pinv = R"igl_Qu8mg5v7(

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

 Compute the Moore-Penrose pseudoinverse
  
   Inputs:
     A  m by n matrix 
     tol  tolerance (if negative then default is used)
   Outputs:
     X  n by m matrix so that A*X*A = A and X*A*X = X and A*X = (A*X)' and
       (X*A) = (X*A)'
)igl_Qu8mg5v7";

npe_function(pinv)
npe_doc(ds_pinv)

npe_arg(a, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    typename DerivedA::Scalar tol;
    dense_f32 x;
    igl::pinv(a, tol, x);
    return std::make_tuple(    npe::move(tol),
    npe::move(x));
} else if (dtype.type() == npe::type_f64) {
    typename DerivedA::Scalar tol;
    dense_f64 x;
    igl::pinv(a, tol, x);
    return std::make_tuple(    npe::move(tol),     npe::move(x));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


