#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/flipped_triangles.h>

const char* ds_flipped_triangles = R"igl_Qu8mg5v7(

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

 Finds the ids of the flipped triangles of the mesh V,F in the UV mapping uv
  
   Inputs:
     V  #V by 2 list of mesh vertex positions
     F  #F by 3 list of mesh faces (must be triangles)
   Outputs:
     X  #flipped list of containing the indices into F of the flipped triangles
   Wrapper with return type
)igl_Qu8mg5v7";

npe_function(flipped_triangles)
npe_doc(ds_flipped_triangles)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 x;
    igl::flipped_triangles(v, f, x);
    return npe::move(x);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 x;
    igl::flipped_triangles(v, f, x);
    return npe::move(x);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/flipped_triangles.h>

const char* ds_flipped_triangles = R"igl_Qu8mg5v7(
See flipped_triangles for the documentation.
)igl_Qu8mg5v7";

npe_function(flipped_triangles)
npe_doc(ds_flipped_triangles)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)



npe_begin_code()
using namespace std;



igl::flipped_triangles(v, f);

return

npe_end_code()


