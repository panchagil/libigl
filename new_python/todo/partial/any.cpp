// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/any.h>

const char* ds_any = R"igl_Qu8mg5v7(

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

 For Dense matrices use: A.rowwise().any() or A.colwise().any()
  
   Inputs:
     A  m by n sparse matrix
     dim  dimension along which to check for any (1 or 2)
   Output:
     B  n-long vector (if dim == 1) 
     or
     B  m-long vector (if dim == 2)
  
)igl_Qu8mg5v7";

npe_function(any)
npe_doc(ds_any)

npe_arg(a, Eigen::SparseMatrix<AType> &)
npe_arg(dim, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 b;
    igl::any(a, dim, b);
    return npe::move(b);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 b;
    igl::any(a, dim, b);
    return npe::move(b);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


