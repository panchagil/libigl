#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/randperm.h>

const char* ds_randperm = R"igl_Qu8mg5v7(

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

 Like matlab's randperm(n) but minus 1
  
   Inputs:
     n  number of elements
   Outputs:
     I  n list of rand permutation of 0:n-1
)igl_Qu8mg5v7";

npe_function(randperm)
npe_doc(ds_randperm)

npe_arg(n, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 i;
    igl::randperm(n, i);
    return npe::move(i);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 i;
    igl::randperm(n, i);
    return npe::move(i);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


