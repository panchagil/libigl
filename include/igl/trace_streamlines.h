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
    template<typename DerivedSource, typename DerivedDir>
    IGL_INLINE bool segments_intersect(
            const Eigen::PlainObjectBase<DerivedSource> &p,
            const Eigen::PlainObjectBase<DerivedDir> &r,
            const Eigen::PlainObjectBase<DerivedSource> &q,
            const Eigen::PlainObjectBase<DerivedDir> &s,
            double & a_t,
            double & a_u,
            double eps = 1e-6
    );

    template<typename DerivedS, typename DerivedV, typename DerivedF, typename DerivedM>
    IGL_INLINE void trace_streamlines(
            const Eigen::PlainObjectBase<DerivedV>& V,
            const Eigen::PlainObjectBase<DerivedF>& F,
            const Eigen::MatrixXi TT,
            const Eigen::MatrixXi& F2E,
            const Eigen::MatrixXi& E2F,
            const Eigen::PlainObjectBase<DerivedS>& sol3D,
            const Eigen::PlainObjectBase<DerivedM>& match_ab,
            const Eigen::PlainObjectBase<DerivedM>& match_ba,
            std::vector <Eigen::MatrixXd>& start_point,
            std::vector <Eigen::MatrixXd>& end_point,
            std::vector <Eigen::VectorXi>& face,
            Eigen::MatrixXi& direction
    );

    IGL_INLINE void initialize_seeds(
            const Eigen::MatrixXd& V,
            const Eigen::MatrixXi& F,
            const Eigen::MatrixXd& temp_field,
            const bool treat_as_symmetric,
            Eigen::MatrixXd& field,
            Eigen::VectorXi& samples,
            std::vector <Eigen::MatrixXd>& start_point,
            std::vector <Eigen::MatrixXd>& end_point,
            std::vector <Eigen::VectorXi>& face,
            Eigen::MatrixXi& direction
    );

}

#ifndef IGL_STATIC_LIBRARY
#  include "trace_streamlines.cpp"
#endif

#endif