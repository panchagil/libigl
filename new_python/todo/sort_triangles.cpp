#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/sort_triangles.h>

const char* ds_sort_triangles = R"igl_Qu8mg5v7(

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

 Inputs:
     V  #V by **4** list of homogeneous vertex positions
     F  #F by 3 list of triangle indices
     MV  4 by 4 model view matrix
     P  4 by 4 projection matrix
   Outputs:
     FF  #F by 3 list of sorted triangles indices
     I  #F list of sorted indices
)igl_Qu8mg5v7";

npe_function(sort_triangles)
npe_doc(ds_sort_triangles)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(mv, dense_f64)
npe_arg(p, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 ff;
    dense_f32 i;
    igl::sort_triangles(v, f, mv, p, ff, i);
    return std::make_tuple(    npe::move(ff),
    npe::move(i));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 ff;
    dense_f64 i;
    igl::sort_triangles(v, f, mv, p, ff, i);
    return std::make_tuple(    npe::move(ff),     npe::move(i));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


