// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/cdt.h>

const char* ds_cdt = R"igl_Qu8mg5v7(

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

 CDT Construct the constrained delaunay triangulation of the convex hull
     of a given set of points and segments in 2D. This differs from a direct
     call to triangulate because it will preprocess the input to remove
     duplicates and return an adjusted segment list on the output.
     
    
     BACKGROUND_MESH Construct a background mesh for a (messy) texture mesh with
     cosntraint edges that are about to deform.
     
     Inputs:
       V  #V by 2 list of texture mesh vertices
       E  #E by 2 list of constraint edge indices into V
       flags  string of triangle flags should contain "-c" unless the
         some subset of segments are known to enclose all other
         points/segments.
     Outputs:
       WV  #WV by 2 list of background mesh vertices 
       WF  #WF by 2 list of background mesh triangle indices into WV
       WE  #WE by 2 list of constraint edge indices into WV (might be smaller
         than E because degenerate constraints have been removed)
       J  #V list of indices into WF/WE for each vertex in V
    
)igl_Qu8mg5v7";

npe_function(cdt)
npe_doc(ds_cdt)

npe_arg(v, dense_f64)
npe_arg(e, dense_f64)
npe_arg(flags, std::string &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 wv;
    dense_f32 wf;
    dense_f32 we;
    dense_f32 j;
    igl::    triangle::cdt(v, e, flags, wv, wf, we, j);
    return std::make_tuple(    npe::move(wv),
    npe::move(wf),
    npe::move(we),
    npe::move(j));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 wv;
    dense_f64 wf;
    dense_f64 we;
    dense_f64 j;
    igl::    triangle::cdt(v, e, flags, wv, wf, we, j);
    return std::make_tuple(    npe::move(wv),     npe::move(wf),     npe::move(we),     npe::move(j));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


