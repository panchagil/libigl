// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/combine.h>

const char* ds_combine = R"igl_Qu8mg5v7(

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

 Concatenate k meshes into a single >=k connected component mesh with a
   single vertex list and face list. Similar to Maya's Combine operation. 
  
   Inputs:
     VV  k-long list of lists of mesh vertex positions
     FF  k-long list of lists of mesh face indices so that FF[i] indexes
       VV[i]
   Outputs:
     V   VV[0].rows()+...+VV[k-1].rows() by VV[0].cols() list of mesh
       vertex positions
     F   FF[0].rows()+...+FF[k-1].rows() by FF[0].cols() list of mesh faces
       indices into V
     Vsizes  k list so that Vsizes(i) is the #vertices in the ith input
     Fsizes  k list so that Fsizes(i) is the #faces in the ith input
   Example:
      Suppose you have mesh A (VA,FA) and mesh B (VB,FB)
     igl::combine<Eigen::MatrixXd,Eigen::MatrixXi>({VA,VB},{FA,FB},V,F);
  
  
)igl_Qu8mg5v7";

npe_function(combine)
npe_doc(ds_combine)

npe_arg(vv, std::vector<DerivedVV> &)
npe_arg(ff, std::vector<DerivedFF> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v;
    dense_i32 f;
    dense_f32 vsizes;
    dense_f32 fsizes;
    igl::combine(vv, ff, v, f, vsizes, fsizes);
    return std::make_tuple(    npe::move(v),
    npe::move(f),
    npe::move(vsizes),
    npe::move(fsizes));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v;
    dense_i32 f;
    dense_f64 vsizes;
    dense_f64 fsizes;
    igl::combine(vv, ff, v, f, vsizes, fsizes);
    return std::make_tuple(    npe::move(v),     npe::move(f),     npe::move(vsizes),     npe::move(fsizes));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/combine.h>

const char* ds_combine = R"igl_Qu8mg5v7(
See combine for the documentation.
)igl_Qu8mg5v7";

npe_function(combine)
npe_doc(ds_combine)

npe_arg(vv, std::vector<DerivedVV> &)
npe_arg(ff, std::vector<DerivedFF> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v;
    dense_i32 f;
    igl::combine(vv, ff, v, f);
    return std::make_tuple(    npe::move(v),
    npe::move(f));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v;
    dense_i32 f;
    igl::combine(vv, ff, v, f);
    return std::make_tuple(    npe::move(v),     npe::move(f));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


