// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/sum.h>

const char* ds_sum = R"igl_Qu8mg5v7(

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

 Sum the columns or rows of a sparse matrix
   Templates:
     T  should be a eigen sparse matrix primitive type like int or double
   Inputs:
     X  m by n sparse matrix
     dim  dimension along which to sum (1 or 2)
   Output:
     S  n-long sparse vector (if dim == 1) 
     or
     S  m-long sparse vector (if dim == 2)
)igl_Qu8mg5v7";

npe_function(sum)
npe_doc(ds_sum)

npe_arg(x, Sparse_f64)
npe_arg(dim, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Sparse_f32 s;
    igl::sum(x, dim, s);
    return npe::move(s);
} else if (dtype.type() == npe::type_f64) {
    Sparse_f64 s;
    igl::sum(x, dim, s);
    return npe::move(s);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/sum.h>

const char* ds_sum = R"igl_Qu8mg5v7(

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

 Sum is "conducted" in the type of DerivedB::Scalar 
)igl_Qu8mg5v7";

npe_function(sum)
npe_doc(ds_sum)

npe_arg(a, Eigen::SparseMatrix<AType> &)
npe_arg(dim, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 b;
    igl::sum(a, dim, b);
    return npe::move(b);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 b;
    igl::sum(a, dim, b);
    return npe::move(b);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


