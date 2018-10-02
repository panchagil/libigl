// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/quats_to_column.h>

const char* ds_quats_to_column = R"igl_Qu8mg5v7(

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
     vQ  n-long list of quaternions
   Outputs:
     Q  n*4-long list of coefficients
)igl_Qu8mg5v7";

npe_function(quats_to_column)
npe_doc(ds_quats_to_column)

npe_arg(v_q, std::vector<Eigen::Quaterniond, Eigen::aligned_allocator<Eigen::Quaterniond> >)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::VectorXd & q;
    igl::quats_to_column(v_q, q);
    return npe::move(q);
} else if (dtype.type() == npe::type_f64) {
    Eigen::VectorXd & q;
    igl::quats_to_column(v_q, q);
    return npe::move(q);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/quats_to_column.h>

const char* ds_quats_to_column = R"igl_Qu8mg5v7(
See quats_to_column for the documentation.
)igl_Qu8mg5v7";

npe_function(quats_to_column)
npe_doc(ds_quats_to_column)

npe_arg(v_q, std::vector<Eigen::Quaterniond, Eigen::aligned_allocator<Eigen::Quaterniond> >)



npe_begin_code()
using namespace std;



igl::quats_to_column(v_q);

return

npe_end_code()


