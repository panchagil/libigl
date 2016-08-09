//
// Created by Francisca Gil Ureta on 7/1/16.
//

#ifndef IGL_STREAMLINES_H
#define IGL_STREAMLINES_H

#include "igl_inline.h"

#include <Eigen/Core>
#include <vector>

namespace igl
{
    struct StreamlineData
    {
        Eigen::MatrixXi TT;
        Eigen::MatrixXi E;
        Eigen::MatrixXi F2E;
        Eigen::MatrixXi E2F;
        Eigen::MatrixXd field;
        Eigen::MatrixXi match_ab;
        Eigen::MatrixXi match_ba;
        int nsample;
        int degree;
    };

    struct StreamlineState
    {
        Eigen::MatrixXd start_point;
        Eigen::MatrixXd end_point;
        Eigen::MatrixXi current_face;
        Eigen::MatrixXi current_direction;

    };


    IGL_INLINE void streamlines_init(
            const Eigen::MatrixXd V,
            const Eigen::MatrixXi F,
            const Eigen::MatrixXd &temp_field,
            const bool treat_as_symmetric,
            StreamlineData &data,
            StreamlineState &state,
            double percentage = 0.3

    );

    IGL_INLINE void streamlines_next(
            const Eigen::MatrixXd V,
            const Eigen::MatrixXi F,
            const StreamlineData & data,
            StreamlineState & state

    );
}


#ifndef IGL_STATIC_LIBRARY
#  include "streamlines.cpp"
#endif

#endif