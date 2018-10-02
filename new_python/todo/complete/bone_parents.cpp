#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/bone_parents.h>

const char* ds_bone_parents = R"igl_Qu8mg5v7(

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

 BONE_PARENTS Recover "parent" bones from directed graph representation.
   
   Inputs:
     BE  #BE by 2 list of directed bone edges
   Outputs:
     P  #BE by 1 list of parent indices into BE, -1 means root.
  
)igl_Qu8mg5v7";

npe_function(bone_parents)
npe_doc(ds_bone_parents)

npe_arg(be, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 p;
    igl::bone_parents(be, p);
    return npe::move(p);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 p;
    igl::bone_parents(be, p);
    return npe::move(p);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


