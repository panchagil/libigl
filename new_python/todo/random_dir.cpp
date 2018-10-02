#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/random_dir_stratified.h>

const char* ds_random_dir_stratified = R"igl_Qu8mg5v7(

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

 Generate n stratified uniformly random unit directions in 3d, return as rows
   of an n by 3 matrix
  
   Inputs:
     n  number of directions
   Return n by 3 matrix of random directions
)igl_Qu8mg5v7";

npe_function(random_dir_stratified)
npe_doc(ds_random_dir_stratified)

npe_arg(n, int)



npe_begin_code()
using namespace std;



igl::random_dir_stratified(n);

return

npe_end_code()


