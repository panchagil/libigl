#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/snap_rounding.h>

const char* ds_snap_rounding = R"igl_Qu8mg5v7(

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

 SNAP_ROUNDING Snap a list of possible intersecting segments with
       endpoints in any precision to _the_ integer grid.
      
       Inputs:
         V  #V by 2 list of vertex positions
         E  #E by 2 list of segment indices into V
       Outputs:
         VI  #VI by 2 list of output integer vertex positions, rounded copies
           of V are always the first #V vertices
         EI  #EI by 2 list of segment indices into V, #EI ≥ #E
         J  #EI list of indices into E revealing "parent segments"
)igl_Qu8mg5v7";

npe_function(snap_rounding)
npe_doc(ds_snap_rounding)

npe_arg(v, dense_f64)
npe_arg(e, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 vi;
    dense_f32 ei;
    dense_f32 j;
    igl::    copyleft::    cgal::snap_rounding(v, e, vi, ei, j);
    return std::make_tuple(    npe::move(vi),
    npe::move(ei),
    npe::move(j));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 vi;
    dense_f64 ei;
    dense_f64 j;
    igl::    copyleft::    cgal::snap_rounding(v, e, vi, ei, j);
    return std::make_tuple(    npe::move(vi),     npe::move(ei),     npe::move(j));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


