// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/unzip_corners.h>

const char* ds_unzip_corners = R"igl_Qu8mg5v7(

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

 UNZIP_CORNERS Given a triangle mesh where corners of each triangle index
   different matrices of attributes (e.g. read from an OBJ file), unzip the
   corners into unique efficiently: attributes become properly vertex valued
   (usually creating greater than #V but less than #F*3 vertices).
  
   To pass a list of attributes this function takes an std::vector of
   std::reference_wrapper of an Eigen::... type. This allows you to use list
   initializers **without** incurring a copy, but means you'll need to
   provide the derived type of A as an explicit template parameter:
  
       unzip_corners<Eigen::MatrixXi>({F,FTC,FN},U,G,J);
  
   Inputs:
     A  #A list of #F by 3 attribute indices, typically {F,FTC,FN}
   Outputs:
     U  #U by #A list of indices into each attribute for each unique mesh
       vertex: U(v,a) is the attribute index of vertex v in attribute a.
     G  #F by 3 list of triangle indices into U
   Example:
     [V,F,TC,FTC] = readOBJ('~/Downloads/kiwis/kiwi.obj');
     [U,G] = unzip_corners(cat(3,F,FTC));
     % display mesh
     tsurf(G,V(U(:,1),:));
     % display texture coordinates
     tsurf(G,TC(U(:,2),:));
  
)igl_Qu8mg5v7";

npe_function(unzip_corners)
npe_doc(ds_unzip_corners)

npe_arg(a, std::vector<std::reference_wrapper<DerivedA> > &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 u;
    dense_f32 g;
    dense_f32 j;
    igl::unzip_corners(a, u, g, j);
    return std::make_tuple(    npe::move(u),
    npe::move(g),
    npe::move(j));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 u;
    dense_f64 g;
    dense_f64 j;
    igl::unzip_corners(a, u, g, j);
    return std::make_tuple(    npe::move(u),     npe::move(g),     npe::move(j));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


