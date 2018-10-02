// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/read_triangle_mesh.h>

const char* ds_read_triangle_mesh = R"igl_Qu8mg5v7(

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

 Simple wrapper, reads floating point precision but assigns to
       DerivedV::Scalar which may be a CGAL type
      
       Inputs:
         str  path to file
       Outputs:
         V  eigen double matrix #V by 3
         F  eigen int matrix #F by 3
       Returns true iff success
)igl_Qu8mg5v7";

npe_function(read_triangle_mesh)
npe_doc(ds_read_triangle_mesh)

npe_arg(str, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v;
    dense_i32 f;
    igl::    copyleft::    cgal::read_triangle_mesh(str, v, f);
    return std::make_tuple(    npe::move(v),
    npe::move(f));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v;
    dense_i32 f;
    igl::    copyleft::    cgal::read_triangle_mesh(str, v, f);
    return std::make_tuple(    npe::move(v),     npe::move(f));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


