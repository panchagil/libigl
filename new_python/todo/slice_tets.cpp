// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/slice_tets.h>

const char* ds_slice_tets = R"igl_Qu8mg5v7(
See slice_tets for the documentation.
)igl_Qu8mg5v7";

npe_function(slice_tets)
npe_doc(ds_slice_tets)

npe_arg(v, dense_f64)
npe_arg(t, dense_f64)
npe_arg(s, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 sv;
    dense_f32 sf;
    dense_f32 j;
    igl::slice_tets(v, t, s, sv, sf, j);
    return std::make_tuple(    npe::move(sv),
    npe::move(sf),
    npe::move(j));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 sv;
    dense_f64 sf;
    dense_f64 j;
    igl::slice_tets(v, t, s, sv, sf, j);
    return std::make_tuple(    npe::move(sv),     npe::move(sf),     npe::move(j));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/slice_tets.h>

const char* ds_slice_tets = R"igl_Qu8mg5v7(

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

 Outputs:
     sE  #SV by 2 list of sorted edge indices into V
     lambda  #SV by 1 list of parameters along each edge in sE so that:
       SV(i,:) = V(sE(i,1),:)*lambda(i) + V(sE(i,2),:)*(1-lambda(i));
)igl_Qu8mg5v7";

npe_function(slice_tets)
npe_doc(ds_slice_tets)

npe_arg(v, dense_f64)
npe_arg(t, dense_f64)
npe_arg(s, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 sv;
    dense_f32 sf;
    dense_f32 j;
    dense_f32 s_e;
    dense_f32 lambda;
    igl::slice_tets(v, t, s, sv, sf, j, s_e, lambda);
    return std::make_tuple(    npe::move(sv),
    npe::move(sf),
    npe::move(j),
    npe::move(s_e),
    npe::move(lambda));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 sv;
    dense_f64 sf;
    dense_f64 j;
    dense_f64 s_e;
    dense_f64 lambda;
    igl::slice_tets(v, t, s, sv, sf, j, s_e, lambda);
    return std::make_tuple(    npe::move(sv),     npe::move(sf),     npe::move(j),     npe::move(s_e),     npe::move(lambda));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/slice_tets.h>

const char* ds_slice_tets = R"igl_Qu8mg5v7(

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

 SLICE_TETS Slice through a tet mesh (V,T) along a given plane (via its
   implicit equation).
  
   Inputs:
     V  #V by 3 list of tet mesh vertices
     T  #T by 4 list of tet indices into V 
     plane  list of 4 coefficients in the plane equation: [x y z 1]'*plane = 0
     S  #V list of values so that S = 0 is the desired isosurface
   Outputs:
     SV  #SV by 3 list of triangle mesh vertices along slice
     SF  #SF by 3 list of triangles indices into SV
     J  #SF list of indices into T revealing from which tet each faces comes
     BC  #SU by #V list of barycentric coordinates (or more generally: linear
       interpolation coordinates) so that SV = BC*V
   
)igl_Qu8mg5v7";

npe_function(slice_tets)
npe_doc(ds_slice_tets)

npe_arg(v, dense_f64)
npe_arg(t, dense_f64)
npe_arg(s, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 sv;
    dense_f32 sf;
    dense_f32 j;
    Eigen::SparseMatrix<BCType> & bc;
    igl::slice_tets(v, t, s, sv, sf, j, bc);
    return std::make_tuple(    npe::move(sv),
    npe::move(sf),
    npe::move(j),
    npe::move(bc));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 sv;
    dense_f64 sf;
    dense_f64 j;
    Eigen::SparseMatrix<BCType> & bc;
    igl::slice_tets(v, t, s, sv, sf, j, bc);
    return std::make_tuple(    npe::move(sv),     npe::move(sf),     npe::move(j),     npe::move(bc));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


