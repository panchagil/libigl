// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/eigs.h>

const char* ds_eigs = R"igl_Qu8mg5v7(
See eigs for the documentation.
)igl_Qu8mg5v7";

npe_function(eigs)
npe_doc(ds_eigs)

npe_arg(a, Eigen::SparseMatrix<Atype> &)
npe_arg(b, Eigen::SparseMatrix<Btype> &)
npe_arg(k, size_t)
npe_arg(type, igl::EigsType)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 s_u;
    dense_f32 s_s;
    igl::eigs(a, b, k, type, s_u, s_s);
    return std::make_tuple(    npe::move(s_u),
    npe::move(s_s));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 s_u;
    dense_f64 s_s;
    igl::eigs(a, b, k, type, s_u, s_s);
    return std::make_tuple(    npe::move(s_u),     npe::move(s_s));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


