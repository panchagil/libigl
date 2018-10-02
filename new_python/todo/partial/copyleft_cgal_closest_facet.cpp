// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/closest_facet.h>

const char* ds_closest_facet = R"igl_Qu8mg5v7(

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

 Determine the closest facet for each of the input points.
      
       Inputs:
         V  #V by 3 array of vertices.
         F  #F by 3 array of faces.
         I  #I list of triangle indices to consider.
         P  #P by 3 array of query points.
      
       Outputs:
         R  #P list of closest facet indices.
         S  #P list of bools indicating on which side of the closest facet
            each query point lies.
)igl_Qu8mg5v7";

npe_function(closest_facet)
npe_doc(ds_closest_facet)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(i, dense_f64)
npe_arg(p, dense_f64)
npe_arg(u_e2_e, std::vector<std::vector<uE2EType> > &)
npe_arg(emap, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 r;
    dense_f32 s;
    igl::    copyleft::    cgal::closest_facet(v, f, i, p, u_e2_e, emap, r, s);
    return std::make_tuple(    npe::move(r),
    npe::move(s));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 r;
    dense_f64 s;
    igl::    copyleft::    cgal::closest_facet(v, f, i, p, u_e2_e, emap, r, s);
    return std::make_tuple(    npe::move(r),     npe::move(s));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/closest_facet.h>

const char* ds_closest_facet = R"igl_Qu8mg5v7(
See closest_facet for the documentation.
)igl_Qu8mg5v7";

npe_function(closest_facet)
npe_doc(ds_closest_facet)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(p, dense_f64)
npe_arg(u_e2_e, std::vector<std::vector<uE2EType> > &)
npe_arg(emap, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 r;
    dense_f32 s;
    igl::    copyleft::    cgal::closest_facet(v, f, p, u_e2_e, emap, r, s);
    return std::make_tuple(    npe::move(r),
    npe::move(s));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 r;
    dense_f64 s;
    igl::    copyleft::    cgal::closest_facet(v, f, p, u_e2_e, emap, r, s);
    return std::make_tuple(    npe::move(r),     npe::move(s));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/closest_facet.h>

const char* ds_closest_facet = R"igl_Qu8mg5v7(
See closest_facet for the documentation.
)igl_Qu8mg5v7";

npe_function(closest_facet)
npe_doc(ds_closest_facet)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(i, dense_f64)
npe_arg(p, dense_f64)
npe_arg(u_e2_e, std::vector<std::vector<uE2EType> > &)
npe_arg(emap, dense_f64)
npe_arg(vf, std::vector<std::vector<size_t> > &)
npe_arg(v_fi, std::vector<std::vector<size_t> > &)
npe_arg(tree, CGAL::AABB_tree<CGAL::AABB_traits<Kernel, CGAL::AABB_triangle_primitive<Kernel, typename std::vector<typename Kernel::Triangle_3>::iterator> > > &)
npe_arg(triangles, std::vector<typename Kernel::Triangle_3> &)
npe_arg(in_i, std::vector<bool> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 r;
    dense_f32 s;
    igl::    copyleft::    cgal::closest_facet(v, f, i, p, u_e2_e, emap, vf, v_fi, tree, triangles, in_i, r, s);
    return std::make_tuple(    npe::move(r),
    npe::move(s));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 r;
    dense_f64 s;
    igl::    copyleft::    cgal::closest_facet(v, f, i, p, u_e2_e, emap, vf, v_fi, tree, triangles, in_i, r, s);
    return std::make_tuple(    npe::move(r),     npe::move(s));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


