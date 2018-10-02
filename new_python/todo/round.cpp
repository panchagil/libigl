// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/round.h>

const char* ds_round = R"igl_Qu8mg5v7(

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

 Round a given matrix to nearest integers
  
   Inputs:
     X  m by n matrix of scalars
   Outputs:
     Y  m by n matrix of rounded integers
)igl_Qu8mg5v7";

npe_function(round)
npe_doc(ds_round)

npe_arg(x, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 y;
    igl::round(x, y);
    return npe::move(y);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 y;
    igl::round(x, y);
    return npe::move(y);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/round.h>

const char* ds_round = R"igl_Qu8mg5v7(

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

 Round a scalar value
  
   Inputs:
     x  number
   Returns x rounded to integer
)igl_Qu8mg5v7";

npe_function(round)
npe_doc(ds_round)

npe_arg(r, DerivedX)



npe_begin_code()
using namespace std;



igl::round(r);

return

npe_end_code()


