#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/sort_triangles.h>

const char* ds_sort_triangles = R"igl_Qu8mg5v7(
See sort_triangles for the documentation.
)igl_Qu8mg5v7";

npe_function(sort_triangles)
npe_doc(ds_sort_triangles)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 ff;
    dense_f32 i;
    igl::    opengl2::sort_triangles(v, f, ff, i);
    return std::make_tuple(    npe::move(ff),
    npe::move(i));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 ff;
    dense_f64 i;
    igl::    opengl2::sort_triangles(v, f, ff, i);
    return std::make_tuple(    npe::move(ff),     npe::move(i));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/sort_triangles_slow.h>

const char* ds_sort_triangles_slow = R"igl_Qu8mg5v7(
See sort_triangles_slow for the documentation.
)igl_Qu8mg5v7";

npe_function(sort_triangles_slow)
npe_doc(ds_sort_triangles_slow)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 ff;
    dense_f32 i;
    igl::    opengl2::sort_triangles_slow(v, f, ff, i);
    return std::make_tuple(    npe::move(ff),
    npe::move(i));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 ff;
    dense_f64 i;
    igl::    opengl2::sort_triangles_slow(v, f, ff, i);
    return std::make_tuple(    npe::move(ff),     npe::move(i));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


