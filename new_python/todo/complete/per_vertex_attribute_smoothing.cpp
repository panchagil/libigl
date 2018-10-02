#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/per_vertex_attribute_smoothing.h>

const char* ds_per_vertex_attribute_smoothing = R"igl_Qu8mg5v7(

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

 Smooth vertex attributes using uniform Laplacian
   Inputs:
     Ain  #V by #A eigen Matrix of mesh vertex attributes (each vertex has #A attributes)
     F    #F by 3 eigne Matrix of face (triangle) indices
   Output:
     Aout #V by #A eigen Matrix of mesh vertex attributes
)igl_Qu8mg5v7";

npe_function(per_vertex_attribute_smoothing)
npe_doc(ds_per_vertex_attribute_smoothing)

npe_arg(ain, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 aout;
    igl::per_vertex_attribute_smoothing(ain, f, aout);
    return npe::move(aout);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 aout;
    igl::per_vertex_attribute_smoothing(ain, f, aout);
    return npe::move(aout);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


