#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/average_onto_faces.h>

const char* ds_average_onto_faces = R"igl_Qu8mg5v7(

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

 average_onto_vertices 
   Move a scalar field defined on faces to vertices by averaging
  
   Input:
     F  #F by ss list of simples/faces
     S  #V by dim list of per-vertex values
   Output:
     SF  #F by dim list of per-face values
)igl_Qu8mg5v7";

npe_function(average_onto_faces)
npe_doc(ds_average_onto_faces)

npe_arg(f, dense_i32)
npe_arg(s, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 sf;
    igl::average_onto_faces(f, s, sf);
    return npe::move(sf);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 sf;
    igl::average_onto_faces(f, s, sf);
    return npe::move(sf);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


