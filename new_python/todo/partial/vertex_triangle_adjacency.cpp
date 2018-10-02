// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/vertex_triangle_adjacency.h>

const char* ds_vertex_triangle_adjacency = R"igl_Qu8mg5v7(

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
     F  #F by 3 list of triangle indices into some vertex list V
     n  number of vertices, #V (e.g., F.maxCoeff()+1)
   Outputs:
     VF  3*#F list  List of faces indice on each vertex, so that VF(NI(i)+j) =
       f, means that face f is the jth face (in no particular order) incident
       on vertex i.
     NI  #V+1 list  cumulative sum of vertex-triangle degrees with a
       preceeding zero. "How many faces" have been seen before visiting this
       vertex and its incident faces.
)igl_Qu8mg5v7";

npe_function(vertex_triangle_adjacency)
npe_doc(ds_vertex_triangle_adjacency)

npe_arg(f, dense_i32)
npe_arg(n, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 vf;
    dense_f32 ni;
    igl::vertex_triangle_adjacency(f, n, vf, ni);
    return std::make_tuple(    npe::move(vf),
    npe::move(ni));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 vf;
    dense_f64 ni;
    igl::vertex_triangle_adjacency(f, n, vf, ni);
    return std::make_tuple(    npe::move(vf),     npe::move(ni));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/vertex_triangle_adjacency.h>

const char* ds_vertex_triangle_adjacency = R"igl_Qu8mg5v7(

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

 vertex_face_adjacency constructs the vertex-face topology of a given mesh (V,F)
  
   Inputs:
     V  #V by 3 list of vertex coordinates
     n  number of vertices #V (e.g. `F.maxCoeff()+1` or `V.rows()`)
     F  #F by dim list of mesh faces (must be triangles)
   Outputs:
     VF  #V list of lists of incident faces (adjacency list)
     VI  #V list of lists of index of incidence within incident faces listed
       in VF
  
   See also: edges, cotmatrix, diag, vv
  
   Known bugs: this should not take V as an input parameter.
   Known bugs/features: if a facet is combinatorially degenerate then faces
   will appear multiple times in VF and correspondingly in VFI (j appears
   twice in F.row(i) then i will appear twice in VF[j])
)igl_Qu8mg5v7";

npe_function(vertex_triangle_adjacency)
npe_doc(ds_vertex_triangle_adjacency)

npe_arg(n, typename DerivedF::Scalar)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<VFType> > & vf;
    std::vector<std::vector<VFiType> > & v_fi;
    igl::vertex_triangle_adjacency(n, f, vf, v_fi);
    return std::make_tuple(    npe::move(vf),
    npe::move(v_fi));
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<VFType> > & vf;
    std::vector<std::vector<VFiType> > & v_fi;
    igl::vertex_triangle_adjacency(n, f, vf, v_fi);
    return std::make_tuple(    npe::move(vf),     npe::move(v_fi));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/vertex_triangle_adjacency.h>

const char* ds_vertex_triangle_adjacency = R"igl_Qu8mg5v7(
See vertex_triangle_adjacency for the documentation.
)igl_Qu8mg5v7";

npe_function(vertex_triangle_adjacency)
npe_doc(ds_vertex_triangle_adjacency)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<IndexType> > & vf;
    std::vector<std::vector<IndexType> > & v_fi;
    igl::vertex_triangle_adjacency(v, f, vf, v_fi);
    return std::make_tuple(    npe::move(vf),
    npe::move(v_fi));
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<IndexType> > & vf;
    std::vector<std::vector<IndexType> > & v_fi;
    igl::vertex_triangle_adjacency(v, f, vf, v_fi);
    return std::make_tuple(    npe::move(vf),     npe::move(v_fi));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


