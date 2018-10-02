#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/null.h>

const char* ds_null = R"igl_Qu8mg5v7(

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

 Like MATLAB's null
  
   Compute a basis for the null space for the given matrix A: the columns of
   the output N form a basis for the space orthogonal to that spanned by the
   rows of A.
  
   Inputs:
     A  m by n matrix
   Outputs:
     N  n by r matrix, where r is the row rank of A
)igl_Qu8mg5v7";

npe_function(null)
npe_doc(ds_null)

npe_arg(a, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 n;
    igl::null(a, n);
    return npe::move(n);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 n;
    igl::null(a, n);
    return npe::move(n);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


