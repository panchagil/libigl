// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/mesh_to_cgal_triangle_list.h>

const char* ds_mesh_to_cgal_triangle_list = R"igl_Qu8mg5v7(

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

 Convert a mesh (V,F) to a list of CGAL triangles
      
       Templates:
         Kernal  CGAL computation and construction kernel (e.g.
           CGAL::Exact_predicates_exact_constructions_kernel)
       Inputs:
         V  #V by 3 list of vertex positions
         F  #F by 3 list of triangle indices
       Outputs:
         T  #F list of CGAL triangles
)igl_Qu8mg5v7";

npe_function(mesh_to_cgal_triangle_list)
npe_doc(ds_mesh_to_cgal_triangle_list)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<CGAL::Triangle_3<Kernel> > & t;
    igl::    copyleft::    cgal::mesh_to_cgal_triangle_list(v, f, t);
    return npe::move(t);
} else if (dtype.type() == npe::type_f64) {
    std::vector<CGAL::Triangle_3<Kernel> > & t;
    igl::    copyleft::    cgal::mesh_to_cgal_triangle_list(v, f, t);
    return npe::move(t);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


