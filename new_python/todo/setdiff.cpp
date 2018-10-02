// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/setdiff.h>

const char* ds_setdiff = R"igl_Qu8mg5v7(

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

 Set difference of elements of matrices
  
   Inputs:
     A  m-long vector of indices
     B  n-long vector of indices
   Outputs:
     C  (k<=m)-long vector of unique elements appearing in A but not in B
     IA  (k<=m)-long list of indices into A so that C = A(IA)
  
)igl_Qu8mg5v7";

npe_function(setdiff)
npe_doc(ds_setdiff)

npe_arg(a, Eigen::DenseBase<DerivedA> &)
npe_arg(b, Eigen::DenseBase<DerivedB> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 c;
    dense_f32 ia;
    igl::setdiff(a, b, c, ia);
    return std::make_tuple(    npe::move(c),
    npe::move(ia));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 c;
    dense_f64 ia;
    igl::setdiff(a, b, c, ia);
    return std::make_tuple(    npe::move(c),     npe::move(ia));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


