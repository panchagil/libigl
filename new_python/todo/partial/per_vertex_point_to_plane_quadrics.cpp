// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/per_vertex_point_to_plane_quadrics.h>

const char* ds_per_vertex_point_to_plane_quadrics = R"igl_Qu8mg5v7(

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

 Compute quadrics per vertex of a "closed" triangle mesh (V,F). Rather than
   follow the qslim paper, this implements the lesser-known _follow up_
   "Simplifying Surfaces with Color and Texture using Quadric Error Metrics".
   This allows V to be n-dimensional (where the extra coordiantes store
   texture UVs, color RGBs, etc.
  
   Inputs:
     V  #V by n list of vertex positions. Assumes that vertices with
       infinite coordinates are "points at infinity" being used to close up
       boundary edges with faces. This allows special subspace quadrice for
       boundary edges: There should never be more than one "point at
       infinity" in a single triangle.
     F  #F by 3 list of triangle indices into V
     E  #E by 2 list of edge indices into V.
     EMAP #F*3 list of indices into E, mapping each directed edge to unique
       unique edge in E
     EF  #E by 2 list of edge flaps, EF(e,0)=f means e=(i-->j) is the edge of
       F(f,:) opposite the vth corner, where EI(e,0)=v. Similarly EF(e,1) "
       e=(j->i)
     EI  #E by 2 list of edge flap corners (see above).
   Outputs:
     quadrics  #V list of quadrics, where a quadric is a tuple {A,b,c} such
       that the quadratic energy of moving this vertex to position x is
       given by x'Ax - 2b + c
  
)igl_Qu8mg5v7";

npe_function(per_vertex_point_to_plane_quadrics)
npe_doc(ds_per_vertex_point_to_plane_quadrics)

npe_arg(v, Eigen::MatrixXd &)
npe_arg(f, Eigen::MatrixXi &)
npe_arg(emap, Eigen::MatrixXi &)
npe_arg(ef, Eigen::MatrixXi &)
npe_arg(ei, Eigen::MatrixXi &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::tuple<Eigen::MatrixXd, Eigen::RowVectorXd, double> > & quadrics;
    igl::per_vertex_point_to_plane_quadrics(v, f, emap, ef, ei, quadrics);
    return npe::move(quadrics);
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::tuple<Eigen::MatrixXd, Eigen::RowVectorXd, double> > & quadrics;
    igl::per_vertex_point_to_plane_quadrics(v, f, emap, ef, ei, quadrics);
    return npe::move(quadrics);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


