// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/components.h>

const char* ds_components = R"igl_Qu8mg5v7(

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

 Ditto but for mesh faces as input. This computes connected components of
   **vertices** where **edges** establish connectivity.
  
   Inputs:
     F  n by 3 list of triangle indices
   Outputs:
     C  max(F) list of component ids
)igl_Qu8mg5v7";

npe_function(components)
npe_doc(ds_components)

npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 c;
    igl::components(f, c);
    return npe::move(c);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 c;
    igl::components(f, c);
    return npe::move(c);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/components.h>

const char* ds_components = R"igl_Qu8mg5v7(

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

 Compute connected components of a graph represented by an adjacency
   matrix. This version is faster than the previous version using boost.
  
   Inputs:
     A  n by n adjacency matrix
   Outputs:
     C  n list of component ids (starting with 0)
     counts  #components list of counts for each component
  
)igl_Qu8mg5v7";

npe_function(components)
npe_doc(ds_components)

npe_arg(a, Eigen::SparseMatrix<AScalar> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 c;
    dense_f32 counts;
    igl::components(a, c, counts);
    return std::make_tuple(    npe::move(c),
    npe::move(counts));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 c;
    dense_f64 counts;
    igl::components(a, c, counts);
    return std::make_tuple(    npe::move(c),     npe::move(counts));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/components.h>

const char* ds_components = R"igl_Qu8mg5v7(
See components for the documentation.
)igl_Qu8mg5v7";

npe_function(components)
npe_doc(ds_components)

npe_arg(a, Eigen::SparseMatrix<AScalar> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 c;
    igl::components(a, c);
    return npe::move(c);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 c;
    igl::components(a, c);
    return npe::move(c);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


