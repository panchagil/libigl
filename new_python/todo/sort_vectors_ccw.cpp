#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/sort_vectors_ccw.h>

const char* ds_sort_vectors_ccw = R"igl_Qu8mg5v7(

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

 Inputs:
     P               1 by 3N row vector of the vectors to be sorted, stacked horizontally
     N               #1 by 3 normal of the plane where the vectors lie
   Output:
     order           N by 1 order of the vectors (indices of the unordered vectors into
                     the ordered vector set)
     sorted          1 by 3N row vector of the ordered vectors, stacked horizontally
     inv_order       N by 1 "inverse" order of the vectors (the indices of the ordered
                     vectors into the unordered vector set)
  
)igl_Qu8mg5v7";

npe_function(sort_vectors_ccw)
npe_doc(ds_sort_vectors_ccw)

npe_arg(p, dense_f64)
npe_arg(n, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 order;
    dense_f32 sorted;
    dense_f32 inv_order;
    igl::sort_vectors_ccw(p, n, order, sorted, inv_order);
    return std::make_tuple(    npe::move(order),
    npe::move(sorted),
    npe::move(inv_order));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 order;
    dense_f64 sorted;
    dense_f64 inv_order;
    igl::sort_vectors_ccw(p, n, order, sorted, inv_order);
    return std::make_tuple(    npe::move(order),     npe::move(sorted),     npe::move(inv_order));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/sort_vectors_ccw.h>

const char* ds_sort_vectors_ccw = R"igl_Qu8mg5v7(
See sort_vectors_ccw for the documentation.
)igl_Qu8mg5v7";

npe_function(sort_vectors_ccw)
npe_doc(ds_sort_vectors_ccw)

npe_arg(p, dense_f64)
npe_arg(n, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 order;
    dense_f32 sorted;
    igl::sort_vectors_ccw(p, n, order, sorted);
    return std::make_tuple(    npe::move(order),
    npe::move(sorted));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 order;
    dense_f64 sorted;
    igl::sort_vectors_ccw(p, n, order, sorted);
    return std::make_tuple(    npe::move(order),     npe::move(sorted));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/sort_vectors_ccw.h>

const char* ds_sort_vectors_ccw = R"igl_Qu8mg5v7(
See sort_vectors_ccw for the documentation.
)igl_Qu8mg5v7";

npe_function(sort_vectors_ccw)
npe_doc(ds_sort_vectors_ccw)

npe_arg(p, dense_f64)
npe_arg(n, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 order;
    dense_f32 inv_order;
    igl::sort_vectors_ccw(p, n, order, inv_order);
    return std::make_tuple(    npe::move(order),
    npe::move(inv_order));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 order;
    dense_f64 inv_order;
    igl::sort_vectors_ccw(p, n, order, inv_order);
    return std::make_tuple(    npe::move(order),     npe::move(inv_order));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/sort_vectors_ccw.h>

const char* ds_sort_vectors_ccw = R"igl_Qu8mg5v7(
See sort_vectors_ccw for the documentation.
)igl_Qu8mg5v7";

npe_function(sort_vectors_ccw)
npe_doc(ds_sort_vectors_ccw)

npe_arg(p, dense_f64)
npe_arg(n, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 order;
    igl::sort_vectors_ccw(p, n, order);
    return npe::move(order);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 order;
    igl::sort_vectors_ccw(p, n, order);
    return npe::move(order);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


