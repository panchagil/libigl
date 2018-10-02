// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/infinite_cost_stopping_condition.h>

const char* ds_infinite_cost_stopping_condition = R"igl_Qu8mg5v7(

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

 Stopping condition function compatible with igl::decimate. The output
   function handle will return true if cost of next edge is infinite.
  
   Inputs:
     cost_and_placement  handle being used by igl::collapse_edge
   Outputs:
     stopping_condition
  
)igl_Qu8mg5v7";

npe_function(infinite_cost_stopping_condition)
npe_doc(ds_infinite_cost_stopping_condition)

npe_arg(cost_and_placement, std::function<void (const int, const Eigen::MatrixXd &, const Eigen::MatrixXi &, const Eigen::MatrixXi &, const Eigen::VectorXi &, const Eigen::MatrixXi &, const Eigen::MatrixXi &, double &, Eigen::RowVectorXd &)> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::function<bool (const Eigen::MatrixXd &, const Eigen::MatrixXi &, const Eigen::MatrixXi &, const Eigen::VectorXi &, const Eigen::MatrixXi &, const Eigen::MatrixXi &, const std::set<std::pair<double, int> > &, const std::vector<std::set<std::pair<double, int> >::iterator> &, const Eigen::MatrixXd &, const int, const int, const int, const int, const int)> & stopping_condition;
    igl::infinite_cost_stopping_condition(cost_and_placement, stopping_condition);
    return npe::move(stopping_condition);
} else if (dtype.type() == npe::type_f64) {
    std::function<bool (const Eigen::MatrixXd &, const Eigen::MatrixXi &, const Eigen::MatrixXi &, const Eigen::VectorXi &, const Eigen::MatrixXi &, const Eigen::MatrixXi &, const std::set<std::pair<double, int> > &, const std::vector<std::set<std::pair<double, int> >::iterator> &, const Eigen::MatrixXd &, const int, const int, const int, const int, const int)> & stopping_condition;
    igl::infinite_cost_stopping_condition(cost_and_placement, stopping_condition);
    return npe::move(stopping_condition);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/infinite_cost_stopping_condition.h>

const char* ds_infinite_cost_stopping_condition = R"igl_Qu8mg5v7(
See infinite_cost_stopping_condition for the documentation.
)igl_Qu8mg5v7";

npe_function(infinite_cost_stopping_condition)
npe_doc(ds_infinite_cost_stopping_condition)

npe_arg(, Eigen::MatrixXd &)
npe_arg(, Eigen::MatrixXi &)
npe_arg(, Eigen::MatrixXi &)
npe_arg(, Eigen::VectorXi &)
npe_arg(, Eigen::MatrixXi &)
npe_arg(, Eigen::MatrixXi &)
npe_arg(, std::set<std::pair<double, int> > &)
npe_arg(, std::vector<std::set<std::pair<double, int> >::iterator> &)
npe_arg(, Eigen::MatrixXd &)
npe_arg(, int)
npe_arg(, int)
npe_arg(, int)
npe_arg(, int)
npe_arg(, int)
npe_arg(cost_and_placement, std::function<void (const int, const Eigen::MatrixXd &, const Eigen::MatrixXi &, const Eigen::MatrixXi &, const Eigen::VectorXi &, const Eigen::MatrixXi &, const Eigen::MatrixXi &, double &, Eigen::RowVectorXd &)> &)



npe_begin_code()
using namespace std;



igl::infinite_cost_stopping_condition(, , , , , , , , , , , , , , cost_and_placement);

return

npe_end_code()


