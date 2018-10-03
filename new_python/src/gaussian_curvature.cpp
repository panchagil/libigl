#include <npe.h>
#include <typedefs.h>
#include <igl/gaussian_curvature.h>

const char* ds_gaussian_curvature = R"igl_Qu8mg5v7(
Compute discrete local integral gaussian curvature (angle deficit, without
averaging by local area).

Parameters
----------
v  #v by 3 array of mesh vertex 3D positions
f  #f by 3 array of face (triangle) indices
dtype : data-type of the returned objects, optional. Default is `float64`.
        (All integer return types are `int32` by default.)

Returns
-------
k  #v by 1 array of discrete gaussian curvature values

See also
--------
principal_curvature

Notes
-----
None

Examples
--------
# Mesh in (v, f)
>>> k = gaussian_curvature(v, f)
)igl_Qu8mg5v7";

npe_function(gaussian_curvature)
npe_doc(ds_gaussian_curvature)

npe_arg(v, dense_f64, dense_f32)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()

if (dtype.type() == npe::type_f32) {
    EigenDenseF32 k;
    igl::gaussian_curvature(v, f, k);
    return npe::move(k);
} else if (dtype.type() == npe::type_f64) {
    EigenDenseF64 k;
    igl::gaussian_curvature(v, f, k);
    return npe::move(k);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


