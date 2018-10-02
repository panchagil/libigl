// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/point_segment_squared_distance.h>

const char* ds_point_segment_squared_distance = R"igl_Qu8mg5v7(

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

 Given a point P1 and segment S2 find the points on each of closest
       approach and the squared distance thereof.
       
       Inputs:
         P1  point
         S2  segment
       Outputs:
         P2  point on S2 closest to P1
         d  distance betwee P1 and S2
)igl_Qu8mg5v7";

npe_function(point_segment_squared_distance)
npe_doc(ds_point_segment_squared_distance)

npe_arg(p1, CGAL::Point_3<Kernel> &)
npe_arg(s2, CGAL::Segment_3<Kernel> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    CGAL::Point_3<Kernel> & p2;
    typename Kernel::FT & d;
    igl::    copyleft::    cgal::point_segment_squared_distance(p1, s2, p2, d);
    return std::make_tuple(    npe::move(p2),
    npe::move(d));
} else if (dtype.type() == npe::type_f64) {
    CGAL::Point_3<Kernel> & p2;
    typename Kernel::FT & d;
    igl::    copyleft::    cgal::point_segment_squared_distance(p1, s2, p2, d);
    return std::make_tuple(    npe::move(p2),     npe::move(d));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


