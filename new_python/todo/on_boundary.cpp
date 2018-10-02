// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/on_boundary.h>

const char* ds_on_boundary = R"igl_Qu8mg5v7(

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

 Templates:
     DerivedT  integer-value: i.e. from MatrixXi
     DerivedI  bool-value: i.e. from MatrixXi
     DerivedC  bool-value: i.e. from MatrixXi
)igl_Qu8mg5v7";

npe_function(on_boundary)
npe_doc(ds_on_boundary)

npe_arg(t, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 i;
    dense_f32 c;
    igl::on_boundary(t, i, c);
    return std::make_tuple(    npe::move(i),
    npe::move(c));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 i;
    dense_f64 c;
    igl::on_boundary(t, i, c);
    return std::make_tuple(    npe::move(i),     npe::move(c));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/on_boundary.h>

const char* ds_on_boundary = R"igl_Qu8mg5v7(

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

 ON_BOUNDARY Determine boundary facets of mesh elements stored in T
  
   Templates:
     IntegerT  integer-value: i.e. int
     IntegerF  integer-value: i.e. int
   Input:
    T  triangle|tetrahedron index list, m by 3|4, where m is the number of
      elements
   Output:
    I  m long list of bools whether tet is on boundary
    C  m by 3|4 list of bools whether opposite facet is on boundary
  
)igl_Qu8mg5v7";

npe_function(on_boundary)
npe_doc(ds_on_boundary)

npe_arg(t, std::vector<std::vector<IntegerT> > &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<bool> & i;
    std::vector<std::vector<bool> > & c;
    igl::on_boundary(t, i, c);
    return std::make_tuple(    npe::move(i),
    npe::move(c));
} else if (dtype.type() == npe::type_f64) {
    std::vector<bool> & i;
    std::vector<std::vector<bool> > & c;
    igl::on_boundary(t, i, c);
    return std::make_tuple(    npe::move(i),     npe::move(c));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


