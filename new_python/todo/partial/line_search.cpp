// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/line_search.h>

const char* ds_line_search = R"igl_Qu8mg5v7(

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

 Implement a bisection linesearch to minimize a mesh-based energy on vertices given at 'x' at a search direction 'd',
   with initial step size. Stops when a point with lower energy is found, or after maximal iterations have been reached.
  
   Inputs:
     x  						#X by dim list of variables
     d  						#X by dim list of a given search direction
     i_step_size  			initial step size
     energy       			A function to compute the mesh-based energy (return an energy that is bigger than 0)
     cur_energy(OPTIONAL)     The energy at the given point. Helps save redundant computations.
  							This is optional. If not specified, the function will compute it.
   Outputs:
  		x  						#X by dim list of variables at the new location
   Returns the energy at the new point 'x'
)igl_Qu8mg5v7";

npe_function(line_search)
npe_doc(ds_line_search)

npe_arg(d, Eigen::MatrixXd &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::MatrixXd & x;
    double i_step_size;
    std::function<double (Eigen::MatrixXd &)> energy;
    double cur_energy;
    igl::line_search(d, x, i_step_size, energy, cur_energy);
    return std::make_tuple(    npe::move(x),
    npe::move(i_step_size),
    npe::move(energy),
    npe::move(cur_energy));
} else if (dtype.type() == npe::type_f64) {
    Eigen::MatrixXd & x;
    double i_step_size;
    std::function<double (Eigen::MatrixXd &)> energy;
    double cur_energy;
    igl::line_search(d, x, i_step_size, energy, cur_energy);
    return std::make_tuple(    npe::move(x),     npe::move(i_step_size),     npe::move(energy),     npe::move(cur_energy));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


