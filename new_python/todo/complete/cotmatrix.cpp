#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/cotmatrix.h>

const char* ds_cotmatrix = R"igl_Qu8mg5v7(

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

 Constructs the cotangent stiffness matrix (discrete laplacian) for a given
   mesh (V,F).
  
   Templates:
     DerivedV  derived type of eigen matrix for V (e.g. derived from
       MatrixXd)
     DerivedF  derived type of eigen matrix for F (e.g. derived from
       MatrixXi)
     Scalar  scalar type for eigen sparse matrix (e.g. double)
   Inputs:
     V  #V by dim list of mesh vertex positions
     F  #F by simplex_size list of mesh faces (must be triangles)
   Outputs: 
     L  #V by #V cotangent matrix, each row i corresponding to V(i,:)
  
   See also: adjacency_matrix
  
   Note: This Laplacian uses the convention that diagonal entries are
   **minus** the sum of off-diagonal entries. The diagonal entries are
   therefore in general negative and the matrix is **negative** semi-definite
   (immediately, -L is **positive** semi-definite)
  
)igl_Qu8mg5v7";

npe_function(cotmatrix)
npe_doc(ds_cotmatrix)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Sparse_f32 l;
    igl::cotmatrix(v, f, l);
    return npe::move(l);
} else if (dtype.type() == npe::type_f64) {
    Sparse_f64 l;
    igl::cotmatrix(v, f, l);
    return npe::move(l);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


