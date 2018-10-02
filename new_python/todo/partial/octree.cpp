// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/octree.h>

const char* ds_octree = R"igl_Qu8mg5v7(

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

 Given a set of 3D points P, generate data structures for a pointerless
   octree. Each cell stores its points, children, center location and width.
   Our octree is not dense. We use the following rule: if the current cell
   has any number of points, it will have all 8 children. A leaf cell will
   have -1's as its list of child indices.
  
   We use a binary numbering of children. Treating the parent cell's center
   as the origin, we number the octants in the following manner:
   The first bit is 1 iff the octant's x coordinate is positive
   The second bit is 1 iff the octant's y coordinate is positive
   The third bit is 1 iff the octant's z coordinate is positive
  
   For example, the octant with negative x, positive y, positive z is:
   110 binary = 6 decimal
  
   Inputs:
     P  #P by 3 list of point locations
  
   Outputs:
     point_indices  a vector of vectors, where the ith entry is a vector of
                    the indices into P that are the ith octree cell's points
     CH     #OctreeCells by 8, where the ith row is the indices of
            the ith octree cell's children
     CN     #OctreeCells by 3, where the ith row is a 3d row vector
            representing the position of the ith cell's center
     W      #OctreeCells, a vector where the ith entry is the width
            of the ith octree cell
  
)igl_Qu8mg5v7";

npe_function(octree)
npe_doc(ds_octree)

npe_arg(p, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<IndexType> > & point_indices;
    dense_f32 ch;
    dense_f32 cn;
    dense_f32 w;
    igl::octree(p, point_indices, ch, cn, w);
    return std::make_tuple(    npe::move(point_indices),
    npe::move(ch),
    npe::move(cn),
    npe::move(w));
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<IndexType> > & point_indices;
    dense_f64 ch;
    dense_f64 cn;
    dense_f64 w;
    igl::octree(p, point_indices, ch, cn, w);
    return std::make_tuple(    npe::move(point_indices),     npe::move(ch),     npe::move(cn),     npe::move(w));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


