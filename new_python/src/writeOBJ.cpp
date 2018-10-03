#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>

#include <igl/writeOBJ.h>

//const char* ds_write_obj_0 = R"igl_Qu8mg5v7(
//Write a mesh in an ascii obj file.

//Parameters
//----------
//filename : path to outputfile
//v : array of vertex positions #v by 3
//tc : array of texture coordinats #tc by 2
//n : array of corner normals #n by 3
//f : #f list of face indices into vertex positions
//ftc : #f list of face indices into vertex texture coordinates
//fn : #f list of face indices into vertex normals

//Returns
//-------
//ret : bool if output was successful

//See also
//--------
//read_obj

//Notes
//-----
//None

//Examples
//--------
//>>> success = write_obj(filename, v, tc, cn, f, ftc, fn)
//)igl_Qu8mg5v7";

//npe_function(write_obj)
//npe_doc(ds_write_obj_0)

//npe_arg(filename, std::string)
//npe_arg(v, dense_f64, dense_f32)
//npe_arg(tc, dense_f64, dense_f32)
//npe_arg(cn, dense_f64, dense_f32)
//npe_arg(f, dense_i32)
//npe_arg(ftc, dense_i32)
//npe_arg(fn, dense_i32)

//npe_begin_code()
//using namespace std;

//bool ret = igl::writeOBJ(filename, v, f, cn, fn, tc, ftc);

//return ret;

//npe_end_code()



const char* ds_write_obj_1 = R"igl_Qu8mg5v7(
Write a mesh in an ascii obj file.

Parameters
----------
filename : path to outputfile
v : array of vertex positions #v by 3
f : #f list of face indices into vertex positions

Returns
-------
ret : bool if output was successful

See also
--------
read_obj

Notes
-----
None

Examples
--------
# Mesh in (v, f)
>>> success = write_obj(v, f)
)igl_Qu8mg5v7";

npe_function(write_obj)
npe_doc(ds_write_obj_1)

npe_arg(filename, std::string)
npe_arg(v, dense_f64, dense_f32)
npe_arg(f, dense_i32)


npe_begin_code()

return igl::writeOBJ(filename, v, f);

npe_end_code()


