#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/isolines.h>

const char* ds_isolines = R"igl_Qu8mg5v7(

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

 Constructs isolines for a function z given on a mesh (V,F)
    
    
     Inputs:
       V  #V by dim list of mesh vertex positions
       F  #F by 3 list of mesh faces (must be triangles)
       z  #V by 1 list of function values evaluated at vertices
       n  the number of desired isolines
     Outputs:
       isoV  #isoV by dim list of isoline vertex positions
       isoE  #isoE by 2 list of isoline edge positions
    
    
)igl_Qu8mg5v7";

npe_function(isolines)
npe_doc(ds_isolines)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(z, dense_f64)
npe_arg(n, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 iso_v;
    dense_f32 iso_e;
    igl::isolines(v, f, z, n, iso_v, iso_e);
    return std::make_tuple(    npe::move(iso_v),
    npe::move(iso_e));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 iso_v;
    dense_f64 iso_e;
    igl::isolines(v, f, z, n, iso_v, iso_e);
    return std::make_tuple(    npe::move(iso_v),     npe::move(iso_e));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


