// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/boundary_loop.h>

const char* ds_boundary_loop = R"igl_Qu8mg5v7(

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

 Compute list of ordered boundary loops for a manifold mesh.
  
   Templates:
    Index  index type
   Inputs:
     F  #V by dim list of mesh faces
   Outputs:
     L  list of loops where L[i] = ordered list of boundary vertices in loop i
  
)igl_Qu8mg5v7";

npe_function(boundary_loop)
npe_doc(ds_boundary_loop)

npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::vector<int> > & l;
    igl::boundary_loop(f, l);
    return npe::move(l);
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::vector<int> > & l;
    igl::boundary_loop(f, l);
    return npe::move(l);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/boundary_loop.h>

const char* ds_boundary_loop = R"igl_Qu8mg5v7(

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

 Compute ordered boundary loops for a manifold mesh and return the 
   longest loop in terms of vertices.
  
   Templates:
    Index  index type
   Inputs:
     F  #V by dim list of mesh faces
   Outputs:
     L  ordered list of boundary vertices of longest boundary loop
  
)igl_Qu8mg5v7";

npe_function(boundary_loop)
npe_doc(ds_boundary_loop)

npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 l;
    igl::boundary_loop(f, l);
    return npe::move(l);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 l;
    igl::boundary_loop(f, l);
    return npe::move(l);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/boundary_loop.h>

const char* ds_boundary_loop = R"igl_Qu8mg5v7(

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

 Compute ordered boundary loops for a manifold mesh and return the 
   longest loop in terms of vertices.
  
   Templates:
    Index  index type
   Inputs:
     F  #V by dim list of mesh faces
   Outputs:
     L  ordered list of boundary vertices of longest boundary loop
  
)igl_Qu8mg5v7";

npe_function(boundary_loop)
npe_doc(ds_boundary_loop)

npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<Index> & l;
    igl::boundary_loop(f, l);
    return npe::move(l);
} else if (dtype.type() == npe::type_f64) {
    std::vector<Index> & l;
    igl::boundary_loop(f, l);
    return npe::move(l);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


