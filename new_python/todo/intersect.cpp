// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/intersect.h>

const char* ds_intersect = R"igl_Qu8mg5v7(

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

 Determine the intersect between two sets of coefficients using ==
   Templates:
     M  matrix type that implements indexing by global index M(i)
   Inputs:
     A  matrix of coefficients
     B  matrix of coefficients
   Output:
     C  matrix of elements appearing in both A and B, C is always resized to
     have a single column
)igl_Qu8mg5v7";

npe_function(intersect)
npe_doc(ds_intersect)

npe_arg(a, M &)
npe_arg(b, M &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    M & c;
    igl::intersect(a, b, c);
    return npe::move(c);
} else if (dtype.type() == npe::type_f64) {
    M & c;
    igl::intersect(a, b, c);
    return npe::move(c);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/intersect.h>

const char* ds_intersect = R"igl_Qu8mg5v7(

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

 Last argument as return
)igl_Qu8mg5v7";

npe_function(intersect)
npe_doc(ds_intersect)

npe_arg(a, M &)
npe_arg(b, M &)



npe_begin_code()
using namespace std;



igl::intersect(a, b);

return

npe_end_code()


