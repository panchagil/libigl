#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/ismember.h>

const char* ds_ismember = R"igl_Qu8mg5v7(

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

 Determine if elements of A exist in elements of B
  
   Inputs:
     A  ma by na matrix
     B  mb by nb matrix
   Outputs:
     IA  ma by na matrix of flags whether corresponding element of A exists in
       B
     LOCB  ma by na matrix of indices in B locating matching element (-1 if
       not found), indices assume column major ordering
  
)igl_Qu8mg5v7";

npe_function(ismember)
npe_doc(ds_ismember)

npe_arg(a, dense_f64)
npe_arg(b, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 ia;
    dense_f32 locb;
    igl::ismember(a, b, ia, locb);
    return std::make_tuple(    npe::move(ia),
    npe::move(locb));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 ia;
    dense_f64 locb;
    igl::ismember(a, b, ia, locb);
    return std::make_tuple(    npe::move(ia),     npe::move(locb));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/ismember_rows.h>

const char* ds_ismember_rows = R"igl_Qu8mg5v7(
See ismember_rows for the documentation.
)igl_Qu8mg5v7";

npe_function(ismember_rows)
npe_doc(ds_ismember_rows)

npe_arg(a, dense_f64)
npe_arg(b, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 ia;
    dense_f32 locb;
    igl::ismember_rows(a, b, ia, locb);
    return std::make_tuple(    npe::move(ia),
    npe::move(locb));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 ia;
    dense_f64 locb;
    igl::ismember_rows(a, b, ia, locb);
    return std::make_tuple(    npe::move(ia),     npe::move(locb));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


