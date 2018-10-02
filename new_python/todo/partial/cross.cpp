// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/cross.h>

const char* ds_cross = R"igl_Qu8mg5v7(

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

 Computes C = cross(A,B,2);
  
   Inputs:
     A  #A by 3 list of row-vectors
     B  #A by 3 list of row-vectors
   Outputs:
     C  #A by 3 list of row-vectors
)igl_Qu8mg5v7";

npe_function(cross)
npe_doc(ds_cross)

npe_arg(a, dense_f64)
npe_arg(b, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 c;
    igl::cross(a, b, c);
    return npe::move(c);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 c;
    igl::cross(a, b, c);
    return npe::move(c);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/cross.h>

const char* ds_cross = R"igl_Qu8mg5v7(

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

 Computes out = cross(a,b)
   Inputs:
     a  left 3d vector
     b  right 3d vector
   Outputs:
     out  result 3d vector
)igl_Qu8mg5v7";

npe_function(cross)
npe_doc(ds_cross)

npe_arg(a, double *)
npe_arg(b, double *)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    double * out;
    igl::cross(a, b, out);
    return npe::move(out);
} else if (dtype.type() == npe::type_f64) {
    double * out;
    igl::cross(a, b, out);
    return npe::move(out);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


