// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/draw_point.h>

const char* ds_draw_point = R"igl_Qu8mg5v7(

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

double POINT_COLOR[3] = {239./255.,213./255.,46./255.};
     Draw a nice looking, colored dot at a given point in 3d.
    
     Note: expects that GL_CURRENT_COLOR is set with the desired foreground color
     
     Inputs:
       x  x-coordinate of point, modelview coordinates
       y  y-coordinate of point, modelview coordinates
       z  z-coordinate of point, modelview coordinates
       requested_r  outer-most radius of dot {7}, measured in screen space pixels
       selected  fills inner circle with black {false}
     Asserts that requested_r does not exceed 0.5*GL_POINT_SIZE_MAX
)igl_Qu8mg5v7";

npe_function(draw_point)
npe_doc(ds_draw_point)

npe_arg(x, double)
npe_arg(y, double)
npe_arg(z, double)
npe_arg(requested_r, double)
npe_arg(selected, bool)



npe_begin_code()
using namespace std;



igl::opengl2::draw_point(x, y, z, requested_r, selected);

return

npe_end_code()
#include <igl/draw_point.h>

const char* ds_draw_point = R"igl_Qu8mg5v7(
See draw_point for the documentation.
)igl_Qu8mg5v7";

npe_function(draw_point)
npe_doc(ds_draw_point)

npe_arg(p, dense_f64)
npe_arg(requested_r, double)
npe_arg(selected, bool)



npe_begin_code()
using namespace std;



igl::opengl2::draw_point(p, requested_r, selected);

return

npe_end_code()


