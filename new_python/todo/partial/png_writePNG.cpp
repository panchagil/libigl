// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/writePNG.h>

const char* ds_write_png = R"igl_Qu8mg5v7(

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

 Writes an image to a png file
    
     Input:
      R,G,B,A texture channels
     Output:
      png_file  path to .png file
     Returns true on success, false on failure
    
)igl_Qu8mg5v7";

npe_function(write_png)
npe_doc(ds_write_png)

npe_arg(r, Eigen::Matrix<unsigned char, Eigen::Dynamic, Eigen::Dynamic>)
npe_arg(g, Eigen::Matrix<unsigned char, Eigen::Dynamic, Eigen::Dynamic>)
npe_arg(b, Eigen::Matrix<unsigned char, Eigen::Dynamic, Eigen::Dynamic>)
npe_arg(a, Eigen::Matrix<unsigned char, Eigen::Dynamic, Eigen::Dynamic>)
npe_arg(png_file, std::string)



npe_begin_code()
using namespace std;



igl::png::writePNG(r, g, b, a, png_file);

return

npe_end_code()


