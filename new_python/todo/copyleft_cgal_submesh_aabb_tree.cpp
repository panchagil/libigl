// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/submesh_aabb_tree.h>

const char* ds_submesh_aabb_tree = R"igl_Qu8mg5v7(

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

 Build an AABB tree for a submesh indicated by a face selection list I
       of a full mesh (V,F)
      
       Inputs:
         V  #V by 3 array of vertices.
         F  #F by 3 array of faces.
         I  #I list of triangle indices to consider.
       Outputs:
         tree  aabb containing triangles of (V,F(I,:))
         triangles  #I list of cgal triangles
         in_I  #F list of whether in submesh
)igl_Qu8mg5v7";

npe_function(submesh_aabb_tree)
npe_doc(ds_submesh_aabb_tree)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(i, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    CGAL::AABB_tree<CGAL::AABB_traits<Kernel, CGAL::AABB_triangle_primitive<Kernel, typename std::vector<typename Kernel::Triangle_3>::iterator> > > & tree;
    std::vector<typename Kernel::Triangle_3> & triangles;
    std::vector<bool> & in_i;
    igl::    copyleft::    cgal::submesh_aabb_tree(v, f, i, tree, triangles, in_i);
    return std::make_tuple(    npe::move(tree),
    npe::move(triangles),
    npe::move(in_i));
} else if (dtype.type() == npe::type_f64) {
    CGAL::AABB_tree<CGAL::AABB_traits<Kernel, CGAL::AABB_triangle_primitive<Kernel, typename std::vector<typename Kernel::Triangle_3>::iterator> > > & tree;
    std::vector<typename Kernel::Triangle_3> & triangles;
    std::vector<bool> & in_i;
    igl::    copyleft::    cgal::submesh_aabb_tree(v, f, i, tree, triangles, in_i);
    return std::make_tuple(    npe::move(tree),     npe::move(triangles),     npe::move(in_i));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


