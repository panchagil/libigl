// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/reorder.h>

const char* ds_reorder = R"igl_Qu8mg5v7(

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

 Act like matlab's Y = X(I) for std vectors
   where I contains a vector of indices so that after,
   Y[j] = X[I[j]] for index j
   this implies that Y.size() == I.size()
   X and Y are allowed to be the same reference
)igl_Qu8mg5v7";

npe_function(reorder)
npe_doc(ds_reorder)

npe_arg(unordered, std::vector<T> &)
npe_arg(index_map, std::vector<size_t> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<T> & ordered;
    igl::reorder(unordered, index_map, ordered);
    return npe::move(ordered);
} else if (dtype.type() == npe::type_f64) {
    std::vector<T> & ordered;
    igl::reorder(unordered, index_map, ordered);
    return npe::move(ordered);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


