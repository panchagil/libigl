import sys, os
import numpy as np

# Add the igl library to the modules search path
sys.path.insert(0, os.getcwd() + "/../")
import pyigl as igl
from shared import TUTORIAL_SHARED_PATH, check_dependencies

dependencies = ["viewer"]
check_dependencies(dependencies)

# Input mesh
V = igl.eigen.MatrixXd()
F = igl.eigen.MatrixXi()

# Face normals
FN = igl.eigen.MatrixXd()

# Topology
E = igl.eigen.MatrixXi()
E2F = igl.eigen.MatrixXi()
F2E = igl.eigen.MatrixXi()
TT = igl.eigen.MatrixXi()

# Constrained faces id
# Eigen::VectorXi b;

# // Constrained faces representative vector
# Eigen::MatrixXd bc;

# Vector field
field = igl.eigen.MatrixXd()
treat_as_symmetric = True

# vector field matchings for adjacent faces
match_ab = igl.eigen.MatrixXi()
match_ba = igl.eigen.MatrixXi()

start_point = igl.eigen.MatrixXd()
end_point = igl.eigen.MatrixXd()
current_face = igl.eigen.MatrixXi()
current_direction = igl.eigen.MatrixXi()

points = [start_point, end_point]
# animation params
anim_t = 0
anim_t_dir = 1


def representative_to_nrosy(V, F, R, N, Y):
    B1 = igl.eigen.MatrixXd()
    B2 = igl.eigen.MatrixXd()
    B3 = igl.eigen.MatrixXd()

    igl.local_basis(V, F, B1, B2, B3)

    Y.resize(F.rows(), 3 * N)
    for i in range(0, F.rows()):
        x = R.row(i) * B1.row(i).transpose()
        y = R.row(i) * B2.row(i).transpose()
        angle = np.arctan2(y, x)

        for j in range(0, N):
            anglej = angle + np.pi * float(j) / float(N)
            xj = float(np.cos(anglej))
            yj = float(np.sin(anglej))
            Y.setBlock(i, j * 3, 1, 3, xj * B1.row(i) + yj * B2.row(i))


def pre_draw(viewer):
    if not viewer.core.is_animating:
        return False

    global anim_t
    global start_point
    global end_point

    igl.trace_streamlines(V, F, TT, F2E, E2F, field, match_ab, match_ba, points[0], points[1], current_face,
                          current_direction)

    value = (anim_t % 100) / 100.0

    if value > 0.5:
        value = 1 - value
    value /= 0.5
    r, g, b = igl.parula(value)
    viewer.data.add_edges(points[0], points[1], igl.eigen.MatrixXd([[r, g, b]]))

    anim_t += anim_t_dir
    aux = points[0]
    points[0] = points[1]
    points[1] = aux

    return False


def key_down(viewer, key, modifier):
    if key == ord(' '):
        viewer.core.is_animating = not viewer.core.is_animating
        return True

    return False


# Load a mesh in OFF format
igl.readOFF(TUTORIAL_SHARED_PATH + "bumpy.off", V, F)
igl.per_face_normals(V, F, FN)
igl.edge_topology(V, F, E, F2E, E2F)
igl.triangle_triangle_adjacency(F, TT)

# Create Vector Field
# #F x 3N matrix where N is the number of vectors per face
temp_field = igl.eigen.MatrixXd()
b = igl.eigen.MatrixXi([[0]])
bc = igl.eigen.MatrixXd([[1, 1, 1]])
S = igl.eigen.MatrixXd()  # unused

degree = 3
igl.comiso.nrosy(V, F, b, bc, igl.eigen.MatrixXi(), igl.eigen.MatrixXd(), igl.eigen.MatrixXd(), 1, 0.5, temp_field, S)

temp_field2 = igl.eigen.MatrixXd()
representative_to_nrosy(V, F, temp_field, degree, temp_field2)

igl.trace_polyvector_field_sort(V, F, temp_field2, treat_as_symmetric, field, match_ab, match_ba)
degree = int(field.cols() / 3)

samples = igl.eigen.MatrixXi()
igl.trace_seeds(V, F, degree, samples, start_point, end_point, current_face, current_direction)

viewer = igl.viewer.Viewer()
viewer.data.set_mesh(V, F)
viewer.callback_pre_draw = pre_draw
viewer.callback_key_down = key_down

viewer.core.show_lines = False

viewer.core.is_animating = False
viewer.core.animation_max_fps = 30.0

# Paint mesh grayish
C = igl.eigen.MatrixXd()
C.setConstant(viewer.data.V.rows(), 3, .9)
viewer.data.set_colors(C)
#
# Draw vector field
VN = igl.eigen.MatrixXd()
igl.per_vertex_normals(V, F, VN)
#
BC = igl.eigen.MatrixXd()
BC_sample = igl.eigen.MatrixXd()
igl.barycenter(V, F, BC)
igl.slice(BC, samples, 1, BC_sample)
for i in range(0, degree):
    v = igl.eigen.MatrixXd()
    v1 = field.block(0, i * 3, F.rows(), 3)
    igl.slice(v1, samples, 1, v)
    viewer.data.add_edges(BC_sample,
                          BC_sample + 0.059 * v,
                          igl.eigen.MatrixXd([[(i / degree), (i / degree), (i / degree)]]))

print("Press [space] to toggle animation")
viewer.launch()
