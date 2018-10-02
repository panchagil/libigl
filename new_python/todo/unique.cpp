// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/unique.h>

const char* ds_unique = R"igl_Qu8mg5v7(

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

 Act like matlab's [C,IA,IC] = unique(X)
  
   Templates:
     T  comparable type T
   Inputs:
     A  #A vector of type T
   Outputs:
     C  #C vector of unique entries in A
     IA  #C index vector so that C = A(IA);
     IC  #A index vector so that A = C(IC);
)igl_Qu8mg5v7";

npe_function(unique)
npe_doc(ds_unique)

npe_arg(a, std::vector<T> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<T> & c;
    std::vector<size_t> & ia;
    std::vector<size_t> & ic;
    igl::unique(a, c, ia, ic);
    return std::make_tuple(    npe::move(c),
    npe::move(ia),
    npe::move(ic));
} else if (dtype.type() == npe::type_f64) {
    std::vector<T> & c;
    std::vector<size_t> & ia;
    std::vector<size_t> & ic;
    igl::unique(a, c, ia, ic);
    return std::make_tuple(    npe::move(c),     npe::move(ia),     npe::move(ic));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/unique.h>

const char* ds_unique = R"igl_Qu8mg5v7(
See unique for the documentation.
)igl_Qu8mg5v7";

npe_function(unique)
npe_doc(ds_unique)

npe_arg(a, std::vector<T> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<T> & c;
    igl::unique(a, c);
    return npe::move(c);
} else if (dtype.type() == npe::type_f64) {
    std::vector<T> & c;
    igl::unique(a, c);
    return npe::move(c);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/unique.h>

const char* ds_unique = R"igl_Qu8mg5v7(
See unique for the documentation.
)igl_Qu8mg5v7";

npe_function(unique)
npe_doc(ds_unique)

npe_arg(a, Eigen::DenseBase<DerivedA> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 c;
    dense_f32 ia;
    dense_f32 ic;
    igl::unique(a, c, ia, ic);
    return std::make_tuple(    npe::move(c),
    npe::move(ia),
    npe::move(ic));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 c;
    dense_f64 ia;
    dense_f64 ic;
    igl::unique(a, c, ia, ic);
    return std::make_tuple(    npe::move(c),     npe::move(ia),     npe::move(ic));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/unique.h>

const char* ds_unique = R"igl_Qu8mg5v7(
See unique for the documentation.
)igl_Qu8mg5v7";

npe_function(unique)
npe_doc(ds_unique)

npe_arg(a, Eigen::DenseBase<DerivedA> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 c;
    igl::unique(a, c);
    return npe::move(c);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 c;
    igl::unique(a, c);
    return npe::move(c);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


