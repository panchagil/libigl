// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/triangle_triangle_adjacency.h>

const char* ds_triangle_triangle_adjacency = R"igl_Qu8mg5v7(

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

 Constructs the triangle-triangle adjacency matrix for a given
   mesh (V,F).
  
   Inputs:
     F  #F by simplex_size list of mesh faces (must be triangles)
   Outputs:
     TT   #F by #3 adjacent matrix, the element i,j is the id of the triangle
          adjacent to the j edge of triangle i
     TTi  #F by #3 adjacent matrix, the element i,j is the id of edge of the
          triangle TT(i,j) that is adjacent with triangle i
  
   NOTE: the first edge of a triangle is [0,1] the second [1,2] and the third
         [2,3].  this convention is DIFFERENT from cotmatrix_entries.h
)igl_Qu8mg5v7";

npe_function(triangle_triangle_adjacency)
npe_doc(ds_triangle_triangle_adjacency)

npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 tt;
    dense_f32 t_ti;
    igl::triangle_triangle_adjacency(f, tt, t_ti);
    return std::make_tuple(    npe::move(tt),
    npe::move(t_ti));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 tt;
    dense_f64 t_ti;
    igl::triangle_triangle_adjacency(f, tt, t_ti);
    return std::make_tuple(    npe::move(tt),     npe::move(t_ti));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/triangle_triangle_adjacency.h>

const char* ds_triangle_triangle_adjacency = R"igl_Qu8mg5v7(
See triangle_triangle_adjacency for the documentation.
)igl_Qu8mg5v7";

npe_function(triangle_triangle_adjacency)
npe_doc(ds_triangle_triangle_adjacency)

npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 tt;
    igl::triangle_triangle_adjacency(f, tt);
    return npe::move(tt);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 tt;
    igl::triangle_triangle_adjacency(f, tt);
    return npe::move(tt);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/triangle_triangle_adjacency_preprocess.h>

const char* ds_triangle_triangle_adjacency_preprocess = R"igl_Qu8mg5v7(

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

 Preprocessing
)igl_Qu8mg5v7";

npe_function(triangle_triangle_adjacency_preprocess)
npe_doc(ds_triangle_triangle_adjacency_preprocess)

npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<TTT_type> > & ttt;
    igl::triangle_triangle_adjacency_preprocess(f, ttt);
    return npe::move(ttt);
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<TTT_type> > & ttt;
    igl::triangle_triangle_adjacency_preprocess(f, ttt);
    return npe::move(ttt);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/triangle_triangle_adjacency_extractTT.h>

const char* ds_triangle_triangle_adjacency_extract_tt = R"igl_Qu8mg5v7(

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

 Extract the face adjacencies
)igl_Qu8mg5v7";

npe_function(triangle_triangle_adjacency_extract_tt)
npe_doc(ds_triangle_triangle_adjacency_extract_tt)

npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<TTT_type> > & ttt;
    dense_f32 tt;
    igl::triangle_triangle_adjacency_extractTT(f, ttt, tt);
    return std::make_tuple(    npe::move(ttt),
    npe::move(tt));
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<TTT_type> > & ttt;
    dense_f64 tt;
    igl::triangle_triangle_adjacency_extractTT(f, ttt, tt);
    return std::make_tuple(    npe::move(ttt),     npe::move(tt));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/triangle_triangle_adjacency_extractTTi.h>

const char* ds_triangle_triangle_adjacency_extract_t_ti = R"igl_Qu8mg5v7(

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

 Extract the face adjacencies indices (needed for fast traversal)
)igl_Qu8mg5v7";

npe_function(triangle_triangle_adjacency_extract_t_ti)
npe_doc(ds_triangle_triangle_adjacency_extract_t_ti)

npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<TTT_type> > & ttt;
    dense_f32 t_ti;
    igl::triangle_triangle_adjacency_extractTTi(f, ttt, t_ti);
    return std::make_tuple(    npe::move(ttt),
    npe::move(t_ti));
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<TTT_type> > & ttt;
    dense_f64 t_ti;
    igl::triangle_triangle_adjacency_extractTTi(f, ttt, t_ti);
    return std::make_tuple(    npe::move(ttt),     npe::move(t_ti));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/triangle_triangle_adjacency.h>

const char* ds_triangle_triangle_adjacency = R"igl_Qu8mg5v7(

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

 Adjacency list version, which works with non-manifold meshes
  
   Inputs:
     F  #F by 3 list of triangle indices
   Outputs:
     TT  #F by 3 list of lists so that TT[i][c] --> {j,k,...} means that
       faces j and k etc. are edge-neighbors of face i on face i's edge
       opposite corner c
     TTj  #F list of lists so that TTj[i][c] --> {j,k,...} means that face
       TT[i][c][0] is an edge-neighbor of face i incident on the edge of face
       TT[i][c][0] opposite corner j, and TT[i][c][1] " corner k, etc.
)igl_Qu8mg5v7";

npe_function(triangle_triangle_adjacency)
npe_doc(ds_triangle_triangle_adjacency)

npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<std::vector<TTIndex> > > & tt;
    std::vector<std::vector<std::vector<TTiIndex> > > & t_ti;
    igl::triangle_triangle_adjacency(f, tt, t_ti);
    return std::make_tuple(    npe::move(tt),
    npe::move(t_ti));
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<std::vector<TTIndex> > > & tt;
    std::vector<std::vector<std::vector<TTiIndex> > > & t_ti;
    igl::triangle_triangle_adjacency(f, tt, t_ti);
    return std::make_tuple(    npe::move(tt),     npe::move(t_ti));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/triangle_triangle_adjacency.h>

const char* ds_triangle_triangle_adjacency = R"igl_Qu8mg5v7(
See triangle_triangle_adjacency for the documentation.
)igl_Qu8mg5v7";

npe_function(triangle_triangle_adjacency)
npe_doc(ds_triangle_triangle_adjacency)

npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<std::vector<TTIndex> > > & tt;
    igl::triangle_triangle_adjacency(f, tt);
    return npe::move(tt);
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<std::vector<TTIndex> > > & tt;
    igl::triangle_triangle_adjacency(f, tt);
    return npe::move(tt);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/triangle_triangle_adjacency.h>

const char* ds_triangle_triangle_adjacency = R"igl_Qu8mg5v7(

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

 Wrapper with bool to choose whether to compute TTi (this prototype should
   be "hidden").
)igl_Qu8mg5v7";

npe_function(triangle_triangle_adjacency)
npe_doc(ds_triangle_triangle_adjacency)

npe_arg(f, dense_i32)
npe_arg(construct_t_ti, bool)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<std::vector<TTIndex> > > & tt;
    std::vector<std::vector<std::vector<TTiIndex> > > & t_ti;
    igl::triangle_triangle_adjacency(f, construct_t_ti, tt, t_ti);
    return std::make_tuple(    npe::move(tt),
    npe::move(t_ti));
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<std::vector<TTIndex> > > & tt;
    std::vector<std::vector<std::vector<TTiIndex> > > & t_ti;
    igl::triangle_triangle_adjacency(f, construct_t_ti, tt, t_ti);
    return std::make_tuple(    npe::move(tt),     npe::move(t_ti));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/triangle_triangle_adjacency.h>

const char* ds_triangle_triangle_adjacency = R"igl_Qu8mg5v7(

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
     E  #F*3 by 2 list of all of directed edges in order (see
       `oriented_facets`)
     EMAP #F*3 list of indices into uE, mapping each directed edge to unique
       undirected edge
     uE2E  #uE list of lists of indices into E of coexisting edges
   See also: unique_edge_map, oriented_facets
)igl_Qu8mg5v7";

npe_function(triangle_triangle_adjacency)
npe_doc(ds_triangle_triangle_adjacency)

npe_arg(e, dense_f64)
npe_arg(emap, dense_f64)
npe_arg(u_e2_e, std::vector<std::vector<uE2EType> > &)
npe_arg(construct_t_ti, bool)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<std::vector<TTIndex> > > & tt;
    std::vector<std::vector<std::vector<TTiIndex> > > & t_ti;
    igl::triangle_triangle_adjacency(e, emap, u_e2_e, construct_t_ti, tt, t_ti);
    return std::make_tuple(    npe::move(tt),
    npe::move(t_ti));
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<std::vector<TTIndex> > > & tt;
    std::vector<std::vector<std::vector<TTiIndex> > > & t_ti;
    igl::triangle_triangle_adjacency(e, emap, u_e2_e, construct_t_ti, tt, t_ti);
    return std::make_tuple(    npe::move(tt),     npe::move(t_ti));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


