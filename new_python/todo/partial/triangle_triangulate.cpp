// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/triangulate.h>

const char* ds_triangulate = R"igl_Qu8mg5v7(

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

 Triangulate the interior of a polygon using the triangle library.
    
     Inputs:
       V #V by 2 list of 2D vertex positions
       E #E by 2 list of vertex ids forming unoriented edges of the boundary of the polygon
       H #H by 2 coordinates of points contained inside holes of the polygon
       flags  string of options pass to triangle (see triangle documentation)
     Outputs:
       V2  #V2 by 2  coordinates of the vertives of the generated triangulation
       F2  #F2 by 3  list of indices forming the faces of the generated triangulation
    
)igl_Qu8mg5v7";

npe_function(triangulate)
npe_doc(ds_triangulate)

npe_arg(v, dense_f64)
npe_arg(e, dense_f64)
npe_arg(h, dense_f64)
npe_arg(flags, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v2;
    dense_f32 f2;
    igl::    triangle::triangulate(v, e, h, flags, v2, f2);
    return std::make_tuple(    npe::move(v2),
    npe::move(f2));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v2;
    dense_f64 f2;
    igl::    triangle::triangulate(v, e, h, flags, v2, f2);
    return std::make_tuple(    npe::move(v2),     npe::move(f2));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/triangulate.h>

const char* ds_triangulate = R"igl_Qu8mg5v7(

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

 Triangulate the interior of a polygon using the triangle library.
    
     Inputs:
       V #V by 2 list of 2D vertex positions
       E #E by 2 list of vertex ids forming unoriented edges of the boundary of the polygon
       H #H by 2 coordinates of points contained inside holes of the polygon
		   M #V list of markers for input vertices
       flags  string of options pass to triangle (see triangle documentation)
     Outputs:
       V2  #V2 by 2  coordinates of the vertives of the generated triangulation
       F2  #F2 by 3  list of indices forming the faces of the generated triangulation
		   M2  #V2 list of markers for output vertices
    
     TODO: expose the option to prevent Steiner points on the boundary
    
)igl_Qu8mg5v7";

npe_function(triangulate)
npe_doc(ds_triangulate)

npe_arg(v, dense_f64)
npe_arg(e, dense_f64)
npe_arg(h, dense_f64)
npe_arg(vm, dense_f64)
npe_arg(em, dense_f64)
npe_arg(flags, std::string)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v2;
    dense_f32 f2;
    dense_f32 vm2;
    dense_f32 em2;
    igl::    triangle::triangulate(v, e, h, vm, em, flags, v2, f2, vm2, em2);
    return std::make_tuple(    npe::move(v2),
    npe::move(f2),
    npe::move(vm2),
    npe::move(em2));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v2;
    dense_f64 f2;
    dense_f64 vm2;
    dense_f64 em2;
    igl::    triangle::triangulate(v, e, h, vm, em, flags, v2, f2, vm2, em2);
    return std::make_tuple(    npe::move(v2),     npe::move(f2),     npe::move(vm2),     npe::move(em2));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


