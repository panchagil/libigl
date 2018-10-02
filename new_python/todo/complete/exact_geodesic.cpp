#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/exact_geodesic.h>

const char* ds_exact_geodesic = R"igl_Qu8mg5v7(

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

 Exact geodesic algorithm for triangular mesh with the implementation from https:code.google.com/archive/p/geodesic/, 
   and the algorithm first described by Mitchell, Mount and Papadimitriou in 1987
  
   Inputs:
     V  #V by 3 list of 3D vertex positions
     F  #F by 3 list of mesh faces
     VS #VS by 1 vector specifying indices of source vertices
     FS #FS by 1 vector specifying indices of source faces
     VT #VT by 1 vector specifying indices of target vertices
     FT #FT by 1 vector specifying indices of target faces
   Output:
     D  #VT+#FT by 1 vector of geodesic distances of each target w.r.t. the nearest one in the source set
  
   Note: 
        Specifying a face as target/source means its center. 
  
)igl_Qu8mg5v7";

npe_function(exact_geodesic)
npe_doc(ds_exact_geodesic)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(vs, dense_f64)
npe_arg(fs, dense_f64)
npe_arg(vt, dense_f64)
npe_arg(ft, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 d;
    igl::exact_geodesic(v, f, vs, fs, vt, ft, d);
    return npe::move(d);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 d;
    igl::exact_geodesic(v, f, vs, fs, vt, ft, d);
    return npe::move(d);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


