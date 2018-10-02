// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/polyhedron_to_mesh.h>

const char* ds_polyhedron_to_mesh = R"igl_Qu8mg5v7(

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

 Convert a CGAL Polyhedron to a mesh (V,F)
      
       Templates:
         Polyhedron  CGAL Polyhedron type (e.g. Polyhedron_3)
       Inputs:
         poly  cgal polyhedron
       Outputs:
         V  #V by 3 list of vertex positions
         F  #F by 3 list of triangle indices
)igl_Qu8mg5v7";

npe_function(polyhedron_to_mesh)
npe_doc(ds_polyhedron_to_mesh)

npe_arg(poly, Polyhedron &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v;
    dense_i32 f;
    igl::    copyleft::    cgal::polyhedron_to_mesh(poly, v, f);
    return std::make_tuple(    npe::move(v),
    npe::move(f));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v;
    dense_i32 f;
    igl::    copyleft::    cgal::polyhedron_to_mesh(poly, v, f);
    return std::make_tuple(    npe::move(v),     npe::move(f));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


