#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/polar_svd.h>

const char* ds_polar_svd = R"igl_Qu8mg5v7(

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

 Computes the polar decomposition (R,T) of a matrix A using SVD singular
   value decomposition
  
   Inputs:
     A  3 by 3 matrix to be decomposed
   Outputs:
     R  3 by 3 rotation matrix part of decomposition (**always rotataion**)
     T  3 by 3 stretch matrix part of decomposition
     U  3 by 3 left-singular vectors
     S  3 by 1 singular values
     V  3 by 3 right-singular vectors
  
  
)igl_Qu8mg5v7";

npe_function(polar_svd)
npe_doc(ds_polar_svd)

npe_arg(a, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 r;
    dense_f32 t;
    dense_f32 u;
    dense_f32 s;
    dense_f32 v;
    igl::polar_svd(a, r, t, u, s, v);
    return std::make_tuple(    npe::move(r),
    npe::move(t),
    npe::move(u),
    npe::move(s),
    npe::move(v));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 r;
    dense_f64 t;
    dense_f64 u;
    dense_f64 s;
    dense_f64 v;
    igl::polar_svd(a, r, t, u, s, v);
    return std::make_tuple(    npe::move(r),     npe::move(t),     npe::move(u),     npe::move(s),     npe::move(v));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/polar_svd.h>

const char* ds_polar_svd = R"igl_Qu8mg5v7(
See polar_svd for the documentation.
)igl_Qu8mg5v7";

npe_function(polar_svd)
npe_doc(ds_polar_svd)

npe_arg(a, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 r;
    dense_f32 t;
    igl::polar_svd(a, r, t);
    return std::make_tuple(    npe::move(r),
    npe::move(t));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 r;
    dense_f64 t;
    igl::polar_svd(a, r, t);
    return std::make_tuple(    npe::move(r),     npe::move(t));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


