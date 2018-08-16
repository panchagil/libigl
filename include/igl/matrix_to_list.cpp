// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2013 Alec Jacobson <alecjacobson@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#include "matrix_to_list.h"

#include <Eigen/Dense>

template <typename DerivedM>
IGL_INLINE void igl::matrix_to_list(
  const Eigen::DenseBase<DerivedM> & M,
  std::vector<std::vector<typename DerivedM::Scalar > > & V)
{
  using namespace std;
  V.resize(M.rows(),vector<typename DerivedM::Scalar >(M.cols()));
  // loop over rows
  for(int i = 0;i<M.rows();i++)
  {
    // loop over cols
    for(int j = 0;j<M.cols();j++)
    {
      V[i][j] = M(i,j);
    }
  }
}

template <typename DerivedM>
IGL_INLINE void igl::matrix_to_list(
  const Eigen::DenseBase<DerivedM> & M,
  std::vector<typename DerivedM::Scalar > & V)
{
  using namespace std;
  V.resize(M.size());
  // loop over cols then rows
  for(int j = 0;j<M.cols();j++)
  {
    for(int i = 0;i<M.rows();i++)
    {
      V[i+j*M.rows()] = M(i,j);
    }
  }
}

template <typename DerivedM>
IGL_INLINE std::vector<typename DerivedM::Scalar > igl::matrix_to_list(
    const Eigen::DenseBase<DerivedM> & M)
{
  std::vector<typename DerivedM::Scalar> V;
  matrix_to_list(M,V);
  return V;
}

#ifdef IGL_STATIC_LIBRARY
// Explicit template instantiation
// generated by autoexplicit.sh
template void igl::matrix_to_list<Eigen::Block<Eigen::Matrix<float, -1, -1, 0, -1, -1>, -1, 1, true> >(Eigen::DenseBase<Eigen::Block<Eigen::Matrix<float, -1, -1, 0, -1, -1>, -1, 1, true> > const&, std::vector<Eigen::Block<Eigen::Matrix<float, -1, -1, 0, -1, -1>, -1, 1, true>::Scalar, std::allocator<Eigen::Block<Eigen::Matrix<float, -1, -1, 0, -1, -1>, -1, 1, true>::Scalar> >&);
// generated by autoexplicit.sh
template void igl::matrix_to_list<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1>, -1, 1, true> >(Eigen::DenseBase<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1>, -1, 1, true> > const&, std::vector<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1>, -1, 1, true>::Scalar, std::allocator<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1>, -1, 1, true>::Scalar> >&);
// generated by autoexplicit.sh
template void igl::matrix_to_list<Eigen::Matrix<int, -1, 2, 0, -1, 2> >(Eigen::DenseBase<Eigen::Matrix<int, -1, 2, 0, -1, 2> > const&, std::vector<Eigen::Matrix<int, -1, 2, 0, -1, 2>::Scalar, std::allocator<Eigen::Matrix<int, -1, 2, 0, -1, 2>::Scalar> >&);
// generated by autoexplicit.sh
template std::vector<Eigen::Matrix<double, -1, 1, 0, -1, 1>::Scalar, std::allocator<Eigen::Matrix<double, -1, 1, 0, -1, 1>::Scalar> > igl::matrix_to_list<Eigen::Matrix<double, -1, 1, 0, -1, 1> >(Eigen::DenseBase<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const&);
// generated by autoexplicit.sh
template std::vector<Eigen::Matrix<int, -1, 1, 0, -1, 1>::Scalar, std::allocator<Eigen::Matrix<int, -1, 1, 0, -1, 1>::Scalar> > igl::matrix_to_list<Eigen::Matrix<int, -1, 1, 0, -1, 1> >(Eigen::DenseBase<Eigen::Matrix<int, -1, 1, 0, -1, 1> > const&);
//template void igl::matrix_to_list<Eigen::MatrixBase<Eigen::Matrix<double, -1, -1, 0, -1, -1> >, double>(Eigen::MatrixBase<Eigen::Matrix<double, -1, -1, 0, -1, -1> > const&, std::vector<std::vector<double, std::allocator<double> >, std::allocator<std::vector<double, std::allocator<double> > > >&);
//template void igl::matrix_to_list<Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1> >, int>(Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1> > const&, std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > >&);
template void igl::matrix_to_list<Eigen::Matrix<double, -1, -1, 0, -1, -1> >(Eigen::DenseBase<Eigen::Matrix<double, -1, -1, 0, -1, -1> > const&, std::vector<std::vector<Eigen::Matrix<double, -1, -1, 0, -1, -1>::Scalar, std::allocator<Eigen::Matrix<double, -1, -1, 0, -1, -1>::Scalar> >, std::allocator<std::vector<Eigen::Matrix<double, -1, -1, 0, -1, -1>::Scalar, std::allocator<Eigen::Matrix<double, -1, -1, 0, -1, -1>::Scalar> > > >&);
template void igl::matrix_to_list<Eigen::Matrix<int, -1, -1, 0, -1, -1> >(Eigen::DenseBase<Eigen::Matrix<int, -1, -1, 0, -1, -1> > const&, std::vector<std::vector<Eigen::Matrix<int, -1, -1, 0, -1, -1>::Scalar, std::allocator<Eigen::Matrix<int, -1, -1, 0, -1, -1>::Scalar> >, std::allocator<std::vector<Eigen::Matrix<int, -1, -1, 0, -1, -1>::Scalar, std::allocator<Eigen::Matrix<int, -1, -1, 0, -1, -1>::Scalar> > > >&);
template void igl::matrix_to_list<Eigen::Matrix<double, -1, 1, 0, -1, 1> >(Eigen::DenseBase<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const&, std::vector<Eigen::Matrix<double, -1, 1, 0, -1, 1>::Scalar, std::allocator<Eigen::Matrix<double, -1, 1, 0, -1, 1>::Scalar> >&);
template void igl::matrix_to_list<Eigen::Matrix<int, -1, -1, 0, -1, -1> >(Eigen::DenseBase<Eigen::Matrix<int, -1, -1, 0, -1, -1> > const&, std::vector<Eigen::Matrix<int, -1, -1, 0, -1, -1>::Scalar, std::allocator<Eigen::Matrix<int, -1, -1, 0, -1, -1>::Scalar> >&);
template void igl::matrix_to_list<Eigen::Matrix<int, -1, 1, 0, -1, 1> >(Eigen::DenseBase<Eigen::Matrix<int, -1, 1, 0, -1, 1> > const&, std::vector<Eigen::Matrix<int, -1, 1, 0, -1, 1>::Scalar, std::allocator<Eigen::Matrix<int, -1, 1, 0, -1, 1>::Scalar> >&);
template void igl::matrix_to_list<Eigen::Matrix<int, -1, 1, 0, -1, 1> >(Eigen::DenseBase<Eigen::Matrix<int, -1, 1, 0, -1, 1> > const&, std::vector<std::vector<Eigen::Matrix<int, -1, 1, 0, -1, 1>::Scalar, std::allocator<Eigen::Matrix<int, -1, 1, 0, -1, 1>::Scalar> >, std::allocator<std::vector<Eigen::Matrix<int, -1, 1, 0, -1, 1>::Scalar, std::allocator<Eigen::Matrix<int, -1, 1, 0, -1, 1>::Scalar> > > >&);
template void igl::matrix_to_list<Eigen::Matrix<double, -1, -1, 0, -1, -1> >(Eigen::DenseBase<Eigen::Matrix<double, -1, -1, 0, -1, -1> > const&, std::vector<Eigen::Matrix<double, -1, -1, 0, -1, -1>::Scalar, std::allocator<Eigen::Matrix<double, -1, -1, 0, -1, -1>::Scalar> >&);
template void igl::matrix_to_list<Eigen::Matrix<int, 1, -1, 1, 1, -1> >(Eigen::DenseBase<Eigen::Matrix<int, 1, -1, 1, 1, -1> > const&, std::vector<Eigen::Matrix<int, 1, -1, 1, 1, -1>::Scalar, std::allocator<Eigen::Matrix<int, 1, -1, 1, 1, -1>::Scalar> >&);
#endif
