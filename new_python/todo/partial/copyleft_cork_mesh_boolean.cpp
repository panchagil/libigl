// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/mesh_boolean.h>

const char* ds_mesh_boolean = R"igl_Qu8mg5v7(

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

 Compute a boolean operation on two input meshes using the cork library.
      
       Inputs:
         VA  #VA by 3 list of vertex positions of first mesh
         FA  #FA by 3 list of triangle indices into VA
         VB  #VB by 3 list of vertex positions of second mesh
         FB  #FB by 3 list of triangle indices into VB
         type  of boolean operation see MeshBooleanType.h
       Outputs:
         VC  #VC by 3 list of vertex positions of output mesh
         FC  #FC by 3 list of triangle indices into VC
)igl_Qu8mg5v7";

npe_function(mesh_boolean)
npe_doc(ds_mesh_boolean)

npe_arg(va, dense_f64)
npe_arg(fa, dense_f64)
npe_arg(vb, dense_f64)
npe_arg(fb, dense_f64)
npe_arg(type, igl::MeshBooleanType &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 vc;
    dense_f32 fc;
    igl::    copyleft::    cork::mesh_boolean(va, fa, vb, fb, type, vc, fc);
    return std::make_tuple(    npe::move(vc),
    npe::move(fc));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 vc;
    dense_f64 fc;
    igl::    copyleft::    cork::mesh_boolean(va, fa, vb, fb, type, vc, fc);
    return std::make_tuple(    npe::move(vc),     npe::move(fc));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


