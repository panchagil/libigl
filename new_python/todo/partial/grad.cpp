// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/grad.h>

const char* ds_grad = R"igl_Qu8mg5v7(

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

 Gradient of a scalar function defined on piecewise linear elements (mesh)
   is constant on each triangle [tetrahedron] i,j,k:
   grad(Xijk) = (Xj-Xi) * (Vi - Vk)^R90 / 2A + (Xk-Xi) * (Vj - Vi)^R90 / 2A
   where Xi is the scalar value at vertex i, Vi is the 3D position of vertex
   i, and A is the area of triangle (i,j,k). ^R90 represent a rotation of
   90 degrees
  
)igl_Qu8mg5v7";

npe_function(grad)
npe_doc(ds_grad)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::SparseMatrix<typename DerivedV::Scalar> & g;
    bool uniform;
    igl::grad(v, f, g, uniform);
    return std::make_tuple(    npe::move(g),
    npe::move(uniform));
} else if (dtype.type() == npe::type_f64) {
    Eigen::SparseMatrix<typename DerivedV::Scalar> & g;
    bool uniform;
    igl::grad(v, f, g, uniform);
    return std::make_tuple(    npe::move(g),     npe::move(uniform));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


