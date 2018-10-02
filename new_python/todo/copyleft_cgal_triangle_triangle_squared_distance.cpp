// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/triangle_triangle_squared_distance.h>

const char* ds_triangle_triangle_squared_distance = R"igl_Qu8mg5v7(

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

 Given two triangles T1 and T2 find the points on each of closest
       approach and the squared distance thereof.
       
       Inputs:
         T1  first triangle
         T2  second triangle
       Outputs:
         P1  point on T1 closest to T2
         P2  point on T2 closest to T1
         d  distance betwee P1 and T2
       Returns true if the closest approach is unique.
)igl_Qu8mg5v7";

npe_function(triangle_triangle_squared_distance)
npe_doc(ds_triangle_triangle_squared_distance)

npe_arg(t1, CGAL::Triangle_3<Kernel> &)
npe_arg(t2, CGAL::Triangle_3<Kernel> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    CGAL::Point_3<Kernel> & p1;
    CGAL::Point_3<Kernel> & p2;
    typename Kernel::FT & d;
    igl::    copyleft::    cgal::triangle_triangle_squared_distance(t1, t2, p1, p2, d);
    return std::make_tuple(    npe::move(p1),
    npe::move(p2),
    npe::move(d));
} else if (dtype.type() == npe::type_f64) {
    CGAL::Point_3<Kernel> & p1;
    CGAL::Point_3<Kernel> & p2;
    typename Kernel::FT & d;
    igl::    copyleft::    cgal::triangle_triangle_squared_distance(t1, t2, p1, p2, d);
    return std::make_tuple(    npe::move(p1),     npe::move(p2),     npe::move(d));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


