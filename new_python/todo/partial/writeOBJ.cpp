// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/writeOBJ.h>

const char* ds_write_obj = R"igl_Qu8mg5v7(

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

 Write a mesh in an ascii obj file
   Inputs:
     str  path to outputfile
     V  #V by 3 mesh vertex positions
     F  #F by 3|4 mesh indices into V
     CN #CN by 3 normal vectors
     FN  #F by 3|4 corner normal indices into CN
     TC  #TC by 2|3 texture coordinates
     FTC #F by 3|4 corner texture coord indices into TC
   Returns true on success, false on error
  
   Known issues: Horrifyingly, this does not have the same order of
   parameters as readOBJ.
)igl_Qu8mg5v7";

npe_function(write_obj)
npe_doc(ds_write_obj)

npe_arg(str, std::string)
npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(cn, dense_f64)
npe_arg(fn, dense_f64)
npe_arg(tc, dense_f64)
npe_arg(ftc, dense_f64)



npe_begin_code()
using namespace std;



igl::writeOBJ(str, v, f, cn, fn, tc, ftc);

return

npe_end_code()
#include <igl/writeOBJ.h>

const char* ds_write_obj = R"igl_Qu8mg5v7(
See writeOBJ for the documentation.
)igl_Qu8mg5v7";

npe_function(write_obj)
npe_doc(ds_write_obj)

npe_arg(str, std::string)
npe_arg(v, dense_f64)
npe_arg(f, dense_i32)



npe_begin_code()
using namespace std;



igl::writeOBJ(str, v, f);

return

npe_end_code()


