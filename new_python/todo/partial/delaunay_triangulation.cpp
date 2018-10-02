// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/delaunay_triangulation.h>

const char* ds_delaunay_triangulation = R"igl_Qu8mg5v7(

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

 Given a set of points in 2D, return a Delaunay triangulation of these
   points.
  
   Inputs:
     V  #V by 2 list of vertex positions
     orient2D  A functor such that orient2D(pa, pb, pc) returns
                 1 if pa,pb,pc forms a conterclockwise triangle.
                -1 if pa,pb,pc forms a clockwise triangle.
                 0 if pa,pb,pc are collinear.
                where the argument pa,pb,pc are of type Scalar[2].
     incircle  A functor such that incircle(pa, pb, pc, pd) returns
                 1 if pd is on the positive size of circumcirle of (pa,pb,pc)
                -1 if pd is on the positive size of circumcirle of (pa,pb,pc)
                 0 if pd is cocircular with pa, pb, pc.
   Outputs:
     F  #F by 3 of faces in Delaunay triangulation.
)igl_Qu8mg5v7";

npe_function(delaunay_triangulation)
npe_doc(ds_delaunay_triangulation)

npe_arg(v, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Orient2D orient2_d;
    InCircle incircle;
    dense_i32 f;
    igl::delaunay_triangulation(v, orient2_d, incircle, f);
    return std::make_tuple(    npe::move(orient2_d),
    npe::move(incircle),
    npe::move(f));
} else if (dtype.type() == npe::type_f64) {
    Orient2D orient2_d;
    InCircle incircle;
    dense_i32 f;
    igl::delaunay_triangulation(v, orient2_d, incircle, f);
    return std::make_tuple(    npe::move(orient2_d),     npe::move(incircle),     npe::move(f));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


