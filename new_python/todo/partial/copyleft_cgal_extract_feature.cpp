// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/extract_feature.h>

const char* ds_extract_feature = R"igl_Qu8mg5v7(

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

 Extract feature edges based on dihedral angle.
       Here, dihedral angle is defined as the angle between surface
       __normals__ as described in
       http:mathworld.wolfram.com/DihedralAngle.html
      
       Non-manifold and boundary edges are automatically considered as
       features.
      
       Inputs:
         V   #V by 3 array of vertices.
         F   #F by 3 array of faces.
         tol Edges with dihedral angle larger than this are considered
             as features.  Angle is measured in radian.
      
       Output:
         feature_edges: #E by 2 array of edges.  Each edge satisfies at
            least one of the following criteria:
      
            * Edge has dihedral angle larger than tol.
            * Edge is boundary.
            * Edge is non-manifold (i.e. it has more than 2 adjacent
              faces).
)igl_Qu8mg5v7";

npe_function(extract_feature)
npe_doc(ds_extract_feature)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(tol, double)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 feature_edges;
    igl::    copyleft::    cgal::extract_feature(v, f, tol, feature_edges);
    return npe::move(feature_edges);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 feature_edges;
    igl::    copyleft::    cgal::extract_feature(v, f, tol, feature_edges);
    return npe::move(feature_edges);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/extract_feature.h>

const char* ds_extract_feature = R"igl_Qu8mg5v7(

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
         V    #V by 3 array of vertices.
         F    #F by 3 array of faces.
         tol  Edges with dihedral angle larger than this are considered
              as features.  Angle is measured in radian.
         E    #E by 2 array of directed edges.
         uE   #uE by 2 array of undirected edges.
         uE2E #uE list of lists mapping undirected edges to all corresponding
              directed edges.
      
       Output:
         feature_edges: #E by 2 array of edges.  Each edge satisfies at
            least one of the following criteria:
      
            * Edge has dihedral angle larger than tol.
            * Edge is boundary.
            * Edge is non-manifold (i.e. it has more than 2 adjacent
              faces).
)igl_Qu8mg5v7";

npe_function(extract_feature)
npe_doc(ds_extract_feature)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(tol, double)
npe_arg(e, dense_f64)
npe_arg(u_e, dense_f64)
npe_arg(u_e2_e, std::vector<std::vector<typename DerivedE::Scalar> > &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 feature_edges;
    igl::    copyleft::    cgal::extract_feature(v, f, tol, e, u_e, u_e2_e, feature_edges);
    return npe::move(feature_edges);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 feature_edges;
    igl::    copyleft::    cgal::extract_feature(v, f, tol, e, u_e, u_e2_e, feature_edges);
    return npe::move(feature_edges);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


