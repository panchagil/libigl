// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/voxel_grid.h>

const char* ds_voxel_grid = R"igl_Qu8mg5v7(

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

 Construct the cell center positions of a regular voxel grid (lattice) made
   of perfectly square voxels.
   
   Inputs:
     box  bounding box to enclose by grid
     s  number of cell centers on largest side (including 2*pad_count)
     pad_count  number of cells beyond box
   Outputs:
     GV  side(0)*side(1)*side(2) by 3 list of cell center positions
     side  3-long list of dimension of voxel grid
)igl_Qu8mg5v7";

npe_function(voxel_grid)
npe_doc(ds_voxel_grid)

npe_arg(box, Eigen::AlignedBox<Scalar, 3> &)
npe_arg(s, int)
npe_arg(pad_count, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 gv;
    dense_f32 side;
    igl::voxel_grid(box, s, pad_count, gv, side);
    return std::make_tuple(    npe::move(gv),
    npe::move(side));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 gv;
    dense_f64 side;
    igl::voxel_grid(box, s, pad_count, gv, side);
    return std::make_tuple(    npe::move(gv),     npe::move(side));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


