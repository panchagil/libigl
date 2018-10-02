// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/fit_plane.h>

const char* ds_fit_plane = R"igl_Qu8mg5v7(

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

 This function fits a plane to a point cloud.
  
   Input:
     V #Vx3 matrix. The 3D point cloud, one row for each vertex.
   Output: 
     N 1x3 Vector. The normal of the fitted plane.
     C 1x3 Vector. A point that lies in the fitted plane.
   From http:missingbytes.blogspot.com/2012/06/fitting-plane-to-point-cloud.html
)igl_Qu8mg5v7";

npe_function(fit_plane)
npe_doc(ds_fit_plane)

npe_arg(v, Eigen::MatrixXd &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::RowVector3d & n;
    Eigen::RowVector3d & c;
    igl::fit_plane(v, n, c);
    return std::make_tuple(    npe::move(n),
    npe::move(c));
} else if (dtype.type() == npe::type_f64) {
    Eigen::RowVector3d & n;
    Eigen::RowVector3d & c;
    igl::fit_plane(v, n, c);
    return std::make_tuple(    npe::move(n),     npe::move(c));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


