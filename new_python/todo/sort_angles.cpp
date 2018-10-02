#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/sort_angles.h>

const char* ds_sort_angles = R"igl_Qu8mg5v7(

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

 Sort angles in ascending order in a numerically robust way.
    
     Instead of computing angles using atan2(y, x), sort directly on (y, x).
    
     Inputs:
       M: m by n matrix of scalars. (n >= 2).  Assuming the first column of M
          contains values for y, and the second column is x.  Using the rest
          of the columns as tie-breaker.
       R: an array of m indices.  M.row(R[i]) contains the i-th smallest
          angle.
)igl_Qu8mg5v7";

npe_function(sort_angles)
npe_doc(ds_sort_angles)

npe_arg(m, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 r;
    igl::sort_angles(m, r);
    return npe::move(r);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 r;
    igl::sort_angles(m, r);
    return npe::move(r);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


