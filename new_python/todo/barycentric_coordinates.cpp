#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/barycentric_coordinates.h>

const char* ds_barycentric_coordinates = R"igl_Qu8mg5v7(

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

 Compute barycentric coordinates in a tet
  
   Inputs:
     P  #P by 3 Query points in 3d
     A  #P by 3 Tet corners in 3d
     B  #P by 3 Tet corners in 3d
     C  #P by 3 Tet corners in 3d
     D  #P by 3 Tet corners in 3d
   Outputs:
     L  #P by 4 list of barycentric coordinates
     
)igl_Qu8mg5v7";

npe_function(barycentric_coordinates)
npe_doc(ds_barycentric_coordinates)

npe_arg(p, dense_f64)
npe_arg(a, dense_f64)
npe_arg(b, dense_f64)
npe_arg(c, dense_f64)
npe_arg(d, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 l;
    igl::barycentric_coordinates(p, a, b, c, d, l);
    return npe::move(l);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 l;
    igl::barycentric_coordinates(p, a, b, c, d, l);
    return npe::move(l);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/barycentric_coordinates.h>

const char* ds_barycentric_coordinates = R"igl_Qu8mg5v7(

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

 Compute barycentric coordinates in a triangle
  
   Inputs:
     P  #P by dim Query points
     A  #P by dim Triangle corners
     B  #P by dim Triangle corners
     C  #P by dim Triangle corners
   Outputs:
     L  #P by 3 list of barycentric coordinates
     
)igl_Qu8mg5v7";

npe_function(barycentric_coordinates)
npe_doc(ds_barycentric_coordinates)

npe_arg(p, dense_f64)
npe_arg(a, dense_f64)
npe_arg(b, dense_f64)
npe_arg(c, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 l;
    igl::barycentric_coordinates(p, a, b, c, l);
    return npe::move(l);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 l;
    igl::barycentric_coordinates(p, a, b, c, l);
    return npe::move(l);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


