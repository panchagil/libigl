//m.def("trace_streamlines", []
//(
//  const Eigen::MatrixXd& V,
//  const Eigen::MatrixXi& F,
//  const Eigen::MatrixXi& TT,
//  const Eigen::MatrixXi& F2E,
//  const Eigen::MatrixXi& E2F,
//  const Eigen::MatrixXd& sold3d,
//  const Eigen::MatrixXi& match_ab,
//  const Eigen::MatrixXi& match_ba,
//  std::vector <Eigen::MatrixXd>& start_point,
//  std::vector <Eigen::MatrixXd>& end_point,
//  std::vector <Eigen::VectorXi>& face,
//  Eigen::MatrixXi& direction
//)
//{
//  return igl::trace_streamlines(V, F,TT, F2E, E2F, sold3d, match_ab, match_ba, start_point, end_point, face, direction);
//}, __doc_igl_barycenter,
//py::arg("V"), py::arg("F"), py::arg("TT"), py::arg("F2E"), py::arg("E2F"),
//py::arg("sold3d"), py::arg("match_ab"), py::arg("match_ba"),py::arg("start_point"),py::arg("end_point"),
//py::arg("face"),py::arg("direction"));
m.def("trace_polyvector_field_sort", []
(
  const Eigen::MatrixXd& V,
  const Eigen::MatrixXi& F,
  const Eigen::MatrixXd& temp_field,
  const bool treat_as_symmetric,
  Eigen::MatrixXd& field,
  Eigen::MatrixXi& match_ab,
  Eigen::MatrixXi& match_ba
)
{
  return igl::trace_polyvector_field_sort(V, F, temp_field, treat_as_symmetric, field, match_ab, match_ba);
},__doc_igl_trace_polyvector_field_sort,
py::arg("V"), py::arg("F"), py::arg("temp_field"), py::arg("treat_as_symmetric"),
py::arg("field"), py::arg("match_ab"), py::arg("match_ba"));

m.def("trace_seeds", []
(
  const Eigen::MatrixXd& V,
  const Eigen::MatrixXi& F,
  const int degree,
  Eigen::VectorXi& samples,
  std::vector <Eigen::MatrixXd>& start_point,
  std::vector <Eigen::MatrixXd>& end_point,
  std::vector <Eigen::VectorXi>& face,
  Eigen::MatrixXi& direction
)
{
  return igl::trace_seeds(V, F, degree, samples, start_point, end_point, face, direction);
},__doc_igl_trace_seeds,
py::arg("V"), py::arg("F"), py::arg("degree"), py::arg("samples"), py::arg("start_point"),
py::arg("end_point"), py::arg("face"), py::arg("direction"));

m.def("trace_streamlines", []
(
const Eigen::MatrixXd& V,
const Eigen::MatrixXi& F,
const Eigen::MatrixXi TT,
const Eigen::MatrixXi& F2E,
const Eigen::MatrixXi& E2F,
const Eigen::MatrixXd& field,
const Eigen::MatrixXi& match_ab,
const Eigen::MatrixXi& match_ba,
std::vector <Eigen::MatrixXd>& start_point,
std::vector <Eigen::MatrixXd>& end_point,
std::vector <Eigen::VectorXi>& face,
Eigen::MatrixXi& direction

)
{
return igl::trace_streamlines(V, F, TT, F2E, E2F, field, match_ab, match_ba, start_point, end_point, face, direction);
},__doc_igl_trace_streamlines,
py::arg("V"), py::arg("F"), py::arg("TT"), py::arg("F2E"), py::arg("E2F"),
py::arg("field"), py::arg("match_ab"), py::arg("match_ba"),
py::arg("start_point"), py::arg("end_point"), py::arg("face"), py::arg("direction"));