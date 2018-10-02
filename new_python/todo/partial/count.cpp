// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/count.h>

const char* ds_count = R"igl_Qu8mg5v7(

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

 Count the number of non-zeros in the columns or rows of a sparse matrix
  
   Inputs:
     X  m by n sparse matrix
     dim  dimension along which to sum (1 or 2)
   Output:
     S  n-long sparse vector (if dim == 1) 
     or
     S  m-long sparse vector (if dim == 2)
)igl_Qu8mg5v7";

npe_function(count)
npe_doc(ds_count)

npe_arg(x, Eigen::SparseMatrix<XType> &)
npe_arg(dim, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::SparseVector<SType> & s;
    igl::count(x, dim, s);
    return npe::move(s);
} else if (dtype.type() == npe::type_f64) {
    Eigen::SparseVector<SType> & s;
    igl::count(x, dim, s);
    return npe::move(s);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/count.h>

const char* ds_count = R"igl_Qu8mg5v7(
See count for the documentation.
)igl_Qu8mg5v7";

npe_function(count)
npe_doc(ds_count)

npe_arg(x, Eigen::SparseMatrix<XType> &)
npe_arg(dim, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 s;
    igl::count(x, dim, s);
    return npe::move(s);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 s;
    igl::count(x, dim, s);
    return npe::move(s);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


