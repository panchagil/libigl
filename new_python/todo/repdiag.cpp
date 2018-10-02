// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/repdiag.h>

const char* ds_repdiag = R"igl_Qu8mg5v7(

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

 Sparse version
)igl_Qu8mg5v7";

npe_function(repdiag)
npe_doc(ds_repdiag)

npe_arg(a, Sparse_f64)
npe_arg(d, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Sparse_f32 b;
    igl::repdiag(a, d, b);
    return npe::move(b);
} else if (dtype.type() == npe::type_f64) {
    Sparse_f64 b;
    igl::repdiag(a, d, b);
    return npe::move(b);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/repdiag.h>

const char* ds_repdiag = R"igl_Qu8mg5v7(

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

 Dense version
)igl_Qu8mg5v7";

npe_function(repdiag)
npe_doc(ds_repdiag)

npe_arg(a, Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> &)
npe_arg(d, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> & b;
    igl::repdiag(a, d, b);
    return npe::move(b);
} else if (dtype.type() == npe::type_f64) {
    Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> & b;
    igl::repdiag(a, d, b);
    return npe::move(b);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/repdiag.h>

const char* ds_repdiag = R"igl_Qu8mg5v7(

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

 Wrapper with B as output
)igl_Qu8mg5v7";

npe_function(repdiag)
npe_doc(ds_repdiag)

npe_arg(a, Mat &)
npe_arg(d, int)



npe_begin_code()
using namespace std;



igl::repdiag(a, d);

return

npe_end_code()


