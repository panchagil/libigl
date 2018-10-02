#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/cut_mesh_from_singularities.h>

const char* ds_cut_mesh_from_singularities = R"igl_Qu8mg5v7(

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

 Given a mesh (V,F) and the integer mismatch of a cross field per edge
   (MMatch), finds the cut_graph connecting the singularities (seams) and the
   degree of the singularities singularity_index
  
   Input:
     V  #V by 3 list of mesh vertex positions
     F  #F by 3 list of faces
     MMatch  #F by 3 list of per corner integer mismatch
   Outputs:
     seams  #F by 3 list of per corner booleans that denotes if an edge is a
       seam or not
  
)igl_Qu8mg5v7";

npe_function(cut_mesh_from_singularities)
npe_doc(ds_cut_mesh_from_singularities)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(m_match, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 seams;
    igl::cut_mesh_from_singularities(v, f, m_match, seams);
    return npe::move(seams);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 seams;
    igl::cut_mesh_from_singularities(v, f, m_match, seams);
    return npe::move(seams);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


