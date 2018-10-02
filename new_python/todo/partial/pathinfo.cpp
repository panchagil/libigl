// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/pathinfo.h>

const char* ds_pathinfo = R"igl_Qu8mg5v7(

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

 Function like PHP's pathinfo
    returns information about path
   Input:
    path  string containing input path
   Outputs:
    dirname  string containing dirname (see dirname.h)
    basename  string containing basename (see basename.h)
    extension  string containing extension (characters after last '.')
    filename  string containing filename (characters of basename before last
      '.')
  
  
   Examples:
  
   input                     | dirname        basename       ext    filename
   "/"                       | "/"            ""             ""     ""
   ""                      | "/"            ""             ""     ""
   "/foo"                    | "/"            "foo"          ""     "foo"
   "/foo/"                   | "/"            "foo"          ""     "foo"
   "/foo"                  | "/"            "foo"          ""     "foo"
   "/foo/./"                 | "/foo"         "."            ""     ""
   "/foo/bar"                | "/foo"         "bar"          ""     "bar"
   "/foo/bar."               | "/foo"         "bar."         ""     "bar"
   "/foo/bar.txt"            | "/foo"         "bar.txt"      "txt"  "bar"
   "/foo/bar.txt.zip"        | "/foo"         "bar.txt.zip"  "zip"  "bar.txt"
   "/foo/bar.dir/"           | "/foo"         "bar.dir"      "dir"  "bar"
   "/foo/bar.dir/file"       | "/foo/bar.dir" "file"         ""     "file"
   "/foo/bar.dir/file.txt"   | "/foo/bar.dir" "file.txt"     "txt"  "file"
    See also: basename, dirname
)igl_Qu8mg5v7";

npe_function(pathinfo)
npe_doc(ds_pathinfo)

npe_arg(path, std::string &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::string & dirname;
    std::string & basename;
    std::string & extension;
    std::string & filename;
    igl::pathinfo(path, dirname, basename, extension, filename);
    return std::make_tuple(    npe::move(dirname),
    npe::move(basename),
    npe::move(extension),
    npe::move(filename));
} else if (dtype.type() == npe::type_f64) {
    std::string & dirname;
    std::string & basename;
    std::string & extension;
    std::string & filename;
    igl::pathinfo(path, dirname, basename, extension, filename);
    return std::make_tuple(    npe::move(dirname),     npe::move(basename),     npe::move(extension),     npe::move(filename));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


