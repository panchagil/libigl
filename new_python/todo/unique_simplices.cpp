#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/unique_simplices.h>

const char* ds_unique_simplices = R"igl_Qu8mg5v7(

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

 Find *combinatorially* unique simplices in F.  **Order independent**
  
   Inputs:
     F  #F by simplex-size list of simplices
   Outputs:
     FF  #FF by simplex-size list of unique simplices in F
     IA  #FF index vector so that FF == sort(F(IA,:),2);
     IC  #F index vector so that sort(F,2) == FF(IC,:);
)igl_Qu8mg5v7";

npe_function(unique_simplices)
npe_doc(ds_unique_simplices)

npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 ff;
    dense_f32 ia;
    dense_f32 ic;
    igl::unique_simplices(f, ff, ia, ic);
    return std::make_tuple(    npe::move(ff),
    npe::move(ia),
    npe::move(ic));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 ff;
    dense_f64 ia;
    dense_f64 ic;
    igl::unique_simplices(f, ff, ia, ic);
    return std::make_tuple(    npe::move(ff),     npe::move(ia),     npe::move(ic));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/unique_simplices.h>

const char* ds_unique_simplices = R"igl_Qu8mg5v7(
See unique_simplices for the documentation.
)igl_Qu8mg5v7";

npe_function(unique_simplices)
npe_doc(ds_unique_simplices)

npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 ff;
    igl::unique_simplices(f, ff);
    return npe::move(ff);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 ff;
    igl::unique_simplices(f, ff);
    return npe::move(ff);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


