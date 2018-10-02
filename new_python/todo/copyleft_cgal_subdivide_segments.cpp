// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/subdivide_segments.h>

const char* ds_subdivide_segments = R"igl_Qu8mg5v7(

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

 Insert steiner points to subdivide a given set of line segments
       
       Inputs:
         V  #V by 2 list of vertex positions
         E  #E by 2 list of segment indices into V
         steiner  #E list of lists of unsorted steiner points (including
           endpoints) along the #E original segments
       Outputs:
         VI  #VI by 2 list of output vertex positions, copies of V are always
           the first #V vertices
         EI  #EI by 2 list of segment indices into V, #EI ≥ #E
         J  #EI list of indices into E revealing "parent segments"
         IM  #VI list of indices into VV of unique vertices.
)igl_Qu8mg5v7";

npe_function(subdivide_segments)
npe_doc(ds_subdivide_segments)

npe_arg(v, dense_f64)
npe_arg(e, dense_f64)
npe_arg(steiner, std::vector<std::vector<CGAL::Point_2<Kernel> > > &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 vi;
    dense_f32 ei;
    dense_f32 j;
    dense_f32 im;
    igl::    copyleft::    cgal::subdivide_segments(v, e, steiner, vi, ei, j, im);
    return std::make_tuple(    npe::move(vi),
    npe::move(ei),
    npe::move(j),
    npe::move(im));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 vi;
    dense_f64 ei;
    dense_f64 j;
    dense_f64 im;
    igl::    copyleft::    cgal::subdivide_segments(v, e, steiner, vi, ei, j, im);
    return std::make_tuple(    npe::move(vi),     npe::move(ei),     npe::move(j),     npe::move(im));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


