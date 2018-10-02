// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/column_to_quats.h>

const char* ds_column_to_quats = R"igl_Qu8mg5v7(

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

 "Columnize" a list of quaternions (q1x,q1y,q1z,q1w,q2x,q2y,q2z,q2w,...)
  
   Inputs:
     Q  n*4-long list of coefficients
   Outputs:
     vQ  n-long list of quaternions
   Returns false if n%4!=0
)igl_Qu8mg5v7";

npe_function(column_to_quats)
npe_doc(ds_column_to_quats)

npe_arg(q, Eigen::VectorXd &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<Eigen::Quaterniond, Eigen::aligned_allocator<Eigen::Quaterniond> > & v_q;
    igl::column_to_quats(q, v_q);
    return npe::move(v_q);
} else if (dtype.type() == npe::type_f64) {
    std::vector<Eigen::Quaterniond, Eigen::aligned_allocator<Eigen::Quaterniond> > & v_q;
    igl::column_to_quats(q, v_q);
    return npe::move(v_q);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


