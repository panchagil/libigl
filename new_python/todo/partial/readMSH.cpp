// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/readMSH.h>

const char* ds_read_msh = R"igl_Qu8mg5v7(

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

 Read a mesh (e.g., tet mesh) from a gmsh .msh file
   
   Inputs:
     filename  path to .msh file
   Outputs:
      V  #V by 3 list of 3D mesh vertex positions
      T  #T by ss list of 3D ss-element indices into V (e.g., ss=4 for tets)
   Returns true on success
)igl_Qu8mg5v7";

npe_function(read_msh)
npe_doc(ds_read_msh)

npe_arg(filename, std::string &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v;
    dense_f32 t;
    igl::readMSH(filename, v, t);
    return std::make_tuple(    npe::move(v),
    npe::move(t));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v;
    dense_f64 t;
    igl::readMSH(filename, v, t);
    return std::make_tuple(    npe::move(v),     npe::move(t));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


