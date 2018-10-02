#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/lexicographic_triangulation.h>

const char* ds_lexicographic_triangulation = R"igl_Qu8mg5v7(

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

 Given a set of points in 2D, return a lexicographic triangulation of these
       points.
      
       Inputs:
         P  #P by 2 list of vertex positions
      
       Outputs:
         F  #F by 3 of faces in lexicographic triangulation.
)igl_Qu8mg5v7";

npe_function(lexicographic_triangulation)
npe_doc(ds_lexicographic_triangulation)

npe_arg(p, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_i32 f;
    igl::    copyleft::    cgal::lexicographic_triangulation(p, f);
    return npe::move(f);
} else if (dtype.type() == npe::type_f64) {
    dense_i32 f;
    igl::    copyleft::    cgal::lexicographic_triangulation(p, f);
    return npe::move(f);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


