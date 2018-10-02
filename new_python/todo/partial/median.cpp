// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/median.h>

const char* ds_median = R"igl_Qu8mg5v7(

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

 Compute the median of an eigen vector
  
   Inputs:
     V  #V list of unsorted values
   Outputs:
     m  median of those values
   Returns true on success, false on failure
)igl_Qu8mg5v7";

npe_function(median)
npe_doc(ds_median)

npe_arg(v, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    mType & m;
    igl::median(v, m);
    return npe::move(m);
} else if (dtype.type() == npe::type_f64) {
    mType & m;
    igl::median(v, m);
    return npe::move(m);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


