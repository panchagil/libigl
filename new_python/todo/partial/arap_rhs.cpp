// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/arap_rhs.h>

const char* ds_arap_rhs = R"igl_Qu8mg5v7(

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

 ARAP_RHS build right-hand side constructor of global poisson solve for
   various Arap energies
   Inputs:
     V  #V by Vdim list of initial domain positions
     F  #F by 3 list of triangle indices into V
     dim  dimension being used at solve time. For deformation usually dim =
       V.cols(), for surface parameterization V.cols() = 3 and dim = 2
     energy  igl::ARAPEnergyType enum value defining which energy is being
       used. See igl::ARAPEnergyType.h for valid options and explanations.
   Outputs:
     K  #V*dim by #(F|V)*dim*dim matrix such that: 
       b = K * reshape(permute(R,[3 1 2]),size(V|F,1)*size(V,2)*size(V,2),1);
     
   See also: arap_linear_block
)igl_Qu8mg5v7";

npe_function(arap_rhs)
npe_doc(ds_arap_rhs)

npe_arg(v, Eigen::MatrixXd &)
npe_arg(f, Eigen::MatrixXi &)
npe_arg(dim, int)
npe_arg(energy, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    int & k;
    igl::arap_rhs(v, f, dim, energy, k);
    return npe::move(k);
} else if (dtype.type() == npe::type_f64) {
    int & k;
    igl::arap_rhs(v, f, dim, energy, k);
    return npe::move(k);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


