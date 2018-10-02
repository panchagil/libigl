#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/nchoosek.h>

const char* ds_nchoosek = R"igl_Qu8mg5v7(

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

 NCHOOSEK  Like matlab's nchoosek.
  
   Inputs:
     n  total number elements
     k  size of sub-set to consider
   Returns number of k-size combinations out of the set [1,...,n]
)igl_Qu8mg5v7";

npe_function(nchoosek)
npe_doc(ds_nchoosek)

npe_arg(n, int)
npe_arg(k, int)



npe_begin_code()
using namespace std;



igl::nchoosek(n, k);

return

npe_end_code()
#include <igl/nchoosek.h>

const char* ds_nchoosek = R"igl_Qu8mg5v7(

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

 
   Inputs:
     V  n-long vector of elements
     k  size of sub-set to consider
   Outputs:
     U  nchoosek by k long matrix where each row is a unique k-size
       combination
)igl_Qu8mg5v7";

npe_function(nchoosek)
npe_doc(ds_nchoosek)

npe_arg(v, dense_f64)
npe_arg(k, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 u;
    igl::nchoosek(v, k, u);
    return npe::move(u);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 u;
    igl::nchoosek(v, k, u);
    return npe::move(u);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


