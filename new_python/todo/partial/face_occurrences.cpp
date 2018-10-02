// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/face_occurrences.h>

const char* ds_face_occurrences = R"igl_Qu8mg5v7(

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

 Count the occruances of each face (row) in a list of face indices
   (irrespecitive of order)
   Inputs:
     F  #F by simplex-size
   Outputs
     C  #F list of counts
   Known bug: triangles/tets only (where ignoring order still gives simplex)
)igl_Qu8mg5v7";

npe_function(face_occurrences)
npe_doc(ds_face_occurrences)

npe_arg(f, std::vector<std::vector<IntegerF> > &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<IntegerC> & c;
    igl::face_occurrences(f, c);
    return npe::move(c);
} else if (dtype.type() == npe::type_f64) {
    std::vector<IntegerC> & c;
    igl::face_occurrences(f, c);
    return npe::move(c);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


