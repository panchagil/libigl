// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/directed_edge_orientations.h>

const char* ds_directed_edge_orientations = R"igl_Qu8mg5v7(

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

 Determine rotations that take each edge from the x-axis to its given rest
   orientation.
  
   Inputs:
     C  #C by 3 list of edge vertex positions
     E  #E by 2 list of directed edges
   Outputs:
     Q  #E list of quaternions 
  
)igl_Qu8mg5v7";

npe_function(directed_edge_orientations)
npe_doc(ds_directed_edge_orientations)

npe_arg(c, dense_f64)
npe_arg(e, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<Eigen::Quaterniond, Eigen::aligned_allocator<Eigen::Quaterniond> > & q;
    igl::directed_edge_orientations(c, e, q);
    return npe::move(q);
} else if (dtype.type() == npe::type_f64) {
    std::vector<Eigen::Quaterniond, Eigen::aligned_allocator<Eigen::Quaterniond> > & q;
    igl::directed_edge_orientations(c, e, q);
    return npe::move(q);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


