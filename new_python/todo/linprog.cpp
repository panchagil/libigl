// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/linprog.h>

const char* ds_linprog = R"igl_Qu8mg5v7(

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

 Solve a linear program given in "standard form"
  
   min  f'x
   s.t. A(    1:k,:) x <= b(1:k)
        A(k+1:end,:) x = b(k+1:end)
     ** x >= 0 **
  
   In contrast to other APIs the entries in b may be negative.
  
   Inputs:
     c  #x list of linear coefficients
     A  #A by #x matrix of linear constraint coefficients
     b  #A list of linear constraint right-hand sides
     k  number of inequality constraints as first rows of A,b
   Outputs:
     x  #x solution vector
  
)igl_Qu8mg5v7";

npe_function(linprog)
npe_doc(ds_linprog)

npe_arg(c, Eigen::VectorXd &)
npe_arg(a, Eigen::MatrixXd &)
npe_arg(b, Eigen::VectorXd &)
npe_arg(k, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::VectorXd & f;
    igl::linprog(c, a, b, k, f);
    return npe::move(f);
} else if (dtype.type() == npe::type_f64) {
    Eigen::VectorXd & f;
    igl::linprog(c, a, b, k, f);
    return npe::move(f);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/linprog.h>

const char* ds_linprog = R"igl_Qu8mg5v7(

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

 Wrapper in friendlier general form (no implicit bounds on x)
  
   min  f'x
   s.t. A x <= b
        B x = c
  
   Inputs:
     f  #x list of linear coefficients
     A  #A by #x matrix of linear inequality constraint coefficients
     b  #A list of linear constraint right-hand sides
     B  #B by #x matrix of linear equality constraint coefficients
     c  #B list of linear constraint right-hand sides
   Outputs:
     x  #x solution vector
  
)igl_Qu8mg5v7";

npe_function(linprog)
npe_doc(ds_linprog)

npe_arg(f, Eigen::VectorXd &)
npe_arg(a, Eigen::MatrixXd &)
npe_arg(b, Eigen::VectorXd &)
npe_arg(b, Eigen::MatrixXd &)
npe_arg(c, Eigen::VectorXd &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::VectorXd & x;
    igl::linprog(f, a, b, b, c, x);
    return npe::move(x);
} else if (dtype.type() == npe::type_f64) {
    Eigen::VectorXd & x;
    igl::linprog(f, a, b, b, c, x);
    return npe::move(x);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


