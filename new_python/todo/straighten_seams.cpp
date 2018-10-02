// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/straighten_seams.h>

const char* ds_straighten_seams = R"igl_Qu8mg5v7(

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

 STRAIGHTEN_SEAMS Given a obj-style mesh with (V,F) defining the geometric
   surface of the mesh and (VT,FT) defining the
   parameterization/texture-mapping of the mesh in the uv-domain, find all
   seams and boundaries in the texture-mapping and "straighten" them,
   remapping vertices along the boundary and in the interior. This will be
   careful to consistently straighten multiple seams in the texture-mesh
   corresponding to the same edge chains in the surface-mesh. 
  
   [UT] = straighten_seams(V,F,VT,FT)
  
   Inputs:
    V  #V by 3 list of vertices
    F  #F by 3 list of triangle indices
    VT  #VT by 2 list of texture coordinates
    FT  #F by 3 list of triangle texture coordinates
    Optional:
      'Tol'  followed by Ramer-Douglas-Peucker tolerance as a fraction of the
        curves bounding box diagonal (see dpsimplify)
   Outputs:
     UE  #UE by 2 list of indices into VT of coarse output polygon edges
     UT  #VT by 3 list of new texture coordinates
     OT  #OT by 2 list of indices into VT of boundary edges 
  
   See also: simplify_curve, dpsimplify
)igl_Qu8mg5v7";

npe_function(straighten_seams)
npe_doc(ds_straighten_seams)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(vt, dense_f64)
npe_arg(ft, dense_f64)
npe_arg(tol, Scalar)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 ue;
    dense_f32 ut;
    dense_f32 ot;
    igl::straighten_seams(v, f, vt, ft, tol, ue, ut, ot);
    return std::make_tuple(    npe::move(ue),
    npe::move(ut),
    npe::move(ot));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 ue;
    dense_f64 ut;
    dense_f64 ot;
    igl::straighten_seams(v, f, vt, ft, tol, ue, ut, ot);
    return std::make_tuple(    npe::move(ue),     npe::move(ut),     npe::move(ot));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


