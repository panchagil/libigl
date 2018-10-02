// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/operator+.h>

const char* ds_operator+ = R"igl_Qu8mg5v7(

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

 A binary addition operator for Quadric tuples compatible with qslim,
   computing c = a+b
  
   Inputs:
     a  QSlim quadric
     b  QSlim quadric
   Output
     c  QSlim quadric
  
)igl_Qu8mg5v7";

npe_function(operator+)
npe_doc(ds_operator+)

npe_arg(a, std::tuple<Eigen::MatrixXd, Eigen::RowVectorXd, double> &)
npe_arg(b, std::tuple<Eigen::MatrixXd, Eigen::RowVectorXd, double> &)



npe_begin_code()
using namespace std;



igl::operator+(a, b);

return

npe_end_code()


