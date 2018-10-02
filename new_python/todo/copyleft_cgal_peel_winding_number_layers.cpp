#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/peel_winding_number_layers.h>

const char* ds_peel_winding_number_layers = R"igl_Qu8mg5v7(
See peel_winding_number_layers for the documentation.
)igl_Qu8mg5v7";

npe_function(peel_winding_number_layers)
npe_doc(ds_peel_winding_number_layers)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 w;
    igl::    copyleft::    cgal::peel_winding_number_layers(v, f, w);
    return npe::move(w);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 w;
    igl::    copyleft::    cgal::peel_winding_number_layers(v, f, w);
    return npe::move(w);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


