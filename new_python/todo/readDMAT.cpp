// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/readDMAT.h>

const char* ds_read_dmat = R"igl_Qu8mg5v7(
See readDMAT for the documentation.
)igl_Qu8mg5v7";

npe_function(read_dmat)
npe_doc(ds_read_dmat)

npe_arg(file_name, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 w;
    igl::readDMAT(file_name, w);
    return npe::move(w);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 w;
    igl::readDMAT(file_name, w);
    return npe::move(w);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/readDMAT.h>

const char* ds_read_dmat = R"igl_Qu8mg5v7(

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

 Wrapper for vector of vectors
)igl_Qu8mg5v7";

npe_function(read_dmat)
npe_doc(ds_read_dmat)

npe_arg(file_name, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<double> > & w;
    igl::readDMAT(file_name, w);
    return npe::move(w);
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<double> > & w;
    igl::readDMAT(file_name, w);
    return npe::move(w);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


