// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/orth.h>

const char* ds_orth = R"igl_Qu8mg5v7(

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

  ORTH   Orthogonalization.
       ORTH(A,Q) produces Q as an orthonormal basis for the range of A.
       That is, Q'*Q = I, the columns of Q span the same space as 
       the columns of A, and the number of columns of Q is the 
       rank of A.
    
    
     The algorithm  uses singular value decomposition, SVD, instead of orthogonal
     factorization, QR.  This doubles the computation time, but
     provides more reliable and consistent rank determination.
     Closely follows MATLAB implementation in orth.m
  
   Inputs:
     A  m by n matrix 
   Outputs:
     Q  m by n matrix with orthonormal columns spanning same column space as
       A
    
   Known bugs: Implementation listed as "Broken"
)igl_Qu8mg5v7";

npe_function(orth)
npe_doc(ds_orth)

npe_arg(a, Eigen::MatrixXd &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::MatrixXd & q;
    igl::orth(a, q);
    return npe::move(q);
} else if (dtype.type() == npe::type_f64) {
    Eigen::MatrixXd & q;
    igl::orth(a, q);
    return npe::move(q);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


