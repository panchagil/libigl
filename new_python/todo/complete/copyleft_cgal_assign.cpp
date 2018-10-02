#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/assign.h>

const char* ds_assign = R"igl_Qu8mg5v7(
See assign for the documentation.
)igl_Qu8mg5v7";

npe_function(assign)
npe_doc(ds_assign)

npe_arg(c, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 d;
    igl::    copyleft::    cgal::assign(c, d);
    return npe::move(d);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 d;
    igl::    copyleft::    cgal::assign(c, d);
    return npe::move(d);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/assign.h>

const char* ds_assign = R"igl_Qu8mg5v7(
See assign for the documentation.
)igl_Qu8mg5v7";

npe_function(assign)
npe_doc(ds_assign)

npe_arg(c, dense_f64)



npe_begin_code()
using namespace std;



igl::copyleft::cgal::assign(c);

return

npe_end_code()


