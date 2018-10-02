#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/convex_hull.h>

const char* ds_convex_hull = R"igl_Qu8mg5v7(

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

 Given a set of points (V), compute the convex hull as a triangle mesh (W,G)
       
       Inputs:
         V  #V by 3 list of input points
       Outputs:
         W  #W by 3 list of convex hull points
         G  #G by 3 list of triangle indices into W
)igl_Qu8mg5v7";

npe_function(convex_hull)
npe_doc(ds_convex_hull)

npe_arg(v, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 w;
    dense_f32 g;
    igl::    copyleft::    cgal::convex_hull(v, w, g);
    return std::make_tuple(    npe::move(w),
    npe::move(g));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 w;
    dense_f64 g;
    igl::    copyleft::    cgal::convex_hull(v, w, g);
    return std::make_tuple(    npe::move(w),     npe::move(g));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/convex_hull.h>

const char* ds_convex_hull = R"igl_Qu8mg5v7(

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

 Given a set of points (V), compute the convex hull as a triangle mesh (F)
       over input vertex set (V)
       
       Inputs:
         V  #V by 3 list of input points
       Outputs:
         F  #F by 3 list of triangle indices into V
      
)igl_Qu8mg5v7";

npe_function(convex_hull)
npe_doc(ds_convex_hull)

npe_arg(v, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_i32 f;
    igl::    copyleft::    cgal::convex_hull(v, f);
    return npe::move(f);
} else if (dtype.type() == npe::type_f64) {
    dense_i32 f;
    igl::    copyleft::    cgal::convex_hull(v, f);
    return npe::move(f);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


