#include <cmath>
#include <Eigen/Dense>
#include <Eigen/Sparse>


template <typename T>
using EigenSparse = Eigen::SparseMatrix<T, Eigen::ColMajor>;

template <typename T>
using EigenDense = Eigen::Matrix<T, -1, -1, Eigen::ColMajor, -1, -1>;

typedef Eigen::Matrix<std::float_t, -1, -1, Eigen::ColMajor, -1, -1> EigenDenseF32;
typedef Eigen::Matrix<std::double_t, -1, -1, Eigen::ColMajor, -1, -1> EigenDenseF64;
typedef Eigen::Matrix<std::int32_t, -1, -1, Eigen::ColMajor, -1, -1> EigenDenseI32;
typedef Eigen::Matrix<std::int64_t, -1, -1, Eigen::ColMajor, -1, -1> EigenDenseI64;

typedef Eigen::SparseMatrix<std::float_t, Eigen::ColMajor> EigenSparseF32;
typedef Eigen::SparseMatrix<std::double_t, Eigen::ColMajor> EigenSparseF64;
typedef Eigen::SparseMatrix<std::int32_t, Eigen::ColMajor> EigenSparseI32;
typedef Eigen::SparseMatrix<std::int64_t, Eigen::ColMajor> EigenSparseI64;
