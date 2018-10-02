#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/diag.h>

const char* ds_diag = R"igl_Qu8mg5v7(

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

 Templates:
     T  should be a eigen sparse matrix primitive type like int or double
   Inputs:
     X  an m by n sparse matrix
   Outputs:
     V  a min(m,n) sparse vector
)igl_Qu8mg5v7";

npe_function(diag)
npe_doc(ds_diag)

npe_arg(x, Sparse_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Sparse_f32 v;
    igl::diag(x, v);
    return npe::move(v);
} else if (dtype.type() == npe::type_f64) {
    Sparse_f64 v;
    igl::diag(x, v);
    return npe::move(v);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/diag.h>

const char* ds_diag = R"igl_Qu8mg5v7(
See diag for the documentation.
)igl_Qu8mg5v7";

npe_function(diag)
npe_doc(ds_diag)

npe_arg(x, Sparse_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v;
    igl::diag(x, v);
    return npe::move(v);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v;
    igl::diag(x, v);
    return npe::move(v);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/diag.h>

const char* ds_diag = R"igl_Qu8mg5v7(

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

 Templates:
     T  should be a eigen sparse matrix primitive type like int or double
   Inputs:
    V  a m sparse vector
   Outputs:
    X  a m by m sparse matrix
)igl_Qu8mg5v7";

npe_function(diag)
npe_doc(ds_diag)

npe_arg(v, Sparse_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Sparse_f32 x;
    igl::diag(v, x);
    return npe::move(x);
} else if (dtype.type() == npe::type_f64) {
    Sparse_f64 x;
    igl::diag(v, x);
    return npe::move(x);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/diag.h>

const char* ds_diag = R"igl_Qu8mg5v7(
See diag for the documentation.
)igl_Qu8mg5v7";

npe_function(diag)
npe_doc(ds_diag)

npe_arg(v, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Sparse_f32 x;
    igl::diag(v, x);
    return npe::move(x);
} else if (dtype.type() == npe::type_f64) {
    Sparse_f64 x;
    igl::diag(v, x);
    return npe::move(x);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


