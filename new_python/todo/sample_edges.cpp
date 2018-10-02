// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/sample_edges.h>

const char* ds_sample_edges = R"igl_Qu8mg5v7(

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

 Compute samples_per_edge extra points along each edge in E defined over
   vertices of V.
  
   Inputs:
     V  vertices over which edges are defined, # vertices by dim
     E  edge list, # edges by 2
     k  number of extra samples to be computed along edge not
          including start and end points
   Output:
     S  sampled vertices, size less than # edges * (2+k) by dim always begins
          with V so that E is also defined over S
)igl_Qu8mg5v7";

npe_function(sample_edges)
npe_doc(ds_sample_edges)

npe_arg(v, Eigen::MatrixXd &)
npe_arg(e, Eigen::MatrixXi &)
npe_arg(k, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::MatrixXd & s;
    igl::sample_edges(v, e, k, s);
    return npe::move(s);
} else if (dtype.type() == npe::type_f64) {
    Eigen::MatrixXd & s;
    igl::sample_edges(v, e, k, s);
    return npe::move(s);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


