// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/jet.h>

const char* ds_jet = R"igl_Qu8mg5v7(

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
     Z  #Z list of factors
     normalize  whether to normalize Z to be tightly between [0,1]
   Outputs:
     C  #C by 3 list of rgb colors
)igl_Qu8mg5v7";

npe_function(jet)
npe_doc(ds_jet)

npe_arg(z, dense_f64)
npe_arg(normalize, bool)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 c;
    igl::jet(z, normalize, c);
    return npe::move(c);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 c;
    igl::jet(z, normalize, c);
    return npe::move(c);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/jet.h>

const char* ds_jet = R"igl_Qu8mg5v7(

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

 JET like MATLAB's jet
  
   Inputs:
     m  number of colors 
   Outputs:
     J  m by list of RGB colors between 0 and 1
  
#ifndef IGL_NO_EIGEN
  void jet(const int m, Eigen::MatrixXd & J);
#endif
   Wrapper for directly computing [r,g,b] values for a given factor f between
   0 and 1
  
   Inputs:
     f  factor determining color value as if 0 was min and 1 was max
   Outputs:
     r  red value
     g  green value
     b  blue value
)igl_Qu8mg5v7";

npe_function(jet)
npe_doc(ds_jet)

npe_arg(f, T)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    T * rgb;
    igl::jet(f, rgb);
    return npe::move(rgb);
} else if (dtype.type() == npe::type_f64) {
    T * rgb;
    igl::jet(f, rgb);
    return npe::move(rgb);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/jet.h>

const char* ds_jet = R"igl_Qu8mg5v7(
See jet for the documentation.
)igl_Qu8mg5v7";

npe_function(jet)
npe_doc(ds_jet)

npe_arg(f, T)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    T & r;
    T & g;
    T & b;
    igl::jet(f, r, g, b);
    return std::make_tuple(    npe::move(r),
    npe::move(g),
    npe::move(b));
} else if (dtype.type() == npe::type_f64) {
    T & r;
    T & g;
    T & b;
    igl::jet(f, r, g, b);
    return std::make_tuple(    npe::move(r),     npe::move(g),     npe::move(b));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/jet.h>

const char* ds_jet = R"igl_Qu8mg5v7(

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
     min_z  value at blue
     max_z  value at red
)igl_Qu8mg5v7";

npe_function(jet)
npe_doc(ds_jet)

npe_arg(z, dense_f64)
npe_arg(min_z, double)
npe_arg(max_z, double)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 c;
    igl::jet(z, min_z, max_z, c);
    return npe::move(c);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 c;
    igl::jet(z, min_z, max_z, c);
    return npe::move(c);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


