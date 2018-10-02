// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/arap_linear_block.h>

const char* ds_arap_linear_block = R"igl_Qu8mg5v7(

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

 ARAP_LINEAR_BLOCK constructs a block of the matrix which constructs the
   linear terms of a given arap energy. When treating rotations as knowns
   (arranged in a column) then this constructs Kd of K such that the linear
   portion of the energy is as a column:
     K * R = [Kx Z  ... Ky Z  ... 
              Z  Kx ... Z  Ky ... 
              ... ]
   These blocks are also used to build the "covariance scatter matrices".
   Here we want to build a scatter matrix that multiplies against positions
   (treated as known) producing covariance matrices to fit each rotation.
   Notice that in the case of the RHS of the poisson solve the rotations are
   known and the positions unknown, and vice versa for rotation fitting.
   These linear block just relate the rotations to the positions, linearly in
   each.
  
   Templates:
     MatV  vertex position matrix, e.g. Eigen::MatrixXd
     MatF  face index matrix, e.g. Eigen::MatrixXd
     Scalar  e.g. double
   Inputs:
     V  #V by dim list of initial domain positions
     F  #F by #simplex size list of triangle indices into V
     d  coordinate of linear constructor to build
     energy  ARAPEnergyType enum value defining which energy is being used.
       See ARAPEnergyType.h for valid options and explanations.
   Outputs:
     Kd  #V by #V/#F block of the linear constructor matrix corresponding to
       coordinate d
  
)igl_Qu8mg5v7";

npe_function(arap_linear_block)
npe_doc(ds_arap_linear_block)

npe_arg(v, MatV &)
npe_arg(f, MatF &)
npe_arg(d, int)
npe_arg(energy, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    int & kd;
    igl::arap_linear_block(v, f, d, energy, kd);
    return npe::move(kd);
} else if (dtype.type() == npe::type_f64) {
    int & kd;
    igl::arap_linear_block(v, f, d, energy, kd);
    return npe::move(kd);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/arap_linear_block_spokes.h>

const char* ds_arap_linear_block_spokes = R"igl_Qu8mg5v7(

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

 Helper functions for each energy type
)igl_Qu8mg5v7";

npe_function(arap_linear_block_spokes)
npe_doc(ds_arap_linear_block_spokes)

npe_arg(v, MatV &)
npe_arg(f, MatF &)
npe_arg(d, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    int & kd;
    igl::arap_linear_block_spokes(v, f, d, kd);
    return npe::move(kd);
} else if (dtype.type() == npe::type_f64) {
    int & kd;
    igl::arap_linear_block_spokes(v, f, d, kd);
    return npe::move(kd);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/arap_linear_block_spokes_and_rims.h>

const char* ds_arap_linear_block_spokes_and_rims = R"igl_Qu8mg5v7(
See arap_linear_block_spokes_and_rims for the documentation.
)igl_Qu8mg5v7";

npe_function(arap_linear_block_spokes_and_rims)
npe_doc(ds_arap_linear_block_spokes_and_rims)

npe_arg(v, MatV &)
npe_arg(f, MatF &)
npe_arg(d, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    int & kd;
    igl::arap_linear_block_spokes_and_rims(v, f, d, kd);
    return npe::move(kd);
} else if (dtype.type() == npe::type_f64) {
    int & kd;
    igl::arap_linear_block_spokes_and_rims(v, f, d, kd);
    return npe::move(kd);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/arap_linear_block_elements.h>

const char* ds_arap_linear_block_elements = R"igl_Qu8mg5v7(
See arap_linear_block_elements for the documentation.
)igl_Qu8mg5v7";

npe_function(arap_linear_block_elements)
npe_doc(ds_arap_linear_block_elements)

npe_arg(v, MatV &)
npe_arg(f, MatF &)
npe_arg(d, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    int & kd;
    igl::arap_linear_block_elements(v, f, d, kd);
    return npe::move(kd);
} else if (dtype.type() == npe::type_f64) {
    int & kd;
    igl::arap_linear_block_elements(v, f, d, kd);
    return npe::move(kd);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


