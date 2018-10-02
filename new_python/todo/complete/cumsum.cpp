#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/cumsum.h>

const char* ds_cumsum = R"igl_Qu8mg5v7(

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

 Computes a cumulative sum of the columns of X, like matlab's `cumsum`.
  
   Templates:
     DerivedX  Type of matrix X
     DerivedY  Type of matrix Y
   Inputs:
     X  m by n Matrix to be cumulatively summed.
     dim  dimension to take cumulative sum (1 or 2)
   Output:
     Y  m by n Matrix containing cumulative sum.
  
)igl_Qu8mg5v7";

npe_function(cumsum)
npe_doc(ds_cumsum)

npe_arg(x, dense_f64)
npe_arg(dim, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 y;
    igl::cumsum(x, dim, y);
    return npe::move(y);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 y;
    igl::cumsum(x, dim, y);
    return npe::move(y);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


