// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/bfs.h>

const char* ds_bfs = R"igl_Qu8mg5v7(

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

 Traverse a **directed** graph represented by an adjacency list using
   breadth first search
  
   Inputs:
     A  #V list of adjacency lists  or #V by #V adjacency matrix
     s  starting node (index into A)
   Outputs:
     D  #V list of indices into rows of A in the order in which graph nodes
       are discovered.
     P  #V list of indices into rows of A of predecessor in resulting
       spanning tree {-1 indicates root/not discovered), order corresponds to
       V **not** D.
)igl_Qu8mg5v7";

npe_function(bfs)
npe_doc(ds_bfs)

npe_arg(a, AType &)
npe_arg(s, size_t)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 d;
    dense_f32 p;
    igl::bfs(a, s, d, p);
    return std::make_tuple(    npe::move(d),
    npe::move(p));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 d;
    dense_f64 p;
    igl::bfs(a, s, d, p);
    return std::make_tuple(    npe::move(d),     npe::move(p));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/bfs.h>

const char* ds_bfs = R"igl_Qu8mg5v7(
See bfs for the documentation.
)igl_Qu8mg5v7";

npe_function(bfs)
npe_doc(ds_bfs)

npe_arg(a, std::vector<std::vector<AType> > &)
npe_arg(s, size_t)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<DType> & d;
    std::vector<PType> & p;
    igl::bfs(a, s, d, p);
    return std::make_tuple(    npe::move(d),
    npe::move(p));
} else if (dtype.type() == npe::type_f64) {
    std::vector<DType> & d;
    std::vector<PType> & p;
    igl::bfs(a, s, d, p);
    return std::make_tuple(    npe::move(d),     npe::move(p));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/bfs.h>

const char* ds_bfs = R"igl_Qu8mg5v7(
See bfs for the documentation.
)igl_Qu8mg5v7";

npe_function(bfs)
npe_doc(ds_bfs)

npe_arg(a, Eigen::SparseMatrix<AType> &)
npe_arg(s, size_t)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<DType> & d;
    std::vector<PType> & p;
    igl::bfs(a, s, d, p);
    return std::make_tuple(    npe::move(d),
    npe::move(p));
} else if (dtype.type() == npe::type_f64) {
    std::vector<DType> & d;
    std::vector<PType> & p;
    igl::bfs(a, s, d, p);
    return std::make_tuple(    npe::move(d),     npe::move(p));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


