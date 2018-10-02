// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/in_element.h>

const char* ds_in_element = R"igl_Qu8mg5v7(

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

 Determine whether each point in a list of points is in the elements of a
   mesh.
  
   templates:
     DIM  dimension of vertices in V (# of columns)
   Inputs:
     V  #V by dim list of mesh vertex positions.
     Ele  #Ele by dim+1 list of mesh indices into #V.
     Q  #Q by dim list of query point positions
     aabb  axis-aligned bounding box tree object (see AABB.h)
   Outputs:
     I  #Q list of indices into Ele of first containing element (-1 means no
       containing element)
)igl_Qu8mg5v7";

npe_function(in_element)
npe_doc(ds_in_element)

npe_arg(v, dense_f64)
npe_arg(ele, Eigen::MatrixXi &)
npe_arg(q, dense_f64)
npe_arg(aabb, AABB<DerivedV, DIM> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::VectorXi & i;
    igl::in_element(v, ele, q, aabb, i);
    return npe::move(i);
} else if (dtype.type() == npe::type_f64) {
    Eigen::VectorXi & i;
    igl::in_element(v, ele, q, aabb, i);
    return npe::move(i);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/in_element.h>

const char* ds_in_element = R"igl_Qu8mg5v7(

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

 Outputs:
     I  #Q by #Ele sparse matrix revealing whether each element contains each
       point: I(q,e) means point q is in element e
)igl_Qu8mg5v7";

npe_function(in_element)
npe_doc(ds_in_element)

npe_arg(v, dense_f64)
npe_arg(ele, Eigen::MatrixXi &)
npe_arg(q, dense_f64)
npe_arg(aabb, AABB<DerivedV, DIM> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Sparse_f32 i;
    igl::in_element(v, ele, q, aabb, i);
    return npe::move(i);
} else if (dtype.type() == npe::type_f64) {
    Sparse_f64 i;
    igl::in_element(v, ele, q, aabb, i);
    return npe::move(i);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


