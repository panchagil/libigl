// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/sort.h>

const char* ds_sort = R"igl_Qu8mg5v7(

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

 Sort the elements of a matrix X along a given dimension like matlabs sort
   function
  
   Templates:
     DerivedX derived scalar type, e.g. MatrixXi or MatrixXd
     DerivedIX derived integer type, e.g. MatrixXi
   Inputs:
     X  m by n matrix whose entries are to be sorted
     dim  dimensional along which to sort:
       1  sort each column (matlab default)
       2  sort each row
     ascending  sort ascending (true, matlab default) or descending (false)
   Outputs:
     Y  m by n matrix whose entries are sorted
     IX  m by n matrix of indices so that if dim = 1, then in matlab notation
       for j = 1:n, Y(:,j) = X(I(:,j),j); end
)igl_Qu8mg5v7";

npe_function(sort)
npe_doc(ds_sort)

npe_arg(x, Eigen::DenseBase<DerivedX> &)
npe_arg(dim, int)
npe_arg(ascending, bool)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 y;
    dense_f32 ix;
    igl::sort(x, dim, ascending, y, ix);
    return std::make_tuple(    npe::move(y),
    npe::move(ix));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 y;
    dense_f64 ix;
    igl::sort(x, dim, ascending, y, ix);
    return std::make_tuple(    npe::move(y),     npe::move(ix));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/sort_new.h>

const char* ds_sort_new = R"igl_Qu8mg5v7(
See sort_new for the documentation.
)igl_Qu8mg5v7";

npe_function(sort_new)
npe_doc(ds_sort_new)

npe_arg(x, Eigen::DenseBase<DerivedX> &)
npe_arg(dim, int)
npe_arg(ascending, bool)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 y;
    dense_f32 ix;
    igl::sort_new(x, dim, ascending, y, ix);
    return std::make_tuple(    npe::move(y),
    npe::move(ix));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 y;
    dense_f64 ix;
    igl::sort_new(x, dim, ascending, y, ix);
    return std::make_tuple(    npe::move(y),     npe::move(ix));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/sort2.h>

const char* ds_sort2 = R"igl_Qu8mg5v7(

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

 Special case if size(X,dim) == 2
)igl_Qu8mg5v7";

npe_function(sort2)
npe_doc(ds_sort2)

npe_arg(x, Eigen::DenseBase<DerivedX> &)
npe_arg(dim, int)
npe_arg(ascending, bool)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 y;
    dense_f32 ix;
    igl::sort2(x, dim, ascending, y, ix);
    return std::make_tuple(    npe::move(y),
    npe::move(ix));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 y;
    dense_f64 ix;
    igl::sort2(x, dim, ascending, y, ix);
    return std::make_tuple(    npe::move(y),     npe::move(ix));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/sort3.h>

const char* ds_sort3 = R"igl_Qu8mg5v7(

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

 Special case if size(X,dim) == 3
)igl_Qu8mg5v7";

npe_function(sort3)
npe_doc(ds_sort3)

npe_arg(x, Eigen::DenseBase<DerivedX> &)
npe_arg(dim, int)
npe_arg(ascending, bool)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 y;
    dense_f32 ix;
    igl::sort3(x, dim, ascending, y, ix);
    return std::make_tuple(    npe::move(y),
    npe::move(ix));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 y;
    dense_f64 ix;
    igl::sort3(x, dim, ascending, y, ix);
    return std::make_tuple(    npe::move(y),     npe::move(ix));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/sort.h>

const char* ds_sort = R"igl_Qu8mg5v7(

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

 Act like matlab's [Y,I] = SORT(X) for std library vectors
   Templates:
     T  should be a class that implements the '<' comparator operator
   Input:
     unsorted  unsorted vector
     ascending  sort ascending (true, matlab default) or descending (false)
   Output:
     sorted     sorted vector, allowed to be same as unsorted
     index_map  an index map such that sorted[i] = unsorted[index_map[i]]
)igl_Qu8mg5v7";

npe_function(sort)
npe_doc(ds_sort)

npe_arg(unsorted, std::vector<T> &)
npe_arg(ascending, bool)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<T> & sorted;
    std::vector<size_t> & index_map;
    igl::sort(unsorted, ascending, sorted, index_map);
    return std::make_tuple(    npe::move(sorted),
    npe::move(index_map));
} else if (dtype.type() == npe::type_f64) {
    std::vector<T> & sorted;
    std::vector<size_t> & index_map;
    igl::sort(unsorted, ascending, sorted, index_map);
    return std::make_tuple(    npe::move(sorted),     npe::move(index_map));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


