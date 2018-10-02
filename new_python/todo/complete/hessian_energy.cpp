#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/hessian_energy.h>

const char* ds_hessian_energy = R"igl_Qu8mg5v7(

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

 Constructs the Hessian energy matrix using mixed FEM
     as described in https:arxiv.org/abs/1707.04348
     Natural Boundary Conditions for Smoothing in Geometry Processing
     (Oded Stein, Eitan Grinspun, Max Wardetzky, Alec Jacobson)
    
     Inputs:
       V  #V by dim list of mesh vertex positions
       F  #F by 3 list of mesh faces (must be triangles)
     Outputs:
       Q  #V by #V Hessian energy matrix, each row/column i
         corresponding to V(i,:)
    
    
    
)igl_Qu8mg5v7";

npe_function(hessian_energy)
npe_doc(ds_hessian_energy)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Sparse_f32 q;
    igl::hessian_energy(v, f, q);
    return npe::move(q);
} else if (dtype.type() == npe::type_f64) {
    Sparse_f64 q;
    igl::hessian_energy(v, f, q);
    return npe::move(q);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


