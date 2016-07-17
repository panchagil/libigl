//
// Created by Francisca Gil Ureta on 7/1/16.
//

#ifndef IGL_TRACE_STREAMLINES_H
#define IGL_TRACE_STREAMLINES_H

#include "igl_inline.h"

#include <Eigen/Core>
#include <vector>

namespace igl
{
    // Determine whether two line segments A,B intersect
    // A: p + t*r :  t \in [0,1]
    // B: q + u*s :  u \in [0,1]
    // Inputs:
    //   p  3-vector origin of segment A
    //   r  3-vector direction of segment A
    //   q  3-vector origin of segment B
    //   s  3-vector direction of segment B
    //  eps precision
    // Outputs:
    //   t  scalar point of intersection along segment A, t \in [0,1]
    //   u  scalar point of intersection along segment B, u \in [0,1]
    // Returns true if intersection
    template<typename DerivedSource, typename DerivedDir>
    IGL_INLINE bool segments_intersect(
            const Eigen::PlainObjectBase<DerivedSource> &p,
            const Eigen::PlainObjectBase<DerivedDir> &r,
            const Eigen::PlainObjectBase<DerivedSource> &q,
            const Eigen::PlainObjectBase<DerivedDir> &s,
            double & t,
            double & u,
            double eps = 1e-6
    );

    // Given a mesh and a vector set field (sol3D) consisting of unordered n-vector sets defined
    // on the faces of the mesh, the function computes a new field with ordered N-vector sets defined
    // on the tangent plane of the faces, and a order-preserving matching between adjacent faces.
    // Inputs:
    //   V          #V by 3 list of mesh vertex coordinates
    //   F          #F by 3 list of mesh faces
    //   sol3D      #F by 3n list of the 3D coordinates of the per-face vectors
    //                    (stacked horizontally for each triangle)
    //   treat_as_symmetric
    //              if true, adds n symmetry directions to the field (N = 2n). Else N = n
    // Outputs:
    //   field      #F by 3N list of the 3D coordinates of the per-face vectors
    //                    (stacked horizontally for each triangle)
    //   match_ab   #E by N matrix, describing for each edge the matching a->b, where a
    //                    and b are the faces adjacent to the edge (i.e. vector #i of
    //                    the vector set in a is matched to vector #mab[i] in b)
    //   match_ba   #E by N matrix, describing for each edge the matching b->a, where a
    //                    and b are the faces adjacent to the edge (i.e. vector #mba[i] of
    //                    the vector set in a is matched to vector #i in b)
    template<typename DerivedV, typename DerivedF, typename DerivedS, typename DerivedM>
    IGL_INLINE void trace_polyvector_field_sort(
            const Eigen::PlainObjectBase<DerivedV>& V,
            const Eigen::PlainObjectBase<DerivedF>& F,
            const Eigen::PlainObjectBase<DerivedS>& sol3D,
            const bool treat_as_symmetric,
            Eigen::PlainObjectBase <DerivedS>& field,
            Eigen::PlainObjectBase <DerivedM> &match_ab,
            Eigen::PlainObjectBase <DerivedM> &match_ba

    );
    // Given a mesh the function computes a set of #S seeds for tracing,
    // state of sample point = {start_point, end_point, face_direction}
    // Inputs:
    //   V             #V by 3 list of mesh vertex coordinates
    //   F             #F by 3 list of mesh faces
    //   degree        d, number of copies of each seed
    // Outputs:
    //   samples       #S by 1 list of face indices
    //   start_point   #d*S by 3 starting points (stacked vertically for each degree)
    //   end_point     #d*S by 3 end points      (stacked vertically for each degree)
    //   face          #S by d face indices      (stacked horizontally for each degree)
    //   direction     #S by d direction indices
    IGL_INLINE void trace_seeds(
            const Eigen::MatrixXd& V,
            const Eigen::MatrixXi& F,
            const int d,
            Eigen::VectorXi& samples,
            Eigen::MatrixXd& start_point,
            Eigen::MatrixXd& end_point,
            Eigen::MatrixXi& face,
            Eigen::MatrixXi& direction
    );

    // Given a mesh, a vector field and a set of tracing points with
    // status = {start_point, end_point, face, direction},
    // the function computes the next status of the points.
    // Inputs:
    //   V          #V by 3 list of mesh vertex coordinates
    //   F          #F by 3 list of mesh faces
    //   TT         #F by #3 adjacent matrix, the element i,j is the id of
    //                    the triangle adjacent to the j edge of triangle i
    //   F2E        #Fx3, Stores the Triangle-Edge relation
    //   E2F        #Ex2, Stores the Edge-Triangle relation
    //   sol3D      #F by 3N list of the 3D coordinates of the per-face vectors
    //                    (stacked horizontally for each triangle)
    //   match_ab   #E by N matrix, describing for each edge the matching a->b, where a
    //                    and b are the faces adjacent to the edge (i.e. vector #i of
    //                    the vector set in a is matched to vector #mab[i] in b)
    //   match_ba   #E by N matrix, describing for each edge the matching b->a, where a
    //                    and b are the faces adjacent to the edge (i.e. vector #mba[i] of
    //                    the vector set in a is matched to vector #i in b)
    // Input/Outputs:
    //   start_point   #d*S by 3 starting points (stacked vertically for each degree)
    //   end_point     #d*S by 3 end points      (stacked vertically for each degree)
    //   face          #S by d face indices      (stacked horizontally for each degree)
    //   direction     #S by d direction indices
    template<typename DerivedV, typename DerivedF, typename DerivedS, typename DerivedM>
    IGL_INLINE void trace_streamlines(
            const Eigen::PlainObjectBase<DerivedV>& V,
            const Eigen::PlainObjectBase<DerivedF>& F,
            const Eigen::MatrixXi TT,
            const Eigen::MatrixXi& F2E,
            const Eigen::MatrixXi& E2F,
            const Eigen::PlainObjectBase<DerivedS>& sol3D,
            const Eigen::PlainObjectBase<DerivedM>& match_ab,
            const Eigen::PlainObjectBase<DerivedM>& match_ba,
            Eigen::MatrixXd& start_point,
            Eigen::MatrixXd& end_point,
            Eigen::MatrixXi& face,
            Eigen::MatrixXi& direction
    );



}

#ifndef IGL_STATIC_LIBRARY
#  include "trace_streamlines.cpp"
#endif

#endif