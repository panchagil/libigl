// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/planarize_quad_mesh.h>

const char* ds_planarize_quad_mesh = R"igl_Qu8mg5v7(

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

 Inputs:
     Vin        #V by 3 eigen Matrix of mesh vertex 3D positions
     F          #F by 4 eigen Matrix of face (quad) indices
     maxIter    maximum numbers of iterations
     threshold  minimum allowed threshold for non-planarity
   Output:
     Vout       #V by 3 eigen Matrix of planar mesh vertex 3D positions
  
)igl_Qu8mg5v7";

npe_function(planarize_quad_mesh)
npe_doc(ds_planarize_quad_mesh)

npe_arg(vin, dense_f64)
npe_arg(f, dense_i32)
npe_arg(max_iter, int)
npe_arg(threshold, double &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 vout;
    igl::planarize_quad_mesh(vin, f, max_iter, threshold, vout);
    return npe::move(vout);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 vout;
    igl::planarize_quad_mesh(vin, f, max_iter, threshold, vout);
    return npe::move(vout);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


