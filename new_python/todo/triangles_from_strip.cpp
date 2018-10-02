#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/triangles_from_strip.h>

const char* ds_triangles_from_strip = R"igl_Qu8mg5v7(

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

 TRIANGLES_FROM_STRIP Create a list of triangles from a stream of indices
   along a strip.
  
   Inputs:
     S  #S list of indices
   Outputs:
     F  #S-2 by 3 list of triangle indices
  
)igl_Qu8mg5v7";

npe_function(triangles_from_strip)
npe_doc(ds_triangles_from_strip)

npe_arg(s, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_i32 f;
    igl::triangles_from_strip(s, f);
    return npe::move(f);
} else if (dtype.type() == npe::type_f64) {
    dense_i32 f;
    igl::triangles_from_strip(s, f);
    return npe::move(f);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


