// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/boundary_facets.h>

const char* ds_boundary_facets = R"igl_Qu8mg5v7(

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
     DerivedF  integer-value: i.e. from MatrixXi
)igl_Qu8mg5v7";

npe_function(boundary_facets)
npe_doc(ds_boundary_facets)

npe_arg(t, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_i32 f;
    igl::boundary_facets(t, f);
    return npe::move(f);
} else if (dtype.type() == npe::type_f64) {
    dense_i32 f;
    igl::boundary_facets(t, f);
    return npe::move(f);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/boundary_facets.h>

const char* ds_boundary_facets = R"igl_Qu8mg5v7(

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

 Same as above but returns F
)igl_Qu8mg5v7";

npe_function(boundary_facets)
npe_doc(ds_boundary_facets)

npe_arg(t, dense_f64)



npe_begin_code()
using namespace std;



igl::boundary_facets(t);

return

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/boundary_facets.h>

const char* ds_boundary_facets = R"igl_Qu8mg5v7(

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

 BOUNDARY_FACETS Determine boundary faces (edges) of tetrahedra (triangles)
   stored in T (analogous to qptoolbox's `outline` and `boundary_faces`).
  
   Templates:
     IntegerT  integer-value: e.g. int
     IntegerF  integer-value: e.g. int
   Input:
    T  tetrahedron (triangle) index list, m by 4 (3), where m is the number of tetrahedra
   Output:
    F  list of boundary faces, n by 3 (2), where n is the number of boundary faces
  
  
)igl_Qu8mg5v7";

npe_function(boundary_facets)
npe_doc(ds_boundary_facets)

npe_arg(t, std::vector<std::vector<IntegerT> > &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<IntegerF> > & f;
    igl::boundary_facets(t, f);
    return npe::move(f);
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<IntegerF> > & f;
    igl::boundary_facets(t, f);
    return npe::move(f);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


