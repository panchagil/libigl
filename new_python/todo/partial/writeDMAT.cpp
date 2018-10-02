// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/writeDMAT.h>

const char* ds_write_dmat = R"igl_Qu8mg5v7(

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

 Write a matrix using ascii dmat file type
  
   Template:
     Mat  matrix type that supports .rows(), .cols(), operator(i,j)
   Inputs:
     file_name  path to .dmat file
     W  eigen matrix containing to-be-written coefficients
     ascii  write ascii file {true}
   Returns true on success, false on error
  
)igl_Qu8mg5v7";

npe_function(write_dmat)
npe_doc(ds_write_dmat)

npe_arg(file_name, std::string)
npe_arg(w, dense_f64)
npe_arg(ascii, bool)



npe_begin_code()
using namespace std;



igl::writeDMAT(file_name, w, ascii);

return

npe_end_code()
#include <igl/writeDMAT.h>

const char* ds_write_dmat = R"igl_Qu8mg5v7(
See writeDMAT for the documentation.
)igl_Qu8mg5v7";

npe_function(write_dmat)
npe_doc(ds_write_dmat)

npe_arg(file_name, std::string)
npe_arg(w, std::vector<std::vector<double> > &)
npe_arg(ascii, bool)



npe_begin_code()
using namespace std;



igl::writeDMAT(file_name, w, ascii);

return

npe_end_code()
#include <igl/writeDMAT.h>

const char* ds_write_dmat = R"igl_Qu8mg5v7(
See writeDMAT for the documentation.
)igl_Qu8mg5v7";

npe_function(write_dmat)
npe_doc(ds_write_dmat)

npe_arg(file_name, std::string)
npe_arg(w, std::vector<Scalar> &)
npe_arg(ascii, bool)



npe_begin_code()
using namespace std;



igl::writeDMAT(file_name, w, ascii);

return

npe_end_code()


