// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/rows_to_matrix.h>

const char* ds_rows_to_matrix = R"igl_Qu8mg5v7(

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

 Convert a list (std::vector) of row vectors of the same length to a matrix
   Template: 
     Row  row vector type, must implement:
       .size()
     Mat  Matrix type, must implement:
       .resize(m,n)
       .row(i) = Row
   Inputs:
     V  a m-long list of vectors of size n
   Outputs:
     M  an m by n matrix
   Returns true on success, false on errors
)igl_Qu8mg5v7";

npe_function(rows_to_matrix)
npe_doc(ds_rows_to_matrix)

npe_arg(v, std::vector<Row> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Mat & m;
    igl::rows_to_matrix(v, m);
    return npe::move(m);
} else if (dtype.type() == npe::type_f64) {
    Mat & m;
    igl::rows_to_matrix(v, m);
    return npe::move(m);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


