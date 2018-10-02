// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/verbose.h>

const char* ds_verbose = R"igl_Qu8mg5v7(

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

 Provide a wrapper for printf, called verbose that functions exactly like
   printf if VERBOSE is defined and does exactly nothing if VERBOSE is
   undefined
)igl_Qu8mg5v7";

npe_function(verbose)
npe_doc(ds_verbose)

npe_arg(msg, char *)



npe_begin_code()
using namespace std;



igl::verbose(msg);

return

npe_end_code()
#include <igl/verbose.h>

const char* ds_verbose = R"igl_Qu8mg5v7(

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

 Provide a wrapper for printf, called verbose that functions exactly like
   printf if VERBOSE is defined and does exactly nothing if VERBOSE is
   undefined
)igl_Qu8mg5v7";

npe_function(verbose)
npe_doc(ds_verbose)

npe_arg(, char *)



npe_begin_code()
using namespace std;



igl::verbose();

return

npe_end_code()


