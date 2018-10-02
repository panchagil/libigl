// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/Combo.h>

const char* ds_combo = R"igl_Qu8mg5v7(
See Combo for the documentation.
)igl_Qu8mg5v7";

npe_function(combo)
npe_doc(ds_combo)

npe_arg(label, char *)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    int * idx;
    int & values;
    ImGui::Combo(label, idx, values);
    return std::make_tuple(    npe::move(idx),
    npe::move(values));
} else if (dtype.type() == npe::type_f64) {
    int * idx;
    int & values;
    ImGui::Combo(label, idx, values);
    return std::make_tuple(    npe::move(idx),     npe::move(values));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/Combo.h>

const char* ds_combo = R"igl_Qu8mg5v7(
See Combo for the documentation.
)igl_Qu8mg5v7";

npe_function(combo)
npe_doc(ds_combo)

npe_arg(label, char *)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    int * idx;
    std::function<const char *(int)> getter;
    int items_count;
    ImGui::Combo(label, idx, getter, items_count);
    return std::make_tuple(    npe::move(idx),
    npe::move(getter),
    npe::move(items_count));
} else if (dtype.type() == npe::type_f64) {
    int * idx;
    std::function<const char *(int)> getter;
    int items_count;
    ImGui::Combo(label, idx, getter, items_count);
    return std::make_tuple(    npe::move(idx),     npe::move(getter),     npe::move(items_count));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/ListBox.h>

const char* ds_list_box = R"igl_Qu8mg5v7(
See ListBox for the documentation.
)igl_Qu8mg5v7";

npe_function(list_box)
npe_doc(ds_list_box)

npe_arg(label, char *)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    int * idx;
    int & values;
    ImGui::ListBox(label, idx, values);
    return std::make_tuple(    npe::move(idx),
    npe::move(values));
} else if (dtype.type() == npe::type_f64) {
    int * idx;
    int & values;
    ImGui::ListBox(label, idx, values);
    return std::make_tuple(    npe::move(idx),     npe::move(values));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/InputText.h>

const char* ds_input_text = R"igl_Qu8mg5v7(
See InputText for the documentation.
)igl_Qu8mg5v7";

npe_function(input_text)
npe_doc(ds_input_text)

npe_arg(label, char *)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    std::string & str;
    int flags;
    int callback;
    void * user_data;
    ImGui::InputText(label, str, flags, callback, user_data);
    return std::make_tuple(    npe::move(str),
    npe::move(flags),
    npe::move(callback),
    npe::move(user_data));
} else if (dtype.type() == npe::type_f64) {
    std::string & str;
    int flags;
    int callback;
    void * user_data;
    ImGui::InputText(label, str, flags, callback, user_data);
    return std::make_tuple(    npe::move(str),     npe::move(flags),     npe::move(callback),     npe::move(user_data));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


