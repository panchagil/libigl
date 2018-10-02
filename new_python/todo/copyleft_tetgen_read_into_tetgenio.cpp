// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/read_into_tetgenio.h>

const char* ds_read_into_tetgenio = R"igl_Qu8mg5v7(

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

 Read a mesh or point set into tetgenio (input object for calling
       tetgen).  Many file formats are already supported by tetgen:
         .off
         .ply
         .node
         .ply
         .medit
         .vtk
         etc.
       Notably it does not support .obj which is loaded by hand here (also
       demonstrating how to load points/faces programmatically)
      
       If the file extension is not recognized the filename is assumed to be
       the basename of a collection describe a tetmesh, (of which at least
       the .node file must exist):
         [filename].node
         [filename].ele
         [filename].face
         [filename].edge
         [filename].vol
      
       Inputs:
         path  path to file or basename to files
       Outputs:
         in  tetgenio input object
       Returns true on success, false on error
)igl_Qu8mg5v7";

npe_function(read_into_tetgenio)
npe_doc(ds_read_into_tetgenio)

npe_arg(path, std::string &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    int & in;
    igl::    copyleft::    tetgen::read_into_tetgenio(path, in);
    return npe::move(in);
} else if (dtype.type() == npe::type_f64) {
    int & in;
    igl::    copyleft::    tetgen::read_into_tetgenio(path, in);
    return npe::move(in);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


