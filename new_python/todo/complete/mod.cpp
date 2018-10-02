#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/mod.h>

const char* ds_mod = R"igl_Qu8mg5v7(

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

 Compute elementwise mod: B = A % base
  
   Inputs:
      A  m by n matrix
      base  number to mod against
   Outputs:
      B  m by n matrix
)igl_Qu8mg5v7";

npe_function(mod)
npe_doc(ds_mod)

npe_arg(a, dense_f64)
npe_arg(base, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 b;
    igl::mod(a, base, b);
    return npe::move(b);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 b;
    igl::mod(a, base, b);
    return npe::move(b);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/mod.h>

const char* ds_mod = R"igl_Qu8mg5v7(
See mod for the documentation.
)igl_Qu8mg5v7";

npe_function(mod)
npe_doc(ds_mod)

npe_arg(a, dense_f64)
npe_arg(base, int)



npe_begin_code()
using namespace std;



igl::mod(a, base);

return

npe_end_code()


