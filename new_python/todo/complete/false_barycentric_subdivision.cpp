#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/false_barycentric_subdivision.h>

const char* ds_false_barycentric_subdivision = R"igl_Qu8mg5v7(

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

 Refine the mesh by adding the barycenter of each face
   Inputs:
     V       #V by 3 coordinates of the vertices
     F       #F by 3 list of mesh faces (must be triangles)
   Outputs:
     VD      #V + #F by 3 coordinate of the vertices of the dual mesh
             The added vertices are added at the end of VD (should not be
             same references as (V,F)
     FD      #F*3 by 3 faces of the dual mesh
  
)igl_Qu8mg5v7";

npe_function(false_barycentric_subdivision)
npe_doc(ds_false_barycentric_subdivision)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 vd;
    dense_f32 fd;
    igl::false_barycentric_subdivision(v, f, vd, fd);
    return std::make_tuple(    npe::move(vd),
    npe::move(fd));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 vd;
    dense_f64 fd;
    igl::false_barycentric_subdivision(v, f, vd, fd);
    return std::make_tuple(    npe::move(vd),     npe::move(fd));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


