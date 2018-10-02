// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/point_triangle_squared_distance.h>

const char* ds_point_triangle_squared_distance = R"igl_Qu8mg5v7(

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

 Given a point P1 and triangle T2 find the points on each of closest
       approach and the squared distance thereof.
       
       Inputs:
         P1  point
         T2  triangle
       Outputs:
         P2  point on T2 closest to P1
         d  distance betwee P1 and T2
)igl_Qu8mg5v7";

npe_function(point_triangle_squared_distance)
npe_doc(ds_point_triangle_squared_distance)

npe_arg(p1, CGAL::Point_3<Kernel> &)
npe_arg(t2, CGAL::Triangle_3<Kernel> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    CGAL::Point_3<Kernel> & p2;
    typename Kernel::FT & d;
    igl::    copyleft::    cgal::point_triangle_squared_distance(p1, t2, p2, d);
    return std::make_tuple(    npe::move(p2),
    npe::move(d));
} else if (dtype.type() == npe::type_f64) {
    CGAL::Point_3<Kernel> & p2;
    typename Kernel::FT & d;
    igl::    copyleft::    cgal::point_triangle_squared_distance(p1, t2, p2, d);
    return std::make_tuple(    npe::move(p2),     npe::move(d));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


