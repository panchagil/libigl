// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/insert_into_cdt.h>

const char* ds_insert_into_cdt = R"igl_Qu8mg5v7(

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

 Given a current 2D constrained Delaunay triangulation (cdt), insert a
       3D "object" (e.g., resulting from intersecting two triangles) into the
       cdt, by projecting it via the given plane (P) and adding appropriate
       constraints.
      
       Inputs:
         obj  CGAL::Object representing a vertex, segment, or (convex)
           polygon. All vertices should lie on the plane P. If not, then this
           adds the _projection_ of this object to the cdt and that might not
           be what you wanted to do.
         P  plane obj lies on and upon which the cdt is being performed
         cdt  current CDT, see output
       Outputs:
         cdt  CDT updated to contain constraints for the given object
      
)igl_Qu8mg5v7";

npe_function(insert_into_cdt)
npe_doc(ds_insert_into_cdt)

npe_arg(obj, CGAL::Object &)
npe_arg(p, CGAL::Plane_3<Kernel> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    CGAL::Constrained_triangulation_plus_2<CGAL::Constrained_Delaunay_triangulation_2<Kernel, CGAL::Triangulation_data_structure_2<CGAL::Triangulation_vertex_base_2<Kernel>, CGAL::Constrained_triangulation_face_base_2<Kernel> >, CGAL::Exact_intersections_tag> > & cdt;
    igl::    copyleft::    cgal::insert_into_cdt(obj, p, cdt);
    return npe::move(cdt);
} else if (dtype.type() == npe::type_f64) {
    CGAL::Constrained_triangulation_plus_2<CGAL::Constrained_Delaunay_triangulation_2<Kernel, CGAL::Triangulation_data_structure_2<CGAL::Triangulation_vertex_base_2<Kernel>, CGAL::Constrained_triangulation_face_base_2<Kernel> >, CGAL::Exact_intersections_tag> > & cdt;
    igl::    copyleft::    cgal::insert_into_cdt(obj, p, cdt);
    return npe::move(cdt);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


