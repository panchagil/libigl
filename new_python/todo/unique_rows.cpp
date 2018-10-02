// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/unique_rows.h>

const char* ds_unique_rows = R"igl_Qu8mg5v7(

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

 Act like matlab's [C,IA,IC] = unique(X,'rows')
  
   Templates:
     DerivedA derived scalar type, e.g. MatrixXi or MatrixXd
     DerivedIA derived integer type, e.g. MatrixXi
     DerivedIC derived integer type, e.g. MatrixXi
   Inputs:
     A  m by n matrix whose entries are to unique'd according to rows
   Outputs:
     C  #C vector of unique rows in A
     IA  #C index vector so that C = A(IA,:);
     IC  #A index vector so that A = C(IC,:);
)igl_Qu8mg5v7";

npe_function(unique_rows)
npe_doc(ds_unique_rows)

npe_arg(a, Eigen::DenseBase<DerivedA> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 c;
    dense_f32 ia;
    dense_f32 ic;
    igl::unique_rows(a, c, ia, ic);
    return std::make_tuple(    npe::move(c),
    npe::move(ia),
    npe::move(ic));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 c;
    dense_f64 ia;
    dense_f64 ic;
    igl::unique_rows(a, c, ia, ic);
    return std::make_tuple(    npe::move(c),     npe::move(ia),     npe::move(ic));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


