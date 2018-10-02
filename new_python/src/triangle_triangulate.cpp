#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>

#include <igl/triangle/triangulate.h>

const char* ds_triangulate = R"igl_Qu8mg5v7(
Triangulate the interior of a polygon using the triangle library.

Parameters
----------
v : #v by 2 array of 2D vertex positions
e : #e by 2 array of vertex ids forming unoriented edges of the boundary of the polygon
h : #h by 2 coordinates of points contained inside holes of the polygon
flags : string of options pass to triangle (see triangle documentation) (default "a0.005q")
dtype : data-type of the returned objects, optional. Default is `float64`.
        (All integer return types are `int32` by default.)

Returns
-------
v2  #v2 by 2 coordinates of the vertives of the generated triangulation
f2  #f2 by 3 array of indices forming the faces of the generated triangulation

See also
--------
None

Notes
-----
None

Examples
--------
>>> v2, f2 = triangulate(v, e, h)
)igl_Qu8mg5v7";

npe_function(triangulate)
npe_doc(ds_triangulate)

npe_arg(v, dense_f64, dense_f32)
npe_arg(e, dense_i32)
npe_arg(h, dense_f64, dense_f32)
npe_default_arg(flags, std::string, "a0.005q")
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Dense_f32 v2;
    Dense_i32 f2;
    igl::triangle::triangulate(v, e, h, flags, v2, f2);
    return std::make_tuple(npe::move(v2), npe::move(f2));
} else if (dtype.type() == npe::type_f64) {
    Dense_f64 v2;
    Dense_i32 f2;
    igl::triangle::triangulate(v, e, h, flags, v2, f2);
    return std::make_tuple(npe::move(v2), npe::move(f2));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
