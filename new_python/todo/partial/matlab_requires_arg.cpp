// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/requires_arg.h>

const char* ds_requires_arg = R"igl_Qu8mg5v7(

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

 Simply throw an error if (i+1)<rhs 
    
     Input:
       i  index of current arg
       nrhs  total number of args
       name of current arg
)igl_Qu8mg5v7";

npe_function(requires_arg)
npe_doc(ds_requires_arg)

npe_arg(i, int)
npe_arg(nrhs, int)
npe_arg(name, char *)



npe_begin_code()
using namespace std;



igl::matlab::requires_arg(i, nrhs, name);

return

npe_end_code()


