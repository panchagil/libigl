// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/order_facets_around_edges.h>

const char* ds_order_facets_around_edges = R"igl_Qu8mg5v7(

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

 For each undirected edge, sort its adjacent faces.  Assuming the
       undirected edge is (s, d).  Sort the adjacent faces clockwise around the
       axis (d - s), i.e. left-hand rule.  An adjacent face is consistently
       oriented if it contains (d, s) as a directed edge.
      
       For overlapping faces, break the tie using signed face index, smaller
       signed index comes before the larger signed index.  Signed index is
       computed as (consistent? 1:-1) * index.
      
       Inputs:
         V    #V by 3 list of vertices.
         F    #F by 3 list of faces
         N    #F by 3 list of face normals.
        uE    #uE by 2 list of vertex_indices, represents undirected edges.
        uE2E  #uE list of lists that maps uE to E. (a one-to-many map)
      
       Outputs:
         uE2oE #uE list of lists that maps uE to an ordered list of E. (a
               one-to-many map)
         uE2C  #uE list of lists of bools indicates whether each face in
               uE2oE[i] is consistently orientated as the ordering.
      
)igl_Qu8mg5v7";

npe_function(order_facets_around_edges)
npe_doc(ds_order_facets_around_edges)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(n, dense_f64)
npe_arg(u_e, dense_f64)
npe_arg(u_e2_e, std::vector<std::vector<uE2EType> > &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<uE2oEType> > & u_e2o_e;
    std::vector<std::vector<uE2CType> > & u_e2_c;
    igl::    copyleft::    cgal::order_facets_around_edges(v, f, n, u_e, u_e2_e, u_e2o_e, u_e2_c);
    return std::make_tuple(    npe::move(u_e2o_e),
    npe::move(u_e2_c));
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<uE2oEType> > & u_e2o_e;
    std::vector<std::vector<uE2CType> > & u_e2_c;
    igl::    copyleft::    cgal::order_facets_around_edges(v, f, n, u_e, u_e2_e, u_e2o_e, u_e2_c);
    return std::make_tuple(    npe::move(u_e2o_e),     npe::move(u_e2_c));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/order_facets_around_edges.h>

const char* ds_order_facets_around_edges = R"igl_Qu8mg5v7(
See order_facets_around_edges for the documentation.
)igl_Qu8mg5v7";

npe_function(order_facets_around_edges)
npe_doc(ds_order_facets_around_edges)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(n, dense_f64)
npe_arg(u_e, dense_f64)
npe_arg(u_e2_e, std::vector<std::vector<uE2EType> > &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<uE2oEType> > & u_e2o_e;
    std::vector<std::vector<uE2CType> > & u_e2_c;
    igl::    copyleft::    cgal::order_facets_around_edges(v, f, n, u_e, u_e2_e, u_e2o_e, u_e2_c);
    return std::make_tuple(    npe::move(u_e2o_e),
    npe::move(u_e2_c));
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<uE2oEType> > & u_e2o_e;
    std::vector<std::vector<uE2CType> > & u_e2_c;
    igl::    copyleft::    cgal::order_facets_around_edges(v, f, n, u_e, u_e2_e, u_e2o_e, u_e2_c);
    return std::make_tuple(    npe::move(u_e2o_e),     npe::move(u_e2_c));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/order_facets_around_edges.h>

const char* ds_order_facets_around_edges = R"igl_Qu8mg5v7(

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

 Order faces around each edge. Only exact predicate is used in the algorithm.
       Normal is not needed.
)igl_Qu8mg5v7";

npe_function(order_facets_around_edges)
npe_doc(ds_order_facets_around_edges)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(u_e, dense_f64)
npe_arg(u_e2_e, std::vector<std::vector<uE2EType> > &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<uE2oEType> > & u_e2o_e;
    std::vector<std::vector<uE2CType> > & u_e2_c;
    igl::    copyleft::    cgal::order_facets_around_edges(v, f, u_e, u_e2_e, u_e2o_e, u_e2_c);
    return std::make_tuple(    npe::move(u_e2o_e),
    npe::move(u_e2_c));
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<uE2oEType> > & u_e2o_e;
    std::vector<std::vector<uE2CType> > & u_e2_c;
    igl::    copyleft::    cgal::order_facets_around_edges(v, f, u_e, u_e2_e, u_e2o_e, u_e2_c);
    return std::make_tuple(    npe::move(u_e2o_e),     npe::move(u_e2_c));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


