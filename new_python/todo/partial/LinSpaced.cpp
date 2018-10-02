// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/LinSpaced.h>

const char* ds_lin_spaced = R"igl_Qu8mg5v7(

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

 Implementation
)igl_Qu8mg5v7";

npe_function(lin_spaced)
npe_doc(ds_lin_spaced)

npe_arg(low, typename Derived::Scalar &)
npe_arg(high, typename Derived::Scalar &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    typename Derived::Index size;
    igl::LinSpaced(low, high, size);
    return npe::move(size);
} else if (dtype.type() == npe::type_f64) {
    typename Derived::Index size;
    igl::LinSpaced(low, high, size);
    return npe::move(size);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/LinSpaced.h>

const char* ds_lin_spaced = R"igl_Qu8mg5v7(

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

 Implementation
)igl_Qu8mg5v7";

npe_function(lin_spaced)
npe_doc(ds_lin_spaced)

npe_arg(low, typename Derived::Scalar &)
npe_arg(high, typename Derived::Scalar &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    typename Derived::Index size;
    igl::LinSpaced(low, high, size);
    return npe::move(size);
} else if (dtype.type() == npe::type_f64) {
    typename Derived::Index size;
    igl::LinSpaced(low, high, size);
    return npe::move(size);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


