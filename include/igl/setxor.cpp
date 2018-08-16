#include "setxor.h"
#include "setdiff.h"
#include "setunion.h"
#include "slice.h"

template <
  typename DerivedA,
  typename DerivedB,
  typename DerivedC,
  typename DerivedIA,
  typename DerivedIB>
IGL_INLINE void igl::setxor(
  const Eigen::DenseBase<DerivedA> & A,
  const Eigen::DenseBase<DerivedB> & B,
  Eigen::MatrixBase<DerivedC> & C,
  Eigen::MatrixBase<DerivedIA> & IA,
  Eigen::MatrixBase<DerivedIB> & IB)
{
  DerivedC AB,BA;
  DerivedIA IAB,IBA;
  setdiff(A,B,AB,IAB);
  setdiff(B,A,BA,IBA);
  setunion(AB,BA,C,IA,IB);
  slice(IAB,DerivedIA(IA),IA);
  slice(IBA,DerivedIB(IB),IB);
}

#ifdef IGL_STATIC_LIBRARY
// Explicit template instantiation
// generated by autoexplicit.sh
template void igl::setxor<Eigen::Matrix<int, -1, 2, 0, -1, 2>, Eigen::Matrix<int, -1, 2, 0, -1, 2>, Eigen::Matrix<int, -1, 1, 0, -1, 1>, Eigen::Matrix<int, -1, 1, 0, -1, 1>, Eigen::Matrix<int, -1, 1, 0, -1, 1> >(Eigen::DenseBase<Eigen::Matrix<int, -1, 2, 0, -1, 2> > const&, Eigen::DenseBase<Eigen::Matrix<int, -1, 2, 0, -1, 2> > const&, Eigen::MatrixBase<Eigen::Matrix<int, -1, 1, 0, -1, 1> >&, Eigen::MatrixBase<Eigen::Matrix<int, -1, 1, 0, -1, 1> >&, Eigen::MatrixBase<Eigen::Matrix<int, -1, 1, 0, -1, 1> >&);
#endif
