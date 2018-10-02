#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/point_areas.h>

const char* ds_point_areas = R"igl_Qu8mg5v7(

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

 Given a 3D set of points P, each with a list of k-nearest-neighbours,
     estimate the geodesic voronoi area associated with each point.
    
     The k nearest neighbours may be known from running igl::knn_octree on
     the output data from igl::octree. We reccomend using a k value
     between 15 and 20 inclusive for accurate area estimation.
    
     N is used filter the neighbours, to ensure area estimation only occurs
     using neighbors that are on the same side of the surface (ie for thin
     sheets), as well as to solve the orientation ambiguity of the tangent
     plane normal.
    
     Note: This function *should* be implemented by pre-filtering I, rather
     than filtering in this function using N. In this case, the function
     would only take P and I as input.
    
     Inputs:
       P  #P by 3 list of point locations
       I  #P by k list of k-nearest-neighbor indices into P
       N  #P by 3 list of point normals
     Outputs:
       A  #P list of estimated areas
)igl_Qu8mg5v7";

npe_function(point_areas)
npe_doc(ds_point_areas)

npe_arg(p, dense_f64)
npe_arg(i, dense_f64)
npe_arg(n, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 a;
    igl::    copyleft::    cgal::point_areas(p, i, n, a);
    return npe::move(a);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 a;
    igl::    copyleft::    cgal::point_areas(p, i, n, a);
    return npe::move(a);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/point_areas.h>

const char* ds_point_areas = R"igl_Qu8mg5v7(

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

 This version can be used to output the tangent plane normal at each
     point. Since we area already fitting a plane to each point's neighbour
     set, the tangent plane normals come "for free"
    
     Inputs:
       P  #P by 3 list of point locations
       I  #P by k list of k-nearest-neighbor indices into P
       N  #P by 3 list of point normals
     Outputs:
       A  #P list of estimated areas
       T  #P by 3 list of tangent plane normals for each point
)igl_Qu8mg5v7";

npe_function(point_areas)
npe_doc(ds_point_areas)

npe_arg(p, dense_f64)
npe_arg(i, dense_f64)
npe_arg(n, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 a;
    dense_f32 t;
    igl::    copyleft::    cgal::point_areas(p, i, n, a, t);
    return std::make_tuple(    npe::move(a),
    npe::move(t));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 a;
    dense_f64 t;
    igl::    copyleft::    cgal::point_areas(p, i, n, a, t);
    return std::make_tuple(    npe::move(a),     npe::move(t));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


