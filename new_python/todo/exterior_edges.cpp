// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/exterior_edges.h>

const char* ds_exterior_edges = R"igl_Qu8mg5v7(

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

 EXTERIOR_EDGES Determines boundary "edges" and also edges with an
   odd number of occurrences where seeing edge (i,j) counts as +1 and seeing
   the opposite edge (j,i) counts as -1
  
   Inputs:
     F  #F by simplex_size list of "faces"
   Outputs:
     E  #E by simplex_size-1  list of exterior edges
  
)igl_Qu8mg5v7";

npe_function(exterior_edges)
npe_doc(ds_exterior_edges)

npe_arg(f, Eigen::MatrixXi &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::MatrixXi & e;
    igl::exterior_edges(f, e);
    return npe::move(e);
} else if (dtype.type() == npe::type_f64) {
    Eigen::MatrixXi & e;
    igl::exterior_edges(f, e);
    return npe::move(e);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/exterior_edges.h>

const char* ds_exterior_edges = R"igl_Qu8mg5v7(

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

 Inline version
)igl_Qu8mg5v7";

npe_function(exterior_edges)
npe_doc(ds_exterior_edges)

npe_arg(f, Eigen::MatrixXi &)



npe_begin_code()
using namespace std;



igl::exterior_edges(f);

return

npe_end_code()


