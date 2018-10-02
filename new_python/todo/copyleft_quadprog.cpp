// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/quadprog.h>

const char* ds_quadprog = R"igl_Qu8mg5v7(

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

 Solve a (dense) quadratric program of the form:
    
       min  0.5 x G x + g0 x
       s.t. CE' x + ce0  = 0
       and  CI' x + ci0 >= 0
    
     Inputs:
       G  #x by #x matrix of quadratic coefficients
       g0  #x vector of linear coefficients
       CE #x by #CE list of linear equality coefficients
       ce0 #CE list of linear equality right-hand sides
       CI #x by #CI list of linear equality coefficients
       ci0 #CI list of linear equality right-hand sides
     Outputs:
       x  #x vector of solution values
     Returns true iff success
)igl_Qu8mg5v7";

npe_function(quadprog)
npe_doc(ds_quadprog)

npe_arg(g, Eigen::MatrixXd &)
npe_arg(g0, Eigen::VectorXd &)
npe_arg(ce, Eigen::MatrixXd &)
npe_arg(ce0, Eigen::VectorXd &)
npe_arg(ci, Eigen::MatrixXd &)
npe_arg(ci0, Eigen::VectorXd &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::VectorXd & x;
    igl::    copyleft::quadprog(g, g0, ce, ce0, ci, ci0, x);
    return npe::move(x);
} else if (dtype.type() == npe::type_f64) {
    Eigen::VectorXd & x;
    igl::    copyleft::quadprog(g, g0, ce, ce0, ci, ci0, x);
    return npe::move(x);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


