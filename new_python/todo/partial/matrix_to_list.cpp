// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/matrix_to_list.h>

const char* ds_matrix_to_list = R"igl_Qu8mg5v7(

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

 Convert a matrix to a list (std::vector) of row vectors of the same size
  
   Template: 
     Mat  Matrix type, must implement:
       .resize(m,n)
       .row(i) = Row
     T  type that can be safely cast to type in Mat via '='
   Inputs:
     M  an m by n matrix
   Outputs:
     V  a m-long list of vectors of size n
  
   See also: list_to_matrix
)igl_Qu8mg5v7";

npe_function(matrix_to_list)
npe_doc(ds_matrix_to_list)

npe_arg(m, Eigen::DenseBase<DerivedM> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<typename DerivedM::Scalar> > & v;
    igl::matrix_to_list(m, v);
    return npe::move(v);
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<typename DerivedM::Scalar> > & v;
    igl::matrix_to_list(m, v);
    return npe::move(v);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/matrix_to_list.h>

const char* ds_matrix_to_list = R"igl_Qu8mg5v7(

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

 Convert a matrix to a list (std::vector) of elements in column-major
   ordering.
  
   Inputs:
      M  an m by n matrix
   Outputs:
      V  an m*n list of elements
)igl_Qu8mg5v7";

npe_function(matrix_to_list)
npe_doc(ds_matrix_to_list)

npe_arg(m, Eigen::DenseBase<DerivedM> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<typename DerivedM::Scalar> & v;
    igl::matrix_to_list(m, v);
    return npe::move(v);
} else if (dtype.type() == npe::type_f64) {
    std::vector<typename DerivedM::Scalar> & v;
    igl::matrix_to_list(m, v);
    return npe::move(v);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/matrix_to_list.h>

const char* ds_matrix_to_list = R"igl_Qu8mg5v7(

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

 Return wrapper
)igl_Qu8mg5v7";

npe_function(matrix_to_list)
npe_doc(ds_matrix_to_list)

npe_arg(m, Eigen::DenseBase<DerivedM> &)



npe_begin_code()
using namespace std;



igl::matrix_to_list(m);

return

npe_end_code()


