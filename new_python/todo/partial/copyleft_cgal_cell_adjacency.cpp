// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/cell_adjacency.h>

const char* ds_cell_adjacency = R"igl_Qu8mg5v7(

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
         per_patch_cells  #P by 2 list of cell labels on each side of each
                          patch.  Cell labels are assumed to be continuous
                          from 0 to #C.
         num_cells        number of cells.
      
       Outputs:
         adjacency_list  #C array of list of adjcent cell information.  If
                         cell i and cell j are adjacent via patch x, where i
                         is on the positive side of x, and j is on the
                         negative side.  Then,
                         adjacency_list[i] will contain the entry {j, false, x}
                         and
                         adjacency_list[j] will contain the entry {i, true, x}
)igl_Qu8mg5v7";

npe_function(cell_adjacency)
npe_doc(ds_cell_adjacency)

npe_arg(per_patch_cells, dense_f64)
npe_arg(num_cells, size_t)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::vector<std::set<std::tuple<typename DerivedC::Scalar, bool, size_t> > > & adjacency_list;
    igl::    copyleft::    cgal::cell_adjacency(per_patch_cells, num_cells, adjacency_list);
    return npe::move(adjacency_list);
} else if (dtype.type() == npe::type_f64) {
    std::vector<std::set<std::tuple<typename DerivedC::Scalar, bool, size_t> > > & adjacency_list;
    igl::    copyleft::    cgal::cell_adjacency(per_patch_cells, num_cells, adjacency_list);
    return npe::move(adjacency_list);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


