// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/centroid.h>

const char* ds_centroid = R"igl_Qu8mg5v7(
See centroid for the documentation.
)igl_Qu8mg5v7";

npe_function(centroid)
npe_doc(ds_centroid)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 c;
    igl::centroid(v, f, c);
    return npe::move(c);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 c;
    igl::centroid(v, f, c);
    return npe::move(c);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/centroid.h>

const char* ds_centroid = R"igl_Qu8mg5v7(

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

 CENTROID Computes the centroid of a closed mesh using a surface integral.
   
   Inputs:
     V  #V by dim list of rest domain positions
     F  #F by 3 list of triangle indices into V
   Outputs:
      c  dim vector of centroid coordinates
      vol  total volume of solid.
  
)igl_Qu8mg5v7";

npe_function(centroid)
npe_doc(ds_centroid)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 c;
    Derivedvol & vol;
    igl::centroid(v, f, c, vol);
    return std::make_tuple(    npe::move(c),
    npe::move(vol));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 c;
    Derivedvol & vol;
    igl::centroid(v, f, c, vol);
    return std::make_tuple(    npe::move(c),     npe::move(vol));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


