// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/colon.h>

const char* ds_colon = R"igl_Qu8mg5v7(

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

 Colon operator like matlab's colon operator. Enumerats values between low
   and hi with step step.
   Templates:
     L  should be a eigen matrix primitive type like int or double
     S  should be a eigen matrix primitive type like int or double
     H  should be a eigen matrix primitive type like int or double
     T  should be a eigen matrix primitive type like int or double
   Inputs:
     low  starting value if step is valid then this is *always* the first
       element of I
     step  step difference between sequential elements returned in I,
       remember this will be cast to template T at compile time. If low<hi
       then step must be positive. If low>hi then step must be negative.
       Otherwise I will be set to empty.
     hi  ending value, if (hi-low)%step is zero then this will be the last
       element in I. If step is positive there will be no elements greater
       than hi, vice versa if hi<low
   Output:
     I  list of values from low to hi with step size step
)igl_Qu8mg5v7";

npe_function(colon)
npe_doc(ds_colon)

npe_arg(low, L)
npe_arg(step, S)
npe_arg(hi, H)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::Matrix<T, Eigen::Dynamic, 1> & i;
    igl::colon(low, step, hi, i);
    return npe::move(i);
} else if (dtype.type() == npe::type_f64) {
    Eigen::Matrix<T, Eigen::Dynamic, 1> & i;
    igl::colon(low, step, hi, i);
    return npe::move(i);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/colon.h>

const char* ds_colon = R"igl_Qu8mg5v7(

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

 Same as above but step == (T)1
)igl_Qu8mg5v7";

npe_function(colon)
npe_doc(ds_colon)

npe_arg(low, L)
npe_arg(hi, H)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::Matrix<T, Eigen::Dynamic, 1> & i;
    igl::colon(low, hi, i);
    return npe::move(i);
} else if (dtype.type() == npe::type_f64) {
    Eigen::Matrix<T, Eigen::Dynamic, 1> & i;
    igl::colon(low, hi, i);
    return npe::move(i);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/colon.h>

const char* ds_colon = R"igl_Qu8mg5v7(

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

 Return output rather than set in reference
)igl_Qu8mg5v7";

npe_function(colon)
npe_doc(ds_colon)

npe_arg(low, L)
npe_arg(hi, H)



npe_begin_code()
using namespace std;



igl::colon(low, hi);

return

npe_end_code()


