#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/repmat.h>

const char* ds_repmat = R"igl_Qu8mg5v7(

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

 Replicate and tile a matrix
  
   Templates:
     T  should be a eigen matrix primitive type like int or double
   Inputs:
     A  m by n input matrix
     r  number of row-direction copies
     c  number of col-direction copies
   Outputs:
     B  r*m by c*n output matrix
  
)igl_Qu8mg5v7";

npe_function(repmat)
npe_doc(ds_repmat)

npe_arg(a, dense_f64)
npe_arg(r, int)
npe_arg(c, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 b;
    igl::repmat(a, r, c, b);
    return npe::move(b);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 b;
    igl::repmat(a, r, c, b);
    return npe::move(b);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/repmat.h>

const char* ds_repmat = R"igl_Qu8mg5v7(
See repmat for the documentation.
)igl_Qu8mg5v7";

npe_function(repmat)
npe_doc(ds_repmat)

npe_arg(a, Sparse_f64)
npe_arg(r, int)
npe_arg(c, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Sparse_f32 b;
    igl::repmat(a, r, c, b);
    return npe::move(b);
} else if (dtype.type() == npe::type_f64) {
    Sparse_f64 b;
    igl::repmat(a, r, c, b);
    return npe::move(b);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


