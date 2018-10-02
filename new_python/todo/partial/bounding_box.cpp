// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/bounding_box.h>

const char* ds_bounding_box = R"igl_Qu8mg5v7(

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

 Build a triangle mesh of the bounding box of a given list of vertices
   
   Inputs:
     V  #V by dim list of rest domain positions
   Outputs:
     BV  2^dim by dim list of bounding box corners positions
     BF  #BF by dim list of simplex facets 
)igl_Qu8mg5v7";

npe_function(bounding_box)
npe_doc(ds_bounding_box)

npe_arg(v, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 bv;
    dense_f32 bf;
    igl::bounding_box(v, bv, bf);
    return std::make_tuple(    npe::move(bv),
    npe::move(bf));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 bv;
    dense_f64 bf;
    igl::bounding_box(v, bv, bf);
    return std::make_tuple(    npe::move(bv),     npe::move(bf));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/bounding_box.h>

const char* ds_bounding_box = R"igl_Qu8mg5v7(
See bounding_box for the documentation.
)igl_Qu8mg5v7";

npe_function(bounding_box)
npe_doc(ds_bounding_box)

npe_arg(v, dense_f64)
npe_arg(pad, typename DerivedV::Scalar)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 bv;
    dense_f32 bf;
    igl::bounding_box(v, pad, bv, bf);
    return std::make_tuple(    npe::move(bv),
    npe::move(bf));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 bv;
    dense_f64 bf;
    igl::bounding_box(v, pad, bv, bf);
    return std::make_tuple(    npe::move(bv),     npe::move(bf));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


