#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/comb_line_field.h>

const char* ds_comb_line_field = R"igl_Qu8mg5v7(

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

 Inputs:
     V          #V by 3 eigen Matrix of mesh vertex 3D positions
     F          #F by 4 eigen Matrix of face (quad) indices
     PD1in      #F by 3 eigen Matrix of the first per face cross field vector
     PD2in      #F by 3 eigen Matrix of the second per face cross field vector
   Output:
     PD1out      #F by 3 eigen Matrix of the first combed cross field vector
     PD2out      #F by 3 eigen Matrix of the second combed cross field vector
  
)igl_Qu8mg5v7";

npe_function(comb_line_field)
npe_doc(ds_comb_line_field)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(pd1in, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 pd1out;
    igl::comb_line_field(v, f, pd1in, pd1out);
    return npe::move(pd1out);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 pd1out;
    igl::comb_line_field(v, f, pd1in, pd1out);
    return npe::move(pd1out);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


