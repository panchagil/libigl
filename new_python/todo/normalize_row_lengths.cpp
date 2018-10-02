#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/normalize_row_lengths.h>

const char* ds_normalize_row_lengths = R"igl_Qu8mg5v7(

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

 Obsolete: just use A.rowwise().normalize() or B=A.rowwise().normalized();
  
   Normalize the rows in A so that their lengths are each 1 and place the new
   entries in B
   Inputs:
     A  #rows by k input matrix
   Outputs:
     B  #rows by k input matrix, can be the same as A
)igl_Qu8mg5v7";

npe_function(normalize_row_lengths)
npe_doc(ds_normalize_row_lengths)

npe_arg(a, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 b;
    igl::normalize_row_lengths(a, b);
    return npe::move(b);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 b;
    igl::normalize_row_lengths(a, b);
    return npe::move(b);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


