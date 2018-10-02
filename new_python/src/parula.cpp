#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/parula.h>

const char* ds_parula = R"igl_Qu8mg5v7(
PARULA like MATLAB's parula colorpalette.

Parameters
----------
z : #z list of factors
normalize : whether to normalize Z to be tightly between [0, 1]
dtype : data-type of the returned objects, optional. Default is `float64`.
        (All integer return types are `int32` by default.)

Returns
-------
c : #c by 3 list of rgb colors

See also
--------
jet

Notes
-----
None

Examples
--------
# Mesh in (v, f), extract z components
>>> z = v[:, 2]
>>> c = parula(z, True)
)igl_Qu8mg5v7";

npe_function(parula)
npe_doc(ds_parula)

npe_arg(z, dense_f64)
npe_arg(normalize, bool)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;

if (dtype.type() == npe::type_f32) {
    Dense_f32 c;
    igl::parula(z, normalize, c);
    return npe::move(c);
} else if (dtype.type() == npe::type_f64) {
    Dense_f64 c;
    igl::parula(z, normalize, c);
    return npe::move(c);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
