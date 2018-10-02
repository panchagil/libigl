// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/find.h>

const char* ds_find = R"igl_Qu8mg5v7(

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

 Find the non-zero entries and there respective indices in a sparse matrix.
   Like matlab's [I,J,V] = find(X)
  
   Templates:
     T  should be a eigen sparse matrix primitive type like int or double
   Input:
     X  m by n matrix whose entries are to be found 
   Outputs:
     I  nnz vector of row indices of non zeros entries in X
     J  nnz vector of column indices of non zeros entries in X
     V  nnz vector of type T non-zeros entries in X
  
)igl_Qu8mg5v7";

npe_function(find)
npe_doc(ds_find)

npe_arg(x, Sparse_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::DenseBase<DerivedI> & i;
    Eigen::DenseBase<DerivedJ> & j;
    Eigen::DenseBase<DerivedV> & v;
    igl::find(x, i, j, v);
    return std::make_tuple(    npe::move(i),
    npe::move(j),
    npe::move(v));
} else if (dtype.type() == npe::type_f64) {
    Eigen::DenseBase<DerivedI> & i;
    Eigen::DenseBase<DerivedJ> & j;
    Eigen::DenseBase<DerivedV> & v;
    igl::find(x, i, j, v);
    return std::make_tuple(    npe::move(i),     npe::move(j),     npe::move(v));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/find.h>

const char* ds_find = R"igl_Qu8mg5v7(
See find for the documentation.
)igl_Qu8mg5v7";

npe_function(find)
npe_doc(ds_find)

npe_arg(x, Eigen::DenseBase<DerivedX> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 i;
    dense_f32 j;
    dense_f32 v;
    igl::find(x, i, j, v);
    return std::make_tuple(    npe::move(i),
    npe::move(j),
    npe::move(v));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 i;
    dense_f64 j;
    dense_f64 v;
    igl::find(x, i, j, v);
    return std::make_tuple(    npe::move(i),     npe::move(j),     npe::move(v));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/find.h>

const char* ds_find = R"igl_Qu8mg5v7(
See find for the documentation.
)igl_Qu8mg5v7";

npe_function(find)
npe_doc(ds_find)

npe_arg(x, Eigen::DenseBase<DerivedX> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 i;
    igl::find(x, i);
    return npe::move(i);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 i;
    igl::find(x, i);
    return npe::move(i);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/find.h>

const char* ds_find = R"igl_Qu8mg5v7(

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

 Find the non-zero entries and there respective indices in a sparse vector.
   Similar to matlab's [I,J,V] = find(X), but instead of [I,J] being
   subscripts into X, since X is a vector we just return I, a list of indices
   into X
  
   Templates:
     T  should be a eigen sparse matrix primitive type like int or double
   Input:
     X  vector whose entries are to be found
   Outputs:
     I  nnz vector of indices of non zeros entries in X
     V  nnz vector of type T non-zeros entries in X
)igl_Qu8mg5v7";

npe_function(find)
npe_doc(ds_find)

npe_arg(x, Sparse_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::Matrix<int, Eigen::Dynamic, 1> & i;
    Eigen::Matrix<T, Eigen::Dynamic, 1> & v;
    igl::find(x, i, v);
    return std::make_tuple(    npe::move(i),
    npe::move(v));
} else if (dtype.type() == npe::type_f64) {
    Eigen::Matrix<int, Eigen::Dynamic, 1> & i;
    Eigen::Matrix<T, Eigen::Dynamic, 1> & v;
    igl::find(x, i, v);
    return std::make_tuple(    npe::move(i),     npe::move(v));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


