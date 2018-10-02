#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/adjacency_matrix.h>

const char* ds_adjacency_matrix = R"igl_Qu8mg5v7(

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

 Constructs the graph adjacency matrix  of a given mesh (V,F)
   Templates:
     T  should be a eigen sparse matrix primitive type like int or double
   Inputs:
     F  #F by dim list of mesh simplices
   Outputs: 
     A  max(F) by max(F) cotangent matrix, each row i corresponding to V(i,:)
  
   Example:
      Mesh in (V,F)
     Eigen::SparseMatrix<double> A;
     adjacency_matrix(F,A);
      sum each row 
     SparseVector<double> Asum;
     sum(A,1,Asum);
      Convert row sums into diagonal of sparse matrix
     SparseMatrix<double> Adiag;
     diag(Asum,Adiag);
      Build uniform laplacian
     SparseMatrix<double> U;
     U = A-Adiag;
  
   See also: edges, cotmatrix, diag
)igl_Qu8mg5v7";

npe_function(adjacency_matrix)
npe_doc(ds_adjacency_matrix)

npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Sparse_f32 a;
    igl::adjacency_matrix(f, a);
    return npe::move(a);
} else if (dtype.type() == npe::type_f64) {
    Sparse_f64 a;
    igl::adjacency_matrix(f, a);
    return npe::move(a);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


