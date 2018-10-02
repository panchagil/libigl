// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/ramer_douglas_peucker.h>

const char* ds_ramer_douglas_peucker = R"igl_Qu8mg5v7(

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

 Ramer-Douglas-Peucker piecewise-linear curve simplification.
  
   Inputs:
     P  #P by dim ordered list of vertices along the curve
     tol  tolerance (maximal euclidean distance allowed between the new line
       and a vertex)
   Outputs:
     S  #S by dim ordered list of points along the curve
     J  #S list of indices into P so that S = P(J,:)
)igl_Qu8mg5v7";

npe_function(ramer_douglas_peucker)
npe_doc(ds_ramer_douglas_peucker)

npe_arg(p, dense_f64)
npe_arg(tol, typename DerivedP::Scalar)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 s;
    dense_f32 j;
    igl::ramer_douglas_peucker(p, tol, s, j);
    return std::make_tuple(    npe::move(s),
    npe::move(j));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 s;
    dense_f64 j;
    igl::ramer_douglas_peucker(p, tol, s, j);
    return std::make_tuple(    npe::move(s),     npe::move(j));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/ramer_douglas_peucker.h>

const char* ds_ramer_douglas_peucker = R"igl_Qu8mg5v7(

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

 Run (Ramer-)Duglass-Peucker curve simplification but keep track of where
   every point on the original curve maps to on the simplified curve.
  
   Inputs:
     P  #P by dim list of points, (use P([1:end 1],:) for loops)
     tol  DP tolerance
   Outputs:
     S  #S by dim list of points along simplified curve
     J  #S indices into P of simplified points
     Q  #P by dim list of points mapping along simplified curve
  
)igl_Qu8mg5v7";

npe_function(ramer_douglas_peucker)
npe_doc(ds_ramer_douglas_peucker)

npe_arg(p, dense_f64)
npe_arg(tol, typename DerivedP::Scalar)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 s;
    dense_f32 j;
    dense_f32 q;
    igl::ramer_douglas_peucker(p, tol, s, j, q);
    return std::make_tuple(    npe::move(s),
    npe::move(j),
    npe::move(q));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 s;
    dense_f64 j;
    dense_f64 q;
    igl::ramer_douglas_peucker(p, tol, s, j, q);
    return std::make_tuple(    npe::move(s),     npe::move(j),     npe::move(q));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


