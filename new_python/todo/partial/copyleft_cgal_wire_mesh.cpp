// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/wire_mesh.h>

const char* ds_wire_mesh = R"igl_Qu8mg5v7(

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

 Construct a "wire" or "wireframe" or "strut" surface mesh, given a
       one-dimensional network of straight edges.
      
       Inputs:
         WV  #WV by 3 list of vertex positions
         WE  #WE by 2 list of edge indices into WV
         th  diameter thickness of wire 
         poly_size  number of sides on each wire (e.g., 4 would produce wires by
           connecting rectangular prisms).
         solid  whether to resolve self-intersections to
           create a "solid" output mesh (cf., [Zhou et al. 2016]
       Outputs:
         V  #V by 3 list of output vertices
         F  #F by 3 list of output triangle indices into V
         J  #F list of indices into [0,#WV+#WE) revealing "birth simplex" of
           output faces J(j) < #WV means the face corresponds to the J(j)th
           vertex in WV. J(j) >= #WV means the face corresponds to the
           (J(j)-#WV)th edge in WE.
)igl_Qu8mg5v7";

npe_function(wire_mesh)
npe_doc(ds_wire_mesh)

npe_arg(wv, dense_f64)
npe_arg(we, dense_f64)
npe_arg(th, double)
npe_arg(poly_size, int)
npe_arg(solid, bool)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v;
    dense_i32 f;
    dense_f32 j;
    igl::    copyleft::    cgal::wire_mesh(wv, we, th, poly_size, solid, v, f, j);
    return std::make_tuple(    npe::move(v),
    npe::move(f),
    npe::move(j));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v;
    dense_i32 f;
    dense_f64 j;
    igl::    copyleft::    cgal::wire_mesh(wv, we, th, poly_size, solid, v, f, j);
    return std::make_tuple(    npe::move(v),     npe::move(f),     npe::move(j));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/wire_mesh.h>

const char* ds_wire_mesh = R"igl_Qu8mg5v7(

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

 Default with solid=true
)igl_Qu8mg5v7";

npe_function(wire_mesh)
npe_doc(ds_wire_mesh)

npe_arg(wv, dense_f64)
npe_arg(we, dense_f64)
npe_arg(th, double)
npe_arg(poly_size, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 v;
    dense_i32 f;
    dense_f32 j;
    igl::    copyleft::    cgal::wire_mesh(wv, we, th, poly_size, v, f, j);
    return std::make_tuple(    npe::move(v),
    npe::move(f),
    npe::move(j));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 v;
    dense_i32 f;
    dense_f64 j;
    igl::    copyleft::    cgal::wire_mesh(wv, we, th, poly_size, v, f, j);
    return std::make_tuple(    npe::move(v),     npe::move(f),     npe::move(j));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


