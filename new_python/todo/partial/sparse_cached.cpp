// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/sparse_cached_precompute.h>

const char* ds_sparse_cached_precompute = R"igl_Qu8mg5v7(

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

 Build a sparse matrix from list of indices and values (I,J,V), similarly to 
   the sparse function in matlab. Divides the construction in two phases, one
   for fixing the sparsity pattern, and one to populate it with values. Compared to
   igl::sparse, this version is slower for the first time (since it requires a
   precomputation), but faster to the subsequent evaluations.
  
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
  
   Example:
     Eigen::SparseMatrix<double> A;
     std::vector<Eigen::Triplet<double> > IJV;
     buildA(IJV);
     if (A.rows() == 0)
     {
       A = Eigen::SparseMatrix<double>(rows,cols);
       igl::sparse_cached_precompute(IJV,A,A_data);
     }
     else
       igl::sparse_cached(IJV,s.A,s.A_data);
)igl_Qu8mg5v7";

npe_function(sparse_cached_precompute)
npe_doc(ds_sparse_cached_precompute)

npe_arg(i, dense_f64)
npe_arg(j, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::VectorXi & data;
    Sparse_f32 x;
    igl::sparse_cached_precompute(i, j, data, x);
    return std::make_tuple(    npe::move(data),
    npe::move(x));
} else if (dtype.type() == npe::type_f64) {
    Eigen::VectorXi & data;
    Sparse_f64 x;
    igl::sparse_cached_precompute(i, j, data, x);
    return std::make_tuple(    npe::move(data),     npe::move(x));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/sparse_cached_precompute.h>

const char* ds_sparse_cached_precompute = R"igl_Qu8mg5v7(
See sparse_cached_precompute for the documentation.
)igl_Qu8mg5v7";

npe_function(sparse_cached_precompute)
npe_doc(ds_sparse_cached_precompute)

npe_arg(triplets, std::vector<Eigen::Triplet<Scalar> > &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::VectorXi & data;
    Sparse_f32 x;
    igl::sparse_cached_precompute(triplets, data, x);
    return std::make_tuple(    npe::move(data),
    npe::move(x));
} else if (dtype.type() == npe::type_f64) {
    Eigen::VectorXi & data;
    Sparse_f64 x;
    igl::sparse_cached_precompute(triplets, data, x);
    return std::make_tuple(    npe::move(data),     npe::move(x));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/sparse_cached.h>

const char* ds_sparse_cached = R"igl_Qu8mg5v7(
See sparse_cached for the documentation.
)igl_Qu8mg5v7";

npe_function(sparse_cached)
npe_doc(ds_sparse_cached)

npe_arg(triplets, std::vector<Eigen::Triplet<Scalar> > &)
npe_arg(data, Eigen::VectorXi &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Sparse_f32 x;
    igl::sparse_cached(triplets, data, x);
    return npe::move(x);
} else if (dtype.type() == npe::type_f64) {
    Sparse_f64 x;
    igl::sparse_cached(triplets, data, x);
    return npe::move(x);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/sparse_cached.h>

const char* ds_sparse_cached = R"igl_Qu8mg5v7(
See sparse_cached for the documentation.
)igl_Qu8mg5v7";

npe_function(sparse_cached)
npe_doc(ds_sparse_cached)

npe_arg(v, dense_f64)
npe_arg(data, Eigen::VectorXi &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Sparse_f32 x;
    igl::sparse_cached(v, data, x);
    return npe::move(x);
} else if (dtype.type() == npe::type_f64) {
    Sparse_f64 x;
    igl::sparse_cached(v, data, x);
    return npe::move(x);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


