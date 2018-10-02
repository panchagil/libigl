// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/min.h>

const char* ds_min = R"igl_Qu8mg5v7(

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

 Inputs:
     X  m by n matrix
     dim  dimension along which to take min
   Outputs:
     Y  n-long vector (if dim == 1) 
     or
     Y  m-long vector (if dim == 2)
     I  vector the same size as Y containing the indices along dim of minimum
       entries
)igl_Qu8mg5v7";

npe_function(min)
npe_doc(ds_min)

npe_arg(a, Eigen::SparseMatrix<AType> &)
npe_arg(dim, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 b;
    dense_f32 i;
    igl::min(a, dim, b, i);
    return std::make_tuple(    npe::move(b),
    npe::move(i));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 b;
    dense_f64 i;
    igl::min(a, dim, b, i);
    return std::make_tuple(    npe::move(b),     npe::move(i));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


