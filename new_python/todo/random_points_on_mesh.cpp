// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/random_points_on_mesh.h>

const char* ds_random_points_on_mesh = R"igl_Qu8mg5v7(

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

 RANDOM_POINTS_ON_MESH Randomly sample a mesh (V,F) n times.
  
   Inputs:
     n  number of samples
     V  #V by dim list of mesh vertex positions
     F  #F by 3 list of mesh triangle indices
   Outputs:
     B  n by 3 list of barycentric coordinates, ith row are coordinates of
       ith sampled point in face FI(i)
     FI  n list of indices into F 
  
)igl_Qu8mg5v7";

npe_function(random_points_on_mesh)
npe_doc(ds_random_points_on_mesh)

npe_arg(n, int)
npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 b;
    dense_f32 fi;
    igl::random_points_on_mesh(n, v, f, b, fi);
    return std::make_tuple(    npe::move(b),
    npe::move(fi));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 b;
    dense_f64 fi;
    igl::random_points_on_mesh(n, v, f, b, fi);
    return std::make_tuple(    npe::move(b),     npe::move(fi));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/random_points_on_mesh.h>

const char* ds_random_points_on_mesh = R"igl_Qu8mg5v7(

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

 Outputs:
     B n by #V sparse matrix so that  B*V produces a list of sample points
)igl_Qu8mg5v7";

npe_function(random_points_on_mesh)
npe_doc(ds_random_points_on_mesh)

npe_arg(n, int)
npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::SparseMatrix<ScalarB> & b;
    dense_f32 fi;
    igl::random_points_on_mesh(n, v, f, b, fi);
    return std::make_tuple(    npe::move(b),
    npe::move(fi));
} else if (dtype.type() == npe::type_f64) {
    Eigen::SparseMatrix<ScalarB> & b;
    dense_f64 fi;
    igl::random_points_on_mesh(n, v, f, b, fi);
    return std::make_tuple(    npe::move(b),     npe::move(fi));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


