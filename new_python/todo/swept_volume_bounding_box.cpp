// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/swept_volume_bounding_box.h>

const char* ds_swept_volume_bounding_box = R"igl_Qu8mg5v7(

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

 Construct an axis-aligned bounding box containing a shape undergoing a
   motion sampled at `steps` discrete momements.
  
   Inputs:
     n  number of mesh vertices
     V  function handle so that V(i,t) returns the 3d position of vertex
       i at time t, for t∈[0,1]
     steps  number of time steps: steps=3 --> t∈{0,0.5,1}
   Outputs:
     box  box containing mesh under motion
)igl_Qu8mg5v7";

npe_function(swept_volume_bounding_box)
npe_doc(ds_swept_volume_bounding_box)

npe_arg(n, size_t &)
npe_arg(v, std::function<Eigen::RowVector3d (const size_t, const double)> &)
npe_arg(steps, size_t &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::AlignedBox3d & box;
    igl::swept_volume_bounding_box(n, v, steps, box);
    return npe::move(box);
} else if (dtype.type() == npe::type_f64) {
    Eigen::AlignedBox3d & box;
    igl::swept_volume_bounding_box(n, v, steps, box);
    return npe::move(box);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


