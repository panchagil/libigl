// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/hausdorff.h>

const char* ds_hausdorff = R"igl_Qu8mg5v7(

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

 Compute lower and upper bounds (l,u) on the Hausdorff distance between a triangle
       (V) and a pointset (e.g., mesh, triangle soup) given by a distance function
       handle (dist_to_B).
      
       Inputs:
         V   3 by 3 list of corner positions so that V.row(i) is the position of the
           ith corner
         treeB  CGAL's AABB tree containing triangle soup (VB,FB)
         TB  list of CGAL triangles in order of FB (for determining which was found
           in computation)
       Outputs:
         l  lower bound on Hausdorff distance 
         u  upper bound on Hausdorff distance
      
)igl_Qu8mg5v7";

npe_function(hausdorff)
npe_doc(ds_hausdorff)

npe_arg(v, dense_f64)
npe_arg(tree_b, CGAL::AABB_tree<CGAL::AABB_traits<Kernel, CGAL::AABB_triangle_primitive<Kernel, typename std::vector<CGAL::Triangle_3<Kernel> >::iterator> > > &)
npe_arg(tb, std::vector<CGAL::Triangle_3<Kernel> > &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Scalar & l;
    Scalar & u;
    igl::    copyleft::    cgal::hausdorff(v, tree_b, tb, l, u);
    return std::make_tuple(    npe::move(l),
    npe::move(u));
} else if (dtype.type() == npe::type_f64) {
    Scalar & l;
    Scalar & u;
    igl::    copyleft::    cgal::hausdorff(v, tree_b, tb, l, u);
    return std::make_tuple(    npe::move(l),     npe::move(u));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


