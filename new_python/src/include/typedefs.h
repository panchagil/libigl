#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>


typedef Eigen::Matrix<std::double_t, Eigen::Dynamic, Eigen::Dynamic> Dense_f64;
typedef Eigen::Matrix<std::float_t, Eigen::Dynamic, Eigen::Dynamic> Dense_f32;
typedef Eigen::Matrix<std::int32_t, Eigen::Dynamic, Eigen::Dynamic> Dense_i32;
typedef Eigen::SparseMatrix<std::int32_t, Eigen::ColMajor, std::int32_t> Sparse_i32;
typedef Eigen::SparseMatrix<std::double_t, Eigen::ColMajor, std::int32_t> Sparse_f64;
typedef Eigen::SparseMatrix<std::float_t, Eigen::ColMajor, std::int32_t> Sparse_f32;



