#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/massmatrix.h>

const char* ds_massmatrix = R"igl_Qu8mg5v7(

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

 Constructs the mass (area) matrix for a given mesh (V,F).
  
   Templates:
     DerivedV  derived type of eigen matrix for V (e.g. derived from
       MatrixXd)
     DerivedF  derived type of eigen matrix for F (e.g. derived from
       MatrixXi)
     Scalar  scalar type for eigen sparse matrix (e.g. double)
   Inputs:
     V  #V by dim list of mesh vertex positions
     F  #F by simplex_size list of mesh faces (must be triangles)
     type  one of the following ints:
       MASSMATRIX_TYPE_BARYCENTRIC  barycentric
       MASSMATRIX_TYPE_VORONOI voronoi-hybrid {default}
       MASSMATRIX_TYPE_FULL full {not implemented}
   Outputs: 
     M  #V by #V mass matrix
  
   See also: adjacency_matrix
  
)igl_Qu8mg5v7";

npe_function(massmatrix)
npe_doc(ds_massmatrix)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(type, igl::MassMatrixType)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Sparse_f32 m;
    igl::massmatrix(v, f, type, m);
    return npe::move(m);
} else if (dtype.type() == npe::type_f64) {
    Sparse_f64 m;
    igl::massmatrix(v, f, type, m);
    return npe::move(m);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


