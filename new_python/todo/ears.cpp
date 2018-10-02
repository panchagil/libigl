#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/ears.h>

const char* ds_ears = R"igl_Qu8mg5v7(

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

 FIND_EARS  Find all ears (faces with two boundary edges) in a given mesh
   
   [ears,ear_opp] = find_ears(F)
  
   Inputs:
     F  #F by 3 list of triangle mesh indices
   Outputs:
     ears  #ears list of indices into F of ears
     ear_opp  #ears list of indices indicating which edge is non-boundary
       (connecting to flops)
   
)igl_Qu8mg5v7";

npe_function(ears)
npe_doc(ds_ears)

npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 ear;
    dense_f32 ear_opp;
    igl::ears(f, ear, ear_opp);
    return std::make_tuple(    npe::move(ear),
    npe::move(ear_opp));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 ear;
    dense_f64 ear_opp;
    igl::ears(f, ear, ear_opp);
    return std::make_tuple(    npe::move(ear),     npe::move(ear_opp));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


