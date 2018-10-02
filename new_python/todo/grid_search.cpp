// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/grid_search.h>

const char* ds_grid_search = R"igl_Qu8mg5v7(

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

 Solve the problem:
  
     minimize f(x)
     subject to lb ≤ x ≤ ub 
   
   by exhaustive grid search.
  
   Inputs:
     f  function to minimize
     LB  #X vector of finite lower bounds
     UB  #X vector of finite upper bounds
     I  #X vector of number of steps for each variable
   Outputs:
     X  #X optimal parameter vector
   Returns f(X)
  
)igl_Qu8mg5v7";

npe_function(grid_search)
npe_doc(ds_grid_search)

npe_arg(f, std::function<Scalar (DerivedX &)>)
npe_arg(lb, dense_f64)
npe_arg(ub, dense_f64)
npe_arg(i, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    DerivedX & x;
    igl::grid_search(f, lb, ub, i, x);
    return npe::move(x);
} else if (dtype.type() == npe::type_f64) {
    DerivedX & x;
    igl::grid_search(f, lb, ub, i, x);
    return npe::move(x);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


