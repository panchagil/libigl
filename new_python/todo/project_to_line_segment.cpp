#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/project_to_line_segment.h>

const char* ds_project_to_line_segment = R"igl_Qu8mg5v7(

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

 PROJECT_TO_LINE_SEGMENT project points onto vectors, that is find the parameter
   t for a point p such that proj_p = (y-x).*t, additionally compute the
   squared distance from p to the line of the vector, such that 
   |p - proj_p|² = sqr_d
  
   [T,sqrD] = project_to_line_segment(P,S,D)
  
   Inputs:
     P  #P by dim list of points to be projected
     S  size dim start position of line vector
     D  size dim destination position of line vector
   Outputs:
     T  #P by 1 list of parameters
     sqrD  #P by 1 list of squared distances
  
  
)igl_Qu8mg5v7";

npe_function(project_to_line_segment)
npe_doc(ds_project_to_line_segment)

npe_arg(p, dense_f64)
npe_arg(s, dense_f64)
npe_arg(d, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 t;
    dense_f32 sqr_d;
    igl::project_to_line_segment(p, s, d, t, sqr_d);
    return std::make_tuple(    npe::move(t),
    npe::move(sqr_d));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 t;
    dense_f64 sqr_d;
    igl::project_to_line_segment(p, s, d, t, sqr_d);
    return std::make_tuple(    npe::move(t),     npe::move(sqr_d));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


