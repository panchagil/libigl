// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/frame_to_cross_field.h>

const char* ds_frame_to_cross_field = R"igl_Qu8mg5v7(

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

 Convert a frame field into its closest cross field
   Inputs:
     V       #V by 3 coordinates of the vertices
     F       #F by 3 list of mesh faces (must be triangles)
     FF1     #F by 3 the first representative vector of the frame field (up to permutation and sign)
     FF2     #F by 3 the second representative vector of the frame field (up to permutation and sign)
  
   Outputs:
     X       #F by 3 representative vector of the closest cross field
  
)igl_Qu8mg5v7";

npe_function(frame_to_cross_field)
npe_doc(ds_frame_to_cross_field)

npe_arg(v, Eigen::MatrixXd &)
npe_arg(f, Eigen::MatrixXi &)
npe_arg(ff1, Eigen::MatrixXd &)
npe_arg(ff2, Eigen::MatrixXd &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::MatrixXd & x;
    igl::frame_to_cross_field(v, f, ff1, ff2, x);
    return npe::move(x);
} else if (dtype.type() == npe::type_f64) {
    Eigen::MatrixXd & x;
    igl::frame_to_cross_field(v, f, ff1, ff2, x);
    return npe::move(x);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


