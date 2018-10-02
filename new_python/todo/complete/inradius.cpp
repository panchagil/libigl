#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/inradius.h>

const char* ds_inradius = R"igl_Qu8mg5v7(

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

 Compute the inradius of each triangle in a mesh (V,F)
  
   Inputs:
     V  #V by dim list of mesh vertex positions
     F  #F by 3 list of triangle indices into V
   Outputs:
     R  #F list of inradii
  
)igl_Qu8mg5v7";

npe_function(inradius)
npe_doc(ds_inradius)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 r;
    igl::inradius(v, f, r);
    return npe::move(r);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 r;
    igl::inradius(v, f, r);
    return npe::move(r);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


