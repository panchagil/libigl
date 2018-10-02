// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/invert_diag.h>

const char* ds_invert_diag = R"igl_Qu8mg5v7(

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
     Y  an m by n sparse matrix
)igl_Qu8mg5v7";

npe_function(invert_diag)
npe_doc(ds_invert_diag)

npe_arg(x, Eigen::SparseMatrixBase<T> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Sparse_f32 y;
    igl::invert_diag(x, y);
    return npe::move(y);
} else if (dtype.type() == npe::type_f64) {
    Sparse_f64 y;
    igl::invert_diag(x, y);
    return npe::move(y);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


