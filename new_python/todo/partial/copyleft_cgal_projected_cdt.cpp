// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/projected_cdt.h>

const char* ds_projected_cdt = R"igl_Qu8mg5v7(

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

 Given a list of objects (e.g., resulting from intersecting a triangle
       with many other triangles), construct a constrained Delaunay
       triangulation on a given plane (P), by inersting constraints for each
       object projected onto that plane.
      
       Inputs:
         objects  list of objects. This should lie on the given plane (P),
           otherwise they are added to the cdt _after_ their non-trivial
           projection
         P  plane upon which all objects lie and upon which the CDT is
           conducted
       Outputs:
         vertices  list of vertices of the CDT mesh _back on the 3D plane_
         faces  list of list of triangle indices into vertices
      
)igl_Qu8mg5v7";

npe_function(projected_cdt)
npe_doc(ds_projected_cdt)

npe_arg(objects, std::vector<CGAL::Object> &)
npe_arg(p, CGAL::Plane_3<Kernel> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<CGAL::Point_3<Kernel> > & vertices;
    std::vector<std::vector<int> > & faces;
    igl::    copyleft::    cgal::projected_cdt(objects, p, vertices, faces);
    return std::make_tuple(    npe::move(vertices),
    npe::move(faces));
} else if (dtype.type() == npe::type_f64) {
    std::vector<CGAL::Point_3<Kernel> > & vertices;
    std::vector<std::vector<int> > & faces;
    igl::    copyleft::    cgal::projected_cdt(objects, p, vertices, faces);
    return std::make_tuple(    npe::move(vertices),     npe::move(faces));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/projected_cdt.h>

const char* ds_projected_cdt = R"igl_Qu8mg5v7(

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

 Outputs:
         V  #V by 3 list of vertices of the CDT mesh _back on the 3D plane_,
           **cast** from the number type of Kernel to the number type of
           DerivedV
         F  #F by 3 list of triangle indices into V
)igl_Qu8mg5v7";

npe_function(projected_cdt)
npe_doc(ds_projected_cdt)

npe_arg(objects, std::vector<CGAL::Object> &)
npe_arg(p, CGAL::Plane_3<Kernel> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v;
    dense_i32 f;
    igl::    copyleft::    cgal::projected_cdt(objects, p, v, f);
    return std::make_tuple(    npe::move(v),
    npe::move(f));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v;
    dense_i32 f;
    igl::    copyleft::    cgal::projected_cdt(objects, p, v, f);
    return std::make_tuple(    npe::move(v),     npe::move(f));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


