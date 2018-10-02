#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/winding_number.h>

const char* ds_winding_number = R"igl_Qu8mg5v7(

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

 WINDING_NUMBER Compute the sum of solid angles of a triangle/tetrahedron
   described by points (vectors) V
  
   Templates:
     dim  dimension of input
   Inputs:
    V  n by 3 list of vertex positions
    F  #F by 3 list of triangle indices, minimum index is 0
    O  no by 3 list of origin positions
   Outputs:
    S  no by 1 list of winding numbers
  
)igl_Qu8mg5v7";

npe_function(winding_number)
npe_doc(ds_winding_number)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(o, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 w;
    igl::winding_number(v, f, o, w);
    return npe::move(w);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 w;
    igl::winding_number(v, f, o, w);
    return npe::move(w);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/winding_number.h>

const char* ds_winding_number = R"igl_Qu8mg5v7(

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

 Compute winding number of a single point
  
   Inputs:
    V  n by dim list of vertex positions
    F  #F by dim list of triangle indices, minimum index is 0
    p  single origin position
   Outputs:
    w  winding number of this point
  
)igl_Qu8mg5v7";

npe_function(winding_number)
npe_doc(ds_winding_number)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(p, dense_f64)



npe_begin_code()
using namespace std;



igl::winding_number(v, f, p);

return

npe_end_code()


