#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/dihedral_angles.h>

const char* ds_dihedral_angles = R"igl_Qu8mg5v7(

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

 DIHEDRAL_ANGLES Compute dihedral angles for all tets of a given tet mesh
   (V,T)
  
   theta = dihedral_angles(V,T)
   theta = dihedral_angles(V,T,'ParameterName',parameter_value,...)
  
   Inputs:
     V  #V by dim list of vertex positions
     T  #V by 4 list of tet indices
   Outputs:
     theta  #T by 6 list of dihedral angles (in radians)
     cos_theta  #T by 6 list of cosine of dihedral angles (in radians)
  
)igl_Qu8mg5v7";

npe_function(dihedral_angles)
npe_doc(ds_dihedral_angles)

npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v;
    dense_f32 t;
    dense_f32 theta;
    dense_f32 cos_theta;
    igl::dihedral_angles(v, t, theta, cos_theta);
    return std::make_tuple(    npe::move(v),
    npe::move(t),
    npe::move(theta),
    npe::move(cos_theta));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v;
    dense_f64 t;
    dense_f64 theta;
    dense_f64 cos_theta;
    igl::dihedral_angles(v, t, theta, cos_theta);
    return std::make_tuple(    npe::move(v),     npe::move(t),     npe::move(theta),     npe::move(cos_theta));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/dihedral_angles_intrinsic.h>

const char* ds_dihedral_angles_intrinsic = R"igl_Qu8mg5v7(
See dihedral_angles_intrinsic for the documentation.
)igl_Qu8mg5v7";

npe_function(dihedral_angles_intrinsic)
npe_doc(ds_dihedral_angles_intrinsic)

npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 l;
    dense_f32 a;
    dense_f32 theta;
    dense_f32 cos_theta;
    igl::dihedral_angles_intrinsic(l, a, theta, cos_theta);
    return std::make_tuple(    npe::move(l),
    npe::move(a),
    npe::move(theta),
    npe::move(cos_theta));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 l;
    dense_f64 a;
    dense_f64 theta;
    dense_f64 cos_theta;
    igl::dihedral_angles_intrinsic(l, a, theta, cos_theta);
    return std::make_tuple(    npe::move(l),     npe::move(a),     npe::move(theta),     npe::move(cos_theta));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


