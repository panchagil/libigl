#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/all_pairs_distances.h>

const char* ds_all_pairs_distances = R"igl_Qu8mg5v7(

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

 ALL_PAIRS_DISTANCES compute distances between each point i in V and point j
   in U
  
   D = all_pairs_distances(V,U)
  
   Templates:
     Mat  matrix class like MatrixXd
   Inputs:
     V  #V by dim list of points
     U  #U by dim list of points
     squared  whether to return squared distances
   Outputs:
     D  #V by #U matrix of distances, where D(i,j) gives the distance or
       squareed distance between V(i,:) and U(j,:)
  
)igl_Qu8mg5v7";

npe_function(all_pairs_distances)
npe_doc(ds_all_pairs_distances)

npe_arg(v, dense_f64)
npe_arg(u, dense_f64)
npe_arg(squared, bool)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 d;
    igl::all_pairs_distances(v, u, squared, d);
    return npe::move(d);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 d;
    igl::all_pairs_distances(v, u, squared, d);
    return npe::move(d);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


