// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/simplify_polyhedron.h>

const char* ds_simplify_polyhedron = R"igl_Qu8mg5v7(

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

 Simplify a polyhedron represented as a triangle mesh (OV,OF) by collapsing
   any edge that doesn't contribute to defining surface's pointset. This
   _would_ also make sense for open and non-manifold meshes, but the current
   implementation only works with closed manifold surfaces with well defined
   triangle normals.
  
   Inputs:
     OV  #OV by 3 list of input mesh vertex positions
     OF  #OF by 3 list of input mesh triangle indices into OV
   Outputs:
     V  #V by 3 list of output mesh vertex positions
     F  #F by 3 list of input mesh triangle indices into V
     J  #F list of indices into OF of birth parents
)igl_Qu8mg5v7";

npe_function(simplify_polyhedron)
npe_doc(ds_simplify_polyhedron)

npe_arg(ov, Eigen::MatrixXd &)
npe_arg(of, Eigen::MatrixXi &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::MatrixXd & v;
    Eigen::MatrixXi & f;
    Eigen::VectorXi & j;
    igl::simplify_polyhedron(ov, of, v, f, j);
    return std::make_tuple(    npe::move(v),
    npe::move(f),
    npe::move(j));
} else if (dtype.type() == npe::type_f64) {
    Eigen::MatrixXd & v;
    Eigen::MatrixXi & f;
    Eigen::VectorXi & j;
    igl::simplify_polyhedron(ov, of, v, f, j);
    return std::make_tuple(    npe::move(v),     npe::move(f),     npe::move(j));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


