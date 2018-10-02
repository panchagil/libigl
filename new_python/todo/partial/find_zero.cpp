// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/find_zero.h>

const char* ds_find_zero = R"igl_Qu8mg5v7(

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

 Find the first zero (whether implicit or explicitly stored) in the
   rows/columns of a matrix.
   Inputs:
     A  m by n sparse matrix
     dim  dimension along which to check for any (1 or 2)
   Output:
     I  n-long vector (if dim == 1)  {m means no zeros found}
     or
     I  m-long vector (if dim == 2)  {n means no zeros found}
  
)igl_Qu8mg5v7";

npe_function(find_zero)
npe_doc(ds_find_zero)

npe_arg(a, Eigen::SparseMatrix<AType> &)
npe_arg(dim, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 i;
    igl::find_zero(a, dim, i);
    return npe::move(i);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 i;
    igl::find_zero(a, dim, i);
    return npe::move(i);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


