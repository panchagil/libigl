// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/mvc.h>

const char* ds_mvc = R"igl_Qu8mg5v7(

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

   MVC - MEAN VALUE COORDINATES
    
     mvc(V,C,W)
    
     Inputs:
      V  #V x dim list of vertex positions (dim = 2 or dim = 3)
      C  #C x dim list of polygon vertex positions in counter-clockwise order
        (dim = 2 or dim = 3)
    
     Outputs:
      W  weights, #V by #C matrix of weights
    
    Known Bugs: implementation is listed as "Broken"
)igl_Qu8mg5v7";

npe_function(mvc)
npe_doc(ds_mvc)

npe_arg(v, Eigen::MatrixXd &)
npe_arg(c, Eigen::MatrixXd &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::MatrixXd & w;
    igl::mvc(v, c, w);
    return npe::move(w);
} else if (dtype.type() == npe::type_f64) {
    Eigen::MatrixXd & w;
    igl::mvc(v, c, w);
    return npe::move(w);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


