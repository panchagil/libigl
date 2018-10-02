// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/dqs.h>

const char* ds_dqs = R"igl_Qu8mg5v7(

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

 Dual quaternion skinning
  
   Inputs:
     V  #V by 3 list of rest positions
     W  #W by #C list of weights
     vQ  #C list of rotation quaternions 
     vT  #C list of translation vectors
   Outputs:
     U  #V by 3 list of new positions
)igl_Qu8mg5v7";

npe_function(dqs)
npe_doc(ds_dqs)

npe_arg(v, dense_f64)
npe_arg(w, dense_f64)
npe_arg(v_q, std::vector<Q, QAlloc> &)
npe_arg(v_t, std::vector<T> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 u;
    igl::dqs(v, w, v_q, v_t, u);
    return npe::move(u);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 u;
    igl::dqs(v, w, v_q, v_t, u);
    return npe::move(u);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


