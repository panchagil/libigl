// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/bone_heat.h>

const char* ds_bone_heat = R"igl_Qu8mg5v7(

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

 BONE_HEAT  Compute skinning weights W given a surface mesh (V,F) and an
     internal skeleton (C,BE) according to "Automatic Rigging" [Baran and
     Popovic 2007].
    
     Inputs:
       V  #V by 3 list of mesh vertex positions
       F  #F by 3 list of mesh corner indices into V
       C  #C by 3 list of joint locations
       P  #P list of point handle indices into C
       BE  #BE by 2 list of bone edge indices into C
       CE  #CE by 2 list of cage edge indices into **P**
     Outputs:
       W  #V by #P+#BE matrix of weights.
     Returns true only on success.
    
)igl_Qu8mg5v7";

npe_function(bone_heat)
npe_doc(ds_bone_heat)

npe_arg(v, Eigen::MatrixXd &)
npe_arg(f, Eigen::MatrixXi &)
npe_arg(c, Eigen::MatrixXd &)
npe_arg(p, Eigen::VectorXi &)
npe_arg(be, Eigen::MatrixXi &)
npe_arg(ce, Eigen::MatrixXi &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::MatrixXd & w;
    igl::    embree::bone_heat(v, f, c, p, be, ce, w);
    return npe::move(w);
} else if (dtype.type() == npe::type_f64) {
    Eigen::MatrixXd & w;
    igl::    embree::bone_heat(v, f, c, p, be, ce, w);
    return npe::move(w);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


