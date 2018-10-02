// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/histc.h>

const char* ds_histc = R"igl_Qu8mg5v7(

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

 Like matlab's histc. Count occurrences of values in X between consecutive
   entries in E
  
   Inputs:
     X  m-long Vector of values
     E  n-long Monotonically increasing vector of edges
   Outputs:
     N  n-long vector where N(k) reveals how many values in X fall between
       E(k) <= X < E(k+1)
     B  m-long vector of bin ids so that B(j) = k if E(k) <= X(j) < E(k+1).
       B(j) = -1 if X(j) is outside of E.
  
   O(n+m*log(n))
)igl_Qu8mg5v7";

npe_function(histc)
npe_doc(ds_histc)

npe_arg(x, dense_f64)
npe_arg(e, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 n;
    dense_f32 b;
    igl::histc(x, e, n, b);
    return std::make_tuple(    npe::move(n),
    npe::move(b));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 n;
    dense_f64 b;
    igl::histc(x, e, n, b);
    return std::make_tuple(    npe::move(n),     npe::move(b));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/histc.h>

const char* ds_histc = R"igl_Qu8mg5v7(

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

 Truly O(m*log(n))
)igl_Qu8mg5v7";

npe_function(histc)
npe_doc(ds_histc)

npe_arg(x, dense_f64)
npe_arg(e, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 b;
    igl::histc(x, e, b);
    return npe::move(b);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 b;
    igl::histc(x, e, b);
    return npe::move(b);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/histc.h>

const char* ds_histc = R"igl_Qu8mg5v7(

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

 Scalar search wrapper
)igl_Qu8mg5v7";

npe_function(histc)
npe_doc(ds_histc)

npe_arg(x, typename DerivedE::Scalar &)
npe_arg(e, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    typename DerivedE::Index & b;
    igl::histc(x, e, b);
    return npe::move(b);
} else if (dtype.type() == npe::type_f64) {
    typename DerivedE::Index & b;
    igl::histc(x, e, b);
    return npe::move(b);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


