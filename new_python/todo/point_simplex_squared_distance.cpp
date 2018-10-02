// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/point_simplex_squared_distance.h>

const char* ds_point_simplex_squared_distance = R"igl_Qu8mg5v7(

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

 Determine squared distance from a point to linear simplex. 
  
   Inputs:
     p  d-long query point
     V  #V by d list of vertices
     Ele  #Ele by ss<=d+1 list of simplex indices into V
     i  index into Ele of simplex
   Outputs:
     sqr_d  squared distance of Ele(i) to p
     c  closest point on Ele(i) 
  
)igl_Qu8mg5v7";

npe_function(point_simplex_squared_distance)
npe_doc(ds_point_simplex_squared_distance)

npe_arg(p, dense_f64)
npe_arg(v, dense_f64)
npe_arg(ele, dense_f64)
npe_arg(i, typename DerivedEle::Index)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Derivedsqr_d & sqr_d;
    dense_f32 c;
    igl::point_simplex_squared_distance(p, v, ele, i, sqr_d, c);
    return std::make_tuple(    npe::move(sqr_d),
    npe::move(c));
} else if (dtype.type() == npe::type_f64) {
    Derivedsqr_d & sqr_d;
    dense_f64 c;
    igl::point_simplex_squared_distance(p, v, ele, i, sqr_d, c);
    return std::make_tuple(    npe::move(sqr_d),     npe::move(c));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/point_simplex_squared_distance.h>

const char* ds_point_simplex_squared_distance = R"igl_Qu8mg5v7(

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

 Determine squared distance from a point to linear simplex.
   Also return barycentric coordinate of closest point. 
  
   Inputs:
     p  d-long query point
     V  #V by d list of vertices
     Ele  #Ele by ss<=d+1 list of simplex indices into V
     i  index into Ele of simplex
   Outputs:
     sqr_d  squared distance of Ele(i) to p
     c  closest point on Ele(i) 
     b  barycentric coordinates of closest point on Ele(i) 
  
)igl_Qu8mg5v7";

npe_function(point_simplex_squared_distance)
npe_doc(ds_point_simplex_squared_distance)

npe_arg(p, dense_f64)
npe_arg(v, dense_f64)
npe_arg(ele, dense_f64)
npe_arg(i, typename DerivedEle::Index)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Derivedsqr_d & sqr_d;
    dense_f32 c;
    dense_f32 b;
    igl::point_simplex_squared_distance(p, v, ele, i, sqr_d, c, b);
    return std::make_tuple(    npe::move(sqr_d),
    npe::move(c),
    npe::move(b));
} else if (dtype.type() == npe::type_f64) {
    Derivedsqr_d & sqr_d;
    dense_f64 c;
    dense_f64 b;
    igl::point_simplex_squared_distance(p, v, ele, i, sqr_d, c, b);
    return std::make_tuple(    npe::move(sqr_d),     npe::move(c),     npe::move(b));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


