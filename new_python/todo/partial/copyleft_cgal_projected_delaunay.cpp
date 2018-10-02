// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/projected_delaunay.h>

const char* ds_projected_delaunay = R"igl_Qu8mg5v7(

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

 Compute 2D delaunay triangulation of a given 3d triangle and a list of
       intersection objects (points,segments,triangles). CGAL uses an affine
       projection rather than an isometric projection, so we're not guaranteed
       that the 2D delaunay triangulation here will be a delaunay triangulation
       in 3D.
      
       Inputs:
         A  triangle in 3D
         A_objects_3  updated list of intersection objects for A
       Outputs:
         cdt  Contrained delaunay triangulation in projected 2D plane
)igl_Qu8mg5v7";

npe_function(projected_delaunay)
npe_doc(ds_projected_delaunay)

npe_arg(a, CGAL::Triangle_3<Kernel> &)
npe_arg(a_objects_3, std::vector<CGAL::Object> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    CGAL::Constrained_triangulation_plus_2<CGAL::Constrained_Delaunay_triangulation_2<Kernel, CGAL::Triangulation_data_structure_2<CGAL::Triangulation_vertex_base_2<Kernel>, CGAL::Constrained_triangulation_face_base_2<Kernel> >, CGAL::Exact_intersections_tag> > & cdt;
    igl::    copyleft::    cgal::projected_delaunay(a, a_objects_3, cdt);
    return npe::move(cdt);
} else if (dtype.type() == npe::type_f64) {
    CGAL::Constrained_triangulation_plus_2<CGAL::Constrained_Delaunay_triangulation_2<Kernel, CGAL::Triangulation_data_structure_2<CGAL::Triangulation_vertex_base_2<Kernel>, CGAL::Constrained_triangulation_face_base_2<Kernel> >, CGAL::Exact_intersections_tag> > & cdt;
    igl::    copyleft::    cgal::projected_delaunay(a, a_objects_3, cdt);
    return npe::move(cdt);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


