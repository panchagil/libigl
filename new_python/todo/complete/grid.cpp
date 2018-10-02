#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/grid.h>

const char* ds_grid = R"igl_Qu8mg5v7(

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

 Construct vertices of a regular grid, suitable for input to
   `igl::marching_cubes`
  
   Inputs:
     res  3-long list of number of vertices along the x y and z dimensions
   Outputs:
     GV  res(0)*res(1)*res(2) by 3 list of mesh vertex positions.
     
)igl_Qu8mg5v7";

npe_function(grid)
npe_doc(ds_grid)

npe_arg(res, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 gv;
    igl::grid(res, gv);
    return npe::move(gv);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 gv;
    igl::grid(res, gv);
    return npe::move(gv);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


