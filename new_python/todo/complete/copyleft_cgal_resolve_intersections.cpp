#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/resolve_intersections.h>

const char* ds_resolve_intersections = R"igl_Qu8mg5v7(
See resolve_intersections for the documentation.
)igl_Qu8mg5v7";

npe_function(resolve_intersections)
npe_doc(ds_resolve_intersections)

npe_arg(v, dense_f64)
npe_arg(e, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 vi;
    dense_f32 ei;
    dense_f32 j;
    dense_f32 im;
    igl::    copyleft::    cgal::resolve_intersections(v, e, vi, ei, j, im);
    return std::make_tuple(    npe::move(vi),
    npe::move(ei),
    npe::move(j),
    npe::move(im));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 vi;
    dense_f64 ei;
    dense_f64 j;
    dense_f64 im;
    igl::    copyleft::    cgal::resolve_intersections(v, e, vi, ei, j, im);
    return std::make_tuple(    npe::move(vi),     npe::move(ei),     npe::move(j),     npe::move(im));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


