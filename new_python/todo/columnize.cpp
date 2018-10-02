#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/columnize.h>

const char* ds_columnize = R"igl_Qu8mg5v7(

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

 "Columnize" a stack of block matrices. If A = [A1,A2,A3,...,Ak] with each A*
   an m by n block then this produces the column vector whose entries are 
   B(j*m*k+i*k+b) = A(i,b*n+j);
   or if A = [A1;A2;...;Ak] then
   B(j*m*k+i*k+b) = A(i+b*m,j);
  
   Templates:
     T  should be a eigen matrix primitive type like int or double
   Inputs:
     A  m*k by n (dim: 1) or m by n*k (dim: 2) eigen Matrix of type T values
     k  number of blocks
     dim  dimension in which blocks are stacked
   Output
     B  m*n*k eigen vector of type T values,
  
   See also: transpose_blocks
)igl_Qu8mg5v7";

npe_function(columnize)
npe_doc(ds_columnize)

npe_arg(a, dense_f64)
npe_arg(k, int)
npe_arg(dim, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 b;
    igl::columnize(a, k, dim, b);
    return npe::move(b);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 b;
    igl::columnize(a, k, dim, b);
    return npe::move(b);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


