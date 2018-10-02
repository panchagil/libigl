#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/cotmatrix_entries.h>

const char* ds_cotmatrix_entries = R"igl_Qu8mg5v7(

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

 COTMATRIX_ENTRIES compute the cotangents of each angle in mesh (V,F)
   
   Inputs:
     V  #V by dim list of rest domain positions
     F  #F by {3|4} list of {triangle|tetrahedra} indices into V
   Outputs:
       C  #F by 3 list of 1/2*cotangents corresponding angles
         for triangles, columns correspond to edges [1,2],[2,0],[0,1]
     OR
       C  #F by 6 list of 1/6*cotangents of dihedral angles*edge lengths
         for tets, columns along edges [1,2],[2,0],[0,1],[3,0],[3,1],[3,2] 
  
)igl_Qu8mg5v7";

npe_function(cotmatrix_entries)
npe_doc(ds_cotmatrix_entries)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 c;
    igl::cotmatrix_entries(v, f, c);
    return npe::move(c);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 c;
    igl::cotmatrix_entries(v, f, c);
    return npe::move(c);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


