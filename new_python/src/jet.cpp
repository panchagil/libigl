#include <npe.h>
#include <typedefs.h>
#include <igl/jet.h>

const char* ds_jet = R"igl_Qu8mg5v7(
JET like MATLAB's jet colorpalette.

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
parula

Notes
-----
None

Examples
--------
# Mesh in (v, f), extract z components
>>> z = v[:, 2]
>>> c = jet(z, True)
)igl_Qu8mg5v7";

npe_function(jet)
npe_doc(ds_jet)

npe_arg(z, dense_f64, dense_f64)
npe_arg(normalize, bool)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()

if (dtype.type() == npe::type_f32) {
    EigenDenseF32 c;
    igl::jet(z, normalize, c);
    return npe::move(c);
} else if (dtype.type() == npe::type_f64) {
    EigenDenseF64 c;
    igl::jet(z, normalize, c);
    return npe::move(c);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()

