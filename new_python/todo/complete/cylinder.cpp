#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/cylinder.h>

const char* ds_cylinder = R"igl_Qu8mg5v7(

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

 Construct a triangle mesh of a cylinder (without caps)
  
   Inputs:
     axis_devisions  number of vertices _around the cylinder_
     height_devisions  number of vertices _up the cylinder_
   Outputs:
     V  #V by 3 list of mesh vertex positions
     F  #F by 3 list of triangle indices into V
  
)igl_Qu8mg5v7";

npe_function(cylinder)
npe_doc(ds_cylinder)

npe_arg(axis_devisions, int)
npe_arg(height_devisions, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v;
    dense_i32 f;
    igl::cylinder(axis_devisions, height_devisions, v, f);
    return std::make_tuple(    npe::move(v),
    npe::move(f));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v;
    dense_i32 f;
    igl::cylinder(axis_devisions, height_devisions, v, f);
    return std::make_tuple(    npe::move(v),     npe::move(f));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


