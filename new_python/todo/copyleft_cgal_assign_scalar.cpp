// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/assign_scalar.h>

const char* ds_assign_scalar = R"igl_Qu8mg5v7(

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
         cgal  cgal scalar
       Outputs:
         d  output scalar
)igl_Qu8mg5v7";

npe_function(assign_scalar)
npe_doc(ds_assign_scalar)

npe_arg(cgal, CGAL::Epeck::FT &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    CGAL::Epeck::FT & d;
    igl::    copyleft::    cgal::assign_scalar(cgal, d);
    return npe::move(d);
} else if (dtype.type() == npe::type_f64) {
    CGAL::Epeck::FT & d;
    igl::    copyleft::    cgal::assign_scalar(cgal, d);
    return npe::move(d);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/assign_scalar.h>

const char* ds_assign_scalar = R"igl_Qu8mg5v7(
See assign_scalar for the documentation.
)igl_Qu8mg5v7";

npe_function(assign_scalar)
npe_doc(ds_assign_scalar)

npe_arg(cgal, CGAL::Epeck::FT &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    double & d;
    igl::    copyleft::    cgal::assign_scalar(cgal, d);
    return npe::move(d);
} else if (dtype.type() == npe::type_f64) {
    double & d;
    igl::    copyleft::    cgal::assign_scalar(cgal, d);
    return npe::move(d);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/assign_scalar.h>

const char* ds_assign_scalar = R"igl_Qu8mg5v7(
See assign_scalar for the documentation.
)igl_Qu8mg5v7";

npe_function(assign_scalar)
npe_doc(ds_assign_scalar)

npe_arg(cgal, CGAL::Epeck::FT &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    float & d;
    igl::    copyleft::    cgal::assign_scalar(cgal, d);
    return npe::move(d);
} else if (dtype.type() == npe::type_f64) {
    float & d;
    igl::    copyleft::    cgal::assign_scalar(cgal, d);
    return npe::move(d);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/assign_scalar.h>

const char* ds_assign_scalar = R"igl_Qu8mg5v7(
See assign_scalar for the documentation.
)igl_Qu8mg5v7";

npe_function(assign_scalar)
npe_doc(ds_assign_scalar)

npe_arg(c, double &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    double & d;
    igl::    copyleft::    cgal::assign_scalar(c, d);
    return npe::move(d);
} else if (dtype.type() == npe::type_f64) {
    double & d;
    igl::    copyleft::    cgal::assign_scalar(c, d);
    return npe::move(d);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/assign_scalar.h>

const char* ds_assign_scalar = R"igl_Qu8mg5v7(
See assign_scalar for the documentation.
)igl_Qu8mg5v7";

npe_function(assign_scalar)
npe_doc(ds_assign_scalar)

npe_arg(c, float &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    float & d;
    igl::    copyleft::    cgal::assign_scalar(c, d);
    return npe::move(d);
} else if (dtype.type() == npe::type_f64) {
    float & d;
    igl::    copyleft::    cgal::assign_scalar(c, d);
    return npe::move(d);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/assign_scalar.h>

const char* ds_assign_scalar = R"igl_Qu8mg5v7(
See assign_scalar for the documentation.
)igl_Qu8mg5v7";

npe_function(assign_scalar)
npe_doc(ds_assign_scalar)

npe_arg(c, float &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    double & d;
    igl::    copyleft::    cgal::assign_scalar(c, d);
    return npe::move(d);
} else if (dtype.type() == npe::type_f64) {
    double & d;
    igl::    copyleft::    cgal::assign_scalar(c, d);
    return npe::move(d);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/assign_scalar.h>

const char* ds_assign_scalar = R"igl_Qu8mg5v7(
See assign_scalar for the documentation.
)igl_Qu8mg5v7";

npe_function(assign_scalar)
npe_doc(ds_assign_scalar)

npe_arg(cgal, CGAL::Exact_predicates_exact_constructions_kernel_with_sqrt::FT &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    CGAL::Exact_predicates_exact_constructions_kernel_with_sqrt::FT & d;
    igl::    copyleft::    cgal::assign_scalar(cgal, d);
    return npe::move(d);
} else if (dtype.type() == npe::type_f64) {
    CGAL::Exact_predicates_exact_constructions_kernel_with_sqrt::FT & d;
    igl::    copyleft::    cgal::assign_scalar(cgal, d);
    return npe::move(d);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/assign_scalar.h>

const char* ds_assign_scalar = R"igl_Qu8mg5v7(
See assign_scalar for the documentation.
)igl_Qu8mg5v7";

npe_function(assign_scalar)
npe_doc(ds_assign_scalar)

npe_arg(cgal, CGAL::Exact_predicates_exact_constructions_kernel_with_sqrt::FT &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    double & d;
    igl::    copyleft::    cgal::assign_scalar(cgal, d);
    return npe::move(d);
} else if (dtype.type() == npe::type_f64) {
    double & d;
    igl::    copyleft::    cgal::assign_scalar(cgal, d);
    return npe::move(d);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/assign_scalar.h>

const char* ds_assign_scalar = R"igl_Qu8mg5v7(
See assign_scalar for the documentation.
)igl_Qu8mg5v7";

npe_function(assign_scalar)
npe_doc(ds_assign_scalar)

npe_arg(cgal, CGAL::Exact_predicates_exact_constructions_kernel_with_sqrt::FT &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    float & d;
    igl::    copyleft::    cgal::assign_scalar(cgal, d);
    return npe::move(d);
} else if (dtype.type() == npe::type_f64) {
    float & d;
    igl::    copyleft::    cgal::assign_scalar(cgal, d);
    return npe::move(d);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/assign_scalar.h>

const char* ds_assign_scalar = R"igl_Qu8mg5v7(
See assign_scalar for the documentation.
)igl_Qu8mg5v7";

npe_function(assign_scalar)
npe_doc(ds_assign_scalar)

npe_arg(cgal, CGAL::Simple_cartesian<mpq_class>::FT &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    CGAL::Simple_cartesian<mpq_class>::FT & d;
    igl::    copyleft::    cgal::assign_scalar(cgal, d);
    return npe::move(d);
} else if (dtype.type() == npe::type_f64) {
    CGAL::Simple_cartesian<mpq_class>::FT & d;
    igl::    copyleft::    cgal::assign_scalar(cgal, d);
    return npe::move(d);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/assign_scalar.h>

const char* ds_assign_scalar = R"igl_Qu8mg5v7(
See assign_scalar for the documentation.
)igl_Qu8mg5v7";

npe_function(assign_scalar)
npe_doc(ds_assign_scalar)

npe_arg(cgal, CGAL::Simple_cartesian<mpq_class>::FT &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    double & d;
    igl::    copyleft::    cgal::assign_scalar(cgal, d);
    return npe::move(d);
} else if (dtype.type() == npe::type_f64) {
    double & d;
    igl::    copyleft::    cgal::assign_scalar(cgal, d);
    return npe::move(d);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/assign_scalar.h>

const char* ds_assign_scalar = R"igl_Qu8mg5v7(
See assign_scalar for the documentation.
)igl_Qu8mg5v7";

npe_function(assign_scalar)
npe_doc(ds_assign_scalar)

npe_arg(cgal, CGAL::Simple_cartesian<mpq_class>::FT &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    float & d;
    igl::    copyleft::    cgal::assign_scalar(cgal, d);
    return npe::move(d);
} else if (dtype.type() == npe::type_f64) {
    float & d;
    igl::    copyleft::    cgal::assign_scalar(cgal, d);
    return npe::move(d);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


