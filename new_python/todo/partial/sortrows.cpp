// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/sortrows.h>

const char* ds_sortrows = R"igl_Qu8mg5v7(

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

 Act like matlab's [Y,I] = sortrows(X)
  
   Templates:
     DerivedX derived scalar type, e.g. MatrixXi or MatrixXd
     DerivedI derived integer type, e.g. MatrixXi
   Inputs:
     X  m by n matrix whose entries are to be sorted
     ascending  sort ascending (true, matlab default) or descending (false)
   Outputs:
     Y  m by n matrix whose entries are sorted (**should not** be same
       reference as X)
     I  m list of indices so that
       Y = X(I,:);
)igl_Qu8mg5v7";

npe_function(sortrows)
npe_doc(ds_sortrows)

npe_arg(x, Eigen::DenseBase<DerivedX> &)
npe_arg(ascending, bool)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 y;
    dense_f32 i;
    igl::sortrows(x, ascending, y, i);
    return std::make_tuple(    npe::move(y),
    npe::move(i));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 y;
    dense_f64 i;
    igl::sortrows(x, ascending, y, i);
    return std::make_tuple(    npe::move(y),     npe::move(i));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


