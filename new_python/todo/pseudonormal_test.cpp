// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/pseudonormal_test.h>

const char* ds_pseudonormal_test = R"igl_Qu8mg5v7(

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

 Given a mesh (V,F), a query point q, and a point on (V,F) c, determine
   whether q is inside (V,F) --> s=-1 or outside (V,F) s=1, based on the
   sign of the dot product between (q-c) and n, where n is the normal _at c_,
   carefully chosen according to [Bærentzen & Aanæs 2005]
  
   Inputs:
     V  #V by 3 list of vertex positions
     F  #F by 3 list of triangle indices
     FN  #F by 3 list of triangle normals 
     VN  #V by 3 list of vertex normals (ANGLE WEIGHTING)
     EN  #E by 3 list of edge normals (UNIFORM WEIGHTING)
     EMAP  #F*3 mapping edges in F to E
     q  Query point
     f  index into F to face to which c belongs
     c  Point on (V,F)
   Outputs:
     s  sign
     n  normal
)igl_Qu8mg5v7";

npe_function(pseudonormal_test)
npe_doc(ds_pseudonormal_test)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(fn, dense_f64)
npe_arg(vn, dense_f64)
npe_arg(en, dense_f64)
npe_arg(emap, dense_f64)
npe_arg(q, dense_f64)
npe_arg(f, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 c;
    Scalar & s;
    dense_f32 n;
    igl::pseudonormal_test(v, f, fn, vn, en, emap, q, f, c, s, n);
    return std::make_tuple(    npe::move(c),
    npe::move(s),
    npe::move(n));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 c;
    Scalar & s;
    dense_f64 n;
    igl::pseudonormal_test(v, f, fn, vn, en, emap, q, f, c, s, n);
    return std::make_tuple(    npe::move(c),     npe::move(s),     npe::move(n));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/pseudonormal_test.h>

const char* ds_pseudonormal_test = R"igl_Qu8mg5v7(
See pseudonormal_test for the documentation.
)igl_Qu8mg5v7";

npe_function(pseudonormal_test)
npe_doc(ds_pseudonormal_test)

npe_arg(v, dense_f64)
npe_arg(e, dense_f64)
npe_arg(en, dense_f64)
npe_arg(vn, dense_f64)
npe_arg(q, dense_f64)
npe_arg(e, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 c;
    Scalar & s;
    dense_f32 n;
    igl::pseudonormal_test(v, e, en, vn, q, e, c, s, n);
    return std::make_tuple(    npe::move(c),
    npe::move(s),
    npe::move(n));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 c;
    Scalar & s;
    dense_f64 n;
    igl::pseudonormal_test(v, e, en, vn, q, e, c, s, n);
    return std::make_tuple(    npe::move(c),     npe::move(s),     npe::move(n));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


