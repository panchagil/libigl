// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/cat.h>

const char* ds_cat = R"igl_Qu8mg5v7(

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

 Perform concatenation of a two matrices along a single dimension
   If dim == 1, then C = [A;B]. If dim == 2 then C = [A B]
   
   Template:
     Scalar  scalar data type for sparse matrices like double or int
     Mat  matrix type for all matrices (e.g. MatrixXd, SparseMatrix)
     MatC  matrix type for output matrix (e.g. MatrixXd) needs to support
       resize
   Inputs:
     A  first input matrix
     B  second input matrix
     dim  dimension along which to concatenate, 1 or 2
   Outputs:
     C  output matrix
     
)igl_Qu8mg5v7";

npe_function(cat)
npe_doc(ds_cat)

npe_arg(dim, int)
npe_arg(a, Sparse_f64)
npe_arg(b, Sparse_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Sparse_f32 c;
    igl::cat(dim, a, b, c);
    return npe::move(c);
} else if (dtype.type() == npe::type_f64) {
    Sparse_f64 c;
    igl::cat(dim, a, b, c);
    return npe::move(c);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/cat.h>

const char* ds_cat = R"igl_Qu8mg5v7(
See cat for the documentation.
)igl_Qu8mg5v7";

npe_function(cat)
npe_doc(ds_cat)

npe_arg(dim, int)
npe_arg(a, dense_f64)
npe_arg(b, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    MatC & c;
    igl::cat(dim, a, b, c);
    return npe::move(c);
} else if (dtype.type() == npe::type_f64) {
    MatC & c;
    igl::cat(dim, a, b, c);
    return npe::move(c);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/cat.h>

const char* ds_cat = R"igl_Qu8mg5v7(

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

 Wrapper that returns C
)igl_Qu8mg5v7";

npe_function(cat)
npe_doc(ds_cat)

npe_arg(dim, int)
npe_arg(a, Mat &)
npe_arg(b, Mat &)



npe_begin_code()
using namespace std;



igl::cat(dim, a, b);

return

npe_end_code()
#include <igl/cat.h>

const char* ds_cat = R"igl_Qu8mg5v7(

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

 Concatenate a "matrix" of blocks
   C = [A0;A1;A2;...;An] where Ai = [A[i][0] A[i][1] ... A[i][m]];
  
   Inputs:
     A  a matrix (vector of row vectors)
   Output:
     C
)igl_Qu8mg5v7";

npe_function(cat)
npe_doc(ds_cat)

npe_arg(a, std::vector<std::vector<Mat> > &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Mat & c;
    igl::cat(a, c);
    return npe::move(c);
} else if (dtype.type() == npe::type_f64) {
    Mat & c;
    igl::cat(a, c);
    return npe::move(c);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


