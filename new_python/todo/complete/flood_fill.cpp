#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/flood_fill.h>

const char* ds_flood_fill = R"igl_Qu8mg5v7(

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

 Given a 3D array with sparse non-nan (number?) data fill in the NaNs via
   flood fill. This should ensure that, e.g., if data near 0 always has a band
   (surface) of numbered and signed data, then components of nans will be
   correctly signed.
  
   Inputs:
     res  3-long list of dimensions of grid
     S  res(0)*res(1)*res(2)  list of scalar values (with (many) nans), see
       output
   Outputs:
     S  flood fill data in place
)igl_Qu8mg5v7";

npe_function(flood_fill)
npe_doc(ds_flood_fill)

npe_arg(res, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 s;
    igl::flood_fill(res, s);
    return npe::move(s);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 s;
    igl::flood_fill(res, s);
    return npe::move(s);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


