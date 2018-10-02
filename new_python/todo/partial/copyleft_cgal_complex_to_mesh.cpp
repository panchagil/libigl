// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/complex_to_mesh.h>

const char* ds_complex_to_mesh = R"igl_Qu8mg5v7(

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

 Templates:
         Tr  CGAL triangulation type, e.g.
           CGAL::Surface_mesh_default_triangulation_3
       Inputs
         c2t3  2-complex (surface) living in a 3d triangulation (e.g. result of
           CGAL::make_surface_mesh)
       Outputs:
         V  #V by 3 list of vertex positions
         F  #F by 3 list of triangle indices
       Returns true iff conversion was successful, failure can ok if CGAL code
       can't figure out ordering.
      
)igl_Qu8mg5v7";

npe_function(complex_to_mesh)
npe_doc(ds_complex_to_mesh)

npe_arg(c2t3, CGAL::Complex_2_in_triangulation_3<Tr> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v;
    dense_i32 f;
    igl::    copyleft::    cgal::complex_to_mesh(c2t3, v, f);
    return std::make_tuple(    npe::move(v),
    npe::move(f));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v;
    dense_i32 f;
    igl::    copyleft::    cgal::complex_to_mesh(c2t3, v, f);
    return std::make_tuple(    npe::move(v),     npe::move(f));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


