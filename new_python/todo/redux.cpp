// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/redux.h>

const char* ds_redux = R"igl_Qu8mg5v7(

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

 REDUX Perform reductions on the rows or columns of a SparseMatrix. This is
   _similar_ to DenseBase::redux, but different in two important ways:
    1. (unstored) Zeros are **not** "visited", however if the first element
       in the column/row  does not appear in the first row/column then the
       reduction is assumed to start with zero. In this way, "any", "all",
       "count"(non-zeros) work as expected. This means it is **not** possible
       to use this to count (implicit) zeros.
    2. This redux is more powerful in the sense that A and B may have
       different types. This makes it possible to count the number of
       non-zeros in a SparseMatrix<bool> A into a VectorXi B.
  
   Inputs:
     A  m by n sparse matrix
     dim  dimension along which to sum (1 or 2)
     func  function handle with the prototype `X(Y a, I i, J j, Z b)` where a
       is the running value, b is A(i,j)
   Output:
     S  n-long sparse vector (if dim == 1) 
     or
     S  m-long sparse vector (if dim == 2)
)igl_Qu8mg5v7";

npe_function(redux)
npe_doc(ds_redux)

npe_arg(a, Eigen::SparseMatrix<AType> &)
npe_arg(dim, int)
npe_arg(func, Func &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 b;
    igl::redux(a, dim, func, b);
    return npe::move(b);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 b;
    igl::redux(a, dim, func, b);
    return npe::move(b);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/redux.h>

const char* ds_redux = R"igl_Qu8mg5v7(

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

 REDUX Perform reductions on the rows or columns of a SparseMatrix. This is
   _similar_ to DenseBase::redux, but different in two important ways:
    1. (unstored) Zeros are **not** "visited", however if the first element
       in the column/row  does not appear in the first row/column then the
       reduction is assumed to start with zero. In this way, "any", "all",
       "count"(non-zeros) work as expected. This means it is **not** possible
       to use this to count (implicit) zeros.
    2. This redux is more powerful in the sense that A and B may have
       different types. This makes it possible to count the number of
       non-zeros in a SparseMatrix<bool> A into a VectorXi B.
  
   Inputs:
     A  m by n sparse matrix
     dim  dimension along which to sum (1 or 2)
     func  function handle with the prototype `X(Y a, I i, J j, Z b)` where a
       is the running value, b is A(i,j)
   Output:
     S  n-long sparse vector (if dim == 1) 
     or
     S  m-long sparse vector (if dim == 2)
)igl_Qu8mg5v7";

npe_function(redux)
npe_doc(ds_redux)

npe_arg(a, Eigen::SparseMatrix<AType> &)
npe_arg(dim, int)
npe_arg(func, Func &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 b;
    igl::redux(a, dim, func, b);
    return npe::move(b);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 b;
    igl::redux(a, dim, func, b);
    return npe::move(b);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


