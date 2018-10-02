#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/hessian.h>

const char* ds_hessian = R"igl_Qu8mg5v7(

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

 Constructs the finite element Hessian matrix
     as described in https:arxiv.org/abs/1707.04348,
     Natural Boundary Conditions for Smoothing in Geometry Processing
     (Oded Stein, Eitan Grinspun, Max Wardetzky, Alec Jacobson)
     The interior vertices are NOT set to zero yet.
    
     Inputs:
       V  #V by dim list of mesh vertex positions
       F  #F by 3 list of mesh faces (must be triangles)
     Outputs:
       H  #V by #V Hessian energy matrix, each column i
         corresponding to V(i,:)
    
    
    
)igl_Qu8mg5v7";

npe_function(hessian)
npe_doc(ds_hessian)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Sparse_f32 h;
    igl::hessian(v, f, h);
    return npe::move(h);
} else if (dtype.type() == npe::type_f64) {
    Sparse_f64 h;
    igl::hessian(v, f, h);
    return npe::move(h);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


