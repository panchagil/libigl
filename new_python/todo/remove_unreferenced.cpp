// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/remove_unreferenced.h>

const char* ds_remove_unreferenced = R"igl_Qu8mg5v7(

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

 Remove unreferenced vertices from V, updating F accordingly
  
   Input:
     V  #V by dim list of mesh vertex positions
     F  #F by ss list of simplices (Values of -1 are quitely skipped)
   Outputs:
     NV  #NV by dim list of mesh vertex positions
     NF  #NF by ss list of simplices
     IM  #V by 1 list of indices such that: NF = IM(F) and NT = IM(T)
        and V(find(IM<=size(NV,1)),:) = NV
  
)igl_Qu8mg5v7";

npe_function(remove_unreferenced)
npe_doc(ds_remove_unreferenced)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 nv;
    dense_f32 nf;
    dense_f32 i;
    igl::remove_unreferenced(v, f, nv, nf, i);
    return std::make_tuple(    npe::move(nv),
    npe::move(nf),
    npe::move(i));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 nv;
    dense_f64 nf;
    dense_f64 i;
    igl::remove_unreferenced(v, f, nv, nf, i);
    return std::make_tuple(    npe::move(nv),     npe::move(nf),     npe::move(i));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/remove_unreferenced.h>

const char* ds_remove_unreferenced = R"igl_Qu8mg5v7(
See remove_unreferenced for the documentation.
)igl_Qu8mg5v7";

npe_function(remove_unreferenced)
npe_doc(ds_remove_unreferenced)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 nv;
    dense_f32 nf;
    dense_f32 i;
    dense_f32 j;
    igl::remove_unreferenced(v, f, nv, nf, i, j);
    return std::make_tuple(    npe::move(nv),
    npe::move(nf),
    npe::move(i),
    npe::move(j));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 nv;
    dense_f64 nf;
    dense_f64 i;
    dense_f64 j;
    igl::remove_unreferenced(v, f, nv, nf, i, j);
    return std::make_tuple(    npe::move(nv),     npe::move(nf),     npe::move(i),     npe::move(j));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/remove_unreferenced.h>

const char* ds_remove_unreferenced = R"igl_Qu8mg5v7(

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

 Inputs:
     n  number of vertices (possibly greater than F.maxCoeff()+1)
     F  #F by ss list of simplices
   Outputs:
     IM  #V by 1 list of indices such that: NF = IM(F) and NT = IM(T)
        and V(find(IM<=size(NV,1)),:) = NV
     J  #RV by 1 list, such that RV = V(J,:)
     
)igl_Qu8mg5v7";

npe_function(remove_unreferenced)
npe_doc(ds_remove_unreferenced)

npe_arg(n, size_t)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 i;
    dense_f32 j;
    igl::remove_unreferenced(n, f, i, j);
    return std::make_tuple(    npe::move(i),
    npe::move(j));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 i;
    dense_f64 j;
    igl::remove_unreferenced(n, f, i, j);
    return std::make_tuple(    npe::move(i),     npe::move(j));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


