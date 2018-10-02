// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/intersect_other.h>

const char* ds_intersect_other = R"igl_Qu8mg5v7(

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

 INTERSECT_OTHER Given a triangle mesh (VA,FA) and another mesh (VB,FB)
       find all pairs of intersecting faces. Note that self-intersections are
       ignored.
       
       Inputs:
         VA  #V by 3 list of vertex positions
         FA  #F by 3 list of triangle indices into VA
         VB  #V by 3 list of vertex positions
         FB  #F by 3 list of triangle indices into VB
         params   whether to detect only and then whether to only find first
           intersection
       Outputs:
         IF  #intersecting face pairs by 2 list of intersecting face pairs,
           indexing FA and FB
         VVAB  #VVAB by 3 list of vertex positions
         FFAB  #FFAB by 3 list of triangle indices into VVA
         JAB  #FFAB list of indices into [FA;FB] denoting birth triangle
         IMAB  #VVAB list of indices stitching duplicates (resulting from
           mesh intersections) together
)igl_Qu8mg5v7";

npe_function(intersect_other)
npe_doc(ds_intersect_other)

npe_arg(va, dense_f64)
npe_arg(fa, dense_f64)
npe_arg(vb, dense_f64)
npe_arg(fb, dense_f64)
npe_arg(params, igl::copyleft::cgal::RemeshSelfIntersectionsParam &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 if;
    dense_f32 vvab;
    dense_f32 ffab;
    dense_f32 jab;
    dense_f32 imab;
    igl::    copyleft::    cgal::intersect_other(va, fa, vb, fb, params, if, vvab, ffab, jab, imab);
    return std::make_tuple(    npe::move(if),
    npe::move(vvab),
    npe::move(ffab),
    npe::move(jab),
    npe::move(imab));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 if;
    dense_f64 vvab;
    dense_f64 ffab;
    dense_f64 jab;
    dense_f64 imab;
    igl::    copyleft::    cgal::intersect_other(va, fa, vb, fb, params, if, vvab, ffab, jab, imab);
    return std::make_tuple(    npe::move(if),     npe::move(vvab),     npe::move(ffab),     npe::move(jab),     npe::move(imab));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/intersect_other.h>

const char* ds_intersect_other = R"igl_Qu8mg5v7(

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

 Legacy wrapper for detect only using common types.
      
       Inputs:
         VA  #V by 3 list of vertex positions
         FA  #F by 3 list of triangle indices into VA
         VB  #V by 3 list of vertex positions
         FB  #F by 3 list of triangle indices into VB
         first_only  whether to only detect the first intersection.
       Outputs:
         IF  #intersecting face pairs by 2 list of intersecting face pairs,
           indexing FA and FB
       Returns true if any intersections were found
      
       See also: remesh_self_intersections
)igl_Qu8mg5v7";

npe_function(intersect_other)
npe_doc(ds_intersect_other)

npe_arg(va, Eigen::MatrixXd &)
npe_arg(fa, Eigen::MatrixXi &)
npe_arg(vb, Eigen::MatrixXd &)
npe_arg(fb, Eigen::MatrixXi &)
npe_arg(first_only, bool)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::MatrixXi & if;
    igl::    copyleft::    cgal::intersect_other(va, fa, vb, fb, first_only, if);
    return npe::move(if);
} else if (dtype.type() == npe::type_f64) {
    Eigen::MatrixXi & if;
    igl::    copyleft::    cgal::intersect_other(va, fa, vb, fb, first_only, if);
    return npe::move(if);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


