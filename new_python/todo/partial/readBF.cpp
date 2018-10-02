// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/readBF.h>

const char* ds_read_bf = R"igl_Qu8mg5v7(

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

 Read a bones forest from a file, returns a list of bone roots
   Input:
     file_name  path to .bf bones tree file
   Output:
     WI  #B list of unique weight indices
     P  #B list of parent indices into B, -1 for roots
     O  #B by 3 list of tip offset vectors from parent (or position for roots)
   Returns true on success, false on errors
)igl_Qu8mg5v7";

npe_function(read_bf)
npe_doc(ds_read_bf)

npe_arg(filename, std::string &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 wi;
    dense_f32 p;
    dense_f32 o;
    igl::readBF(filename, wi, p, o);
    return std::make_tuple(    npe::move(wi),
    npe::move(p),
    npe::move(o));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 wi;
    dense_f64 p;
    dense_f64 o;
    igl::readBF(filename, wi, p, o);
    return std::make_tuple(    npe::move(wi),     npe::move(p),     npe::move(o));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/readBF.h>

const char* ds_read_bf = R"igl_Qu8mg5v7(

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

 Read bone forest into pure bone-skeleton format, expects only bones (no
   point handles), and that a root in the .bf <---> no weight attachment.
  
   Input:
     file_name  path to .bf bones tree file
   Output:
     WI  #B list of unique weight indices
     P  #B list of parent indices into B, -1 for roots
     O  #B by 3 list of tip offset vectors from parent (or position for roots)
     C  #C by 3 list of absolute joint locations
     BE  #BE by 3 list of bone indices into C, in order of weight index
     P  #BE list of parent bone indices into BE, -1 means root bone
   Returns true on success, false on errors
     
   See also: readTGF, bone_parents, forward_kinematics
)igl_Qu8mg5v7";

npe_function(read_bf)
npe_doc(ds_read_bf)

npe_arg(filename, std::string &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 wi;
    dense_f32 bf_p;
    dense_f32 o;
    dense_f32 c;
    dense_f32 be;
    dense_f32 p;
    igl::readBF(filename, wi, bf_p, o, c, be, p);
    return std::make_tuple(    npe::move(wi),
    npe::move(bf_p),
    npe::move(o),
    npe::move(c),
    npe::move(be),
    npe::move(p));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 wi;
    dense_f64 bf_p;
    dense_f64 o;
    dense_f64 c;
    dense_f64 be;
    dense_f64 p;
    igl::readBF(filename, wi, bf_p, o, c, be, p);
    return std::make_tuple(    npe::move(wi),     npe::move(bf_p),     npe::move(o),     npe::move(c),     npe::move(be),     npe::move(p));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


