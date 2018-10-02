// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/point_mesh_squared_distance.h>

const char* ds_point_mesh_squared_distance = R"igl_Qu8mg5v7(

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

 Compute distances from a set of points P to a triangle mesh (V,F)
      
       Templates:
         Kernal  CGAL computation and construction kernel (e.g.
           CGAL::Simple_cartesian<double>)
       Inputs:
         P  #P by 3 list of query point positions
         V  #V by 3 list of vertex positions
         F  #F by 3 list of triangle indices
       Outputs:
         sqrD  #P list of smallest squared distances
         I  #P list of facet indices corresponding to smallest distances
         C  #P by 3 list of closest points
      
       Known bugs: This only computes distances to triangles. So unreferenced
       vertices and degenerate triangles (segments) are ignored.
)igl_Qu8mg5v7";

npe_function(point_mesh_squared_distance)
npe_doc(ds_point_mesh_squared_distance)

npe_arg(p, dense_f64)
npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 sqr_d;
    dense_f32 i;
    dense_f32 c;
    igl::    copyleft::    cgal::point_mesh_squared_distance(p, v, f, sqr_d, i, c);
    return std::make_tuple(    npe::move(sqr_d),
    npe::move(i),
    npe::move(c));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 sqr_d;
    dense_f64 i;
    dense_f64 c;
    igl::    copyleft::    cgal::point_mesh_squared_distance(p, v, f, sqr_d, i, c);
    return std::make_tuple(    npe::move(sqr_d),     npe::move(i),     npe::move(c));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/point_mesh_squared_distance_precompute.h>

const char* ds_point_mesh_squared_distance_precompute = R"igl_Qu8mg5v7(

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

 Probably can do this in a way that we don't pass around `tree` and `T`
      
       Outputs:
         tree  CGAL's AABB tree
         T  list of CGAL triangles in order of F (for determining which was found
           in computation)
)igl_Qu8mg5v7";

npe_function(point_mesh_squared_distance_precompute)
npe_doc(ds_point_mesh_squared_distance_precompute)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    CGAL::AABB_tree<CGAL::AABB_traits<Kernel, CGAL::AABB_triangle_primitive<Kernel, typename std::vector<CGAL::Triangle_3<Kernel> >::iterator> > > & tree;
    std::vector<CGAL::Triangle_3<Kernel> > & t;
    igl::    copyleft::    cgal::point_mesh_squared_distance_precompute(v, f, tree, t);
    return std::make_tuple(    npe::move(tree),
    npe::move(t));
} else if (dtype.type() == npe::type_f64) {
    CGAL::AABB_tree<CGAL::AABB_traits<Kernel, CGAL::AABB_triangle_primitive<Kernel, typename std::vector<CGAL::Triangle_3<Kernel> >::iterator> > > & tree;
    std::vector<CGAL::Triangle_3<Kernel> > & t;
    igl::    copyleft::    cgal::point_mesh_squared_distance_precompute(v, f, tree, t);
    return std::make_tuple(    npe::move(tree),     npe::move(t));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/point_mesh_squared_distance.h>

const char* ds_point_mesh_squared_distance = R"igl_Qu8mg5v7(

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

 Inputs:
        see above
       Outputs:
        see above
)igl_Qu8mg5v7";

npe_function(point_mesh_squared_distance)
npe_doc(ds_point_mesh_squared_distance)

npe_arg(p, dense_f64)
npe_arg(tree, CGAL::AABB_tree<CGAL::AABB_traits<Kernel, CGAL::AABB_triangle_primitive<Kernel, typename std::vector<CGAL::Triangle_3<Kernel> >::iterator> > > &)
npe_arg(t, std::vector<CGAL::Triangle_3<Kernel> > &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 sqr_d;
    dense_f32 i;
    dense_f32 c;
    igl::    copyleft::    cgal::point_mesh_squared_distance(p, tree, t, sqr_d, i, c);
    return std::make_tuple(    npe::move(sqr_d),
    npe::move(i),
    npe::move(c));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 sqr_d;
    dense_f64 i;
    dense_f64 c;
    igl::    copyleft::    cgal::point_mesh_squared_distance(p, tree, t, sqr_d, i, c);
    return std::make_tuple(    npe::move(sqr_d),     npe::move(i),     npe::move(c));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


