#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/cocoa_key_to_anttweakbar_key.h>

const char* ds_cocoa_key_to_anttweakbar_key = R"igl_Qu8mg5v7(

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

 Convert an unsigned char (like that from Cocoa apps) to AntTweakBar key
     code.
     See also: TranslateKey() in TwMgr.cpp in AntTweakBar source
     Inputs:
       key  unsigned char key from keyboard
     Returns int of new key code 
)igl_Qu8mg5v7";

npe_function(cocoa_key_to_anttweakbar_key)
npe_doc(ds_cocoa_key_to_anttweakbar_key)

npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    int key;
    igl::    anttweakbar::cocoa_key_to_anttweakbar_key(key);
    return npe::move(key);
} else if (dtype.type() == npe::type_f64) {
    int key;
    igl::    anttweakbar::cocoa_key_to_anttweakbar_key(key);
    return npe::move(key);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


