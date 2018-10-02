% for inc in includes:
#include ${inc}
% endfor
% for func in functions:
#include <igl/${func['orgname']}.h>

const char* ds_${func['name']} = R"igl_Qu8mg5v7(
${func['docstring']}
)igl_Qu8mg5v7";

npe_function(${func['name']})
npe_doc(ds_${func['name']})

% for p in func['in_parameters'][:]:
npe_arg(${p['name']}, ${p['type']})
% endfor
${func['dtype_def']}


npe_begin_code()
using namespace std;


% if func['dtype_def'] != "":
if (dtype.type() == npe::type_f32) {
    % for p in func['out_parameters'][:]:
    ${p['type'].replace("f64", "f32")} ${p['name']};
    % endfor
    % for n in func['namespaces']:
    ${n}::\
% endfor
${func['orgname']}(\
% for p in func['all_parameters'][:-1]:
${p['name']}, \
% endfor
${func['all_parameters'][-1]['name']});
    % if len(func['out_parameters']) > 1:
    return std::make_tuple(\
    % for p in func['out_parameters'][:-1]:
    npe::move(${p['name']}),
    % endfor
    npe::move(${func['out_parameters'][-1]['name']}));
    % elif len(func['out_parameters']) == 1:
    return npe::move(${func['out_parameters'][0]['name']});
    % else:
    return;
    % endif
} else if (dtype.type() == npe::type_f64) {
    % for p in func['out_parameters'][:]:
    ${p['type'].replace("f32", "f64")} ${p['name']};
    % endfor
    % for n in func['namespaces']:
    ${n}::\
% endfor
${func['orgname']}(\
% for p in func['all_parameters'][:-1]:
${p['name']}, \
% endfor
${func['all_parameters'][-1]['name']});
    % if len(func['out_parameters']) > 1:
    return std::make_tuple(\
    % for p in func['out_parameters'][:-1]:
    npe::move(${p['name']}), \
    % endfor
    npe::move(${func['out_parameters'][-1]['name']}));
    % elif len(func['out_parameters']) == 1:
    return npe::move(${func['out_parameters'][0]['name']});
    % else:
    return;
    % endif
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}
% else:
% for p in func['out_parameters'][:]:
${p['type']} ${p['name']};
% endfor

% for n in func['namespaces']:
${n}::\
% endfor
${func['orgname']}(\
% for p in func['all_parameters'][:-1]:
${p['name']}, \
% endfor
${func['all_parameters'][-1]['name']});

return
% endif

npe_end_code()
% endfor


