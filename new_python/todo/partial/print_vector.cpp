// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/print_vector.h>

const char* ds_print_vector = R"igl_Qu8mg5v7(

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

 Not clear what these are supposed to be doing. Currently they print
   vectors to standard error...
)igl_Qu8mg5v7";

npe_function(print_vector)
npe_doc(ds_print_vector)

npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<T> & v;
    igl::print_vector(v);
    return npe::move(v);
} else if (dtype.type() == npe::type_f64) {
    std::vector<T> & v;
    igl::print_vector(v);
    return npe::move(v);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/print_vector.h>

const char* ds_print_vector = R"igl_Qu8mg5v7(
See print_vector for the documentation.
)igl_Qu8mg5v7";

npe_function(print_vector)
npe_doc(ds_print_vector)

npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<T> > & v;
    igl::print_vector(v);
    return npe::move(v);
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<T> > & v;
    igl::print_vector(v);
    return npe::move(v);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/print_vector.h>

const char* ds_print_vector = R"igl_Qu8mg5v7(
See print_vector for the documentation.
)igl_Qu8mg5v7";

npe_function(print_vector)
npe_doc(ds_print_vector)

npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<std::vector<T> > > & v;
    igl::print_vector(v);
    return npe::move(v);
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<std::vector<T> > > & v;
    igl::print_vector(v);
    return npe::move(v);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


