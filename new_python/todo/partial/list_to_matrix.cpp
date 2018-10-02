// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/list_to_matrix.h>

const char* ds_list_to_matrix = R"igl_Qu8mg5v7(

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
     T  type that can be safely cast to type in Mat via '='
     Mat  Matrix type, must implement:
       .resize(m,n)
       .row(i) = Row
   Inputs:
     V  a m-long list of vectors of size n
   Outputs:
     M  an m by n matrix
   Returns true on success, false on errors
)igl_Qu8mg5v7";

npe_function(list_to_matrix)
npe_doc(ds_list_to_matrix)

npe_arg(v, std::vector<std::vector<T> > &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 m;
    igl::list_to_matrix(v, m);
    return npe::move(m);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 m;
    igl::list_to_matrix(v, m);
    return npe::move(m);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/list_to_matrix.h>

const char* ds_list_to_matrix = R"igl_Qu8mg5v7(

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

 Convert a list of row vectors of `n` or less to a matrix and pad on
   the right with `padding`:
  
   Inputs:
     V  a m-long list of vectors of size <=n
     n  number of columns
     padding  value to fill in from right for short rows
   Outputs:
     M  an m by n matrix
)igl_Qu8mg5v7";

npe_function(list_to_matrix)
npe_doc(ds_list_to_matrix)

npe_arg(v, std::vector<std::vector<T> > &)
npe_arg(n, int)
npe_arg(padding, T &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 m;
    igl::list_to_matrix(v, n, padding, m);
    return npe::move(m);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 m;
    igl::list_to_matrix(v, n, padding, m);
    return npe::move(m);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/list_to_matrix.h>

const char* ds_list_to_matrix = R"igl_Qu8mg5v7(

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

 Vector wrapper
)igl_Qu8mg5v7";

npe_function(list_to_matrix)
npe_doc(ds_list_to_matrix)

npe_arg(v, std::vector<T> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 m;
    igl::list_to_matrix(v, m);
    return npe::move(m);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 m;
    igl::list_to_matrix(v, m);
    return npe::move(m);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


