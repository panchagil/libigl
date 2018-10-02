#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/speye.h>

const char* ds_speye = R"igl_Qu8mg5v7(

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

 Builds an m by n sparse identity matrix like matlab's speye function
   Templates:
     T  should be a eigen sparse matrix primitive type like int or double
   Inputs:
     m  number of rows
     n  number of cols
   Outputs:
     I  m by n sparse matrix with 1's on the main diagonal
)igl_Qu8mg5v7";

npe_function(speye)
npe_doc(ds_speye)

npe_arg(n, int)
npe_arg(m, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Sparse_f32 i;
    igl::speye(n, m, i);
    return npe::move(i);
} else if (dtype.type() == npe::type_f64) {
    Sparse_f64 i;
    igl::speye(n, m, i);
    return npe::move(i);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/speye.h>

const char* ds_speye = R"igl_Qu8mg5v7(

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

 Builds an n by n sparse identity matrix like matlab's speye function
   Templates:
     T  should be a eigen sparse matrix primitive type like int or double
   Inputs:
     n  number of rows and cols
   Outputs:
     I  n by n sparse matrix with 1's on the main diagonal
)igl_Qu8mg5v7";

npe_function(speye)
npe_doc(ds_speye)

npe_arg(n, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Sparse_f32 i;
    igl::speye(n, i);
    return npe::move(i);
} else if (dtype.type() == npe::type_f64) {
    Sparse_f64 i;
    igl::speye(n, i);
    return npe::move(i);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


