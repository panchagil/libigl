% for inc in includes:
#include ${inc}
% endfor

% for func in functions:
#include <igl/${func['name']}.h>


npe_function("${func['name']}")
% for p in func['parameters'][:]:
npe_arg("${p['name']}", "${p['type']}")
% endfor
npe_begin_code()
using namespace std;


% for n in func['namespaces']:
${n}::\
% endfor
${func['name']}(\
% for p in func['parameters'][:-1]:
${p['name']}, \
% endfor
${func['parameters'][-1]['name']});
return

npe_end_code()
% endfor


