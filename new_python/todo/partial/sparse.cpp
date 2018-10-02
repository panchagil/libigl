// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/sparse.h>

const char* ds_sparse = R"igl_Qu8mg5v7(

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

 THIS MAY BE SUPERSEDED BY EIGEN'S .sparseView Indeed it is.
   Convert a full, dense matrix to a sparse one
  
   Templates:
     T  should be a eigen sparse matrix primitive type like int or double
   Input:
     D  m by n full, dense matrix
   Output:
     X  m by n sparse matrix
)igl_Qu8mg5v7";

npe_function(sparse)
npe_doc(ds_sparse)

npe_arg(d, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Sparse_f32 x;
    igl::sparse(d, x);
    return npe::move(x);
} else if (dtype.type() == npe::type_f64) {
    Sparse_f64 x;
    igl::sparse(d, x);
    return npe::move(x);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/sparse.h>

const char* ds_sparse = R"igl_Qu8mg5v7(

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

 Wrapper with return
)igl_Qu8mg5v7";

npe_function(sparse)
npe_doc(ds_sparse)

npe_arg(d, dense_f64)



npe_begin_code()
using namespace std;



igl::sparse(d);

return

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/sparse.h>

const char* ds_sparse = R"igl_Qu8mg5v7(

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

 Build a sparse matrix from list of indices and values (I,J,V), functions
   like the sparse function in matlab
  
   Templates:
     IndexVector  list of indices, value should be non-negative and should
       expect to be cast to an index. Must implement operator(i) to retrieve
       ith element
     ValueVector  list of values, value should be expect to be cast to type
       T. Must implement operator(i) to retrieve ith element
     T  should be a eigen sparse matrix primitive type like int or double
   Input:
     I  nnz vector of row indices of non zeros entries in X
     J  nnz vector of column indices of non zeros entries in X
     V  nnz vector of non-zeros entries in X
     Optional:
       m  number of rows
       n  number of cols
   Outputs:
     X  m by n matrix of type T whose entries are to be found 
  
)igl_Qu8mg5v7";

npe_function(sparse)
npe_doc(ds_sparse)

npe_arg(i, IndexVector &)
npe_arg(j, IndexVector &)
npe_arg(v, ValueVector &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Sparse_f32 x;
    igl::sparse(i, j, v, x);
    return npe::move(x);
} else if (dtype.type() == npe::type_f64) {
    Sparse_f64 x;
    igl::sparse(i, j, v, x);
    return npe::move(x);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/sparse.h>

const char* ds_sparse = R"igl_Qu8mg5v7(
See sparse for the documentation.
)igl_Qu8mg5v7";

npe_function(sparse)
npe_doc(ds_sparse)

npe_arg(i, IndexVectorI &)
npe_arg(j, IndexVectorJ &)
npe_arg(v, ValueVector &)
npe_arg(m, size_t)
npe_arg(n, size_t)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Sparse_f32 x;
    igl::sparse(i, j, v, m, n, x);
    return npe::move(x);
} else if (dtype.type() == npe::type_f64) {
    Sparse_f64 x;
    igl::sparse(i, j, v, m, n, x);
    return npe::move(x);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


