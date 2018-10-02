#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/massmatrix.h>

const char* ds_massmatrix = R"igl_Qu8mg5v7(
Constructs the mass (area) matrix for a given mesh (V,F).

Parameters
----------
v : #v by dim list of mesh vertex positions
f : #f by simplex_size list of mesh faces (must be triangles)
type : one of the following types:
       -igl.MASSMATRIX_TYPE_BARYCENTRIC  barycentric
       -igl.MASSMATRIX_TYPE_VORONOI voronoi-hybrid (default)
       -igl.MASSMATRIX_TYPE_FULL full (not implemented)

Returns
-------
m : #v by #v mass matrix

See also
--------
adjacency_matrix

Notes
-----
None

Examples
--------

)igl_Qu8mg5v7";

npe_function(massmatrix)
npe_doc(ds_massmatrix)

npe_arg(v, dense_f64) // TODO adding dense_f32 gives an error here, see https://stackoverflow.com/questions/23946658/error-mixing-types-with-eigen-matrices
npe_arg(f, dense_i32)
npe_default_arg(type, int, 1)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;

Sparse_f64 m;
igl::massmatrix(v, f, igl::MassMatrixType(type), m);
return npe::move(m);

npe_end_code()


