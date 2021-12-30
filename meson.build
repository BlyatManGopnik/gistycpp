project('gistycpp', 'c', default_options: ['cpp_std=c++17'])
cpr_proj = subproject('cpr')
cpr_dep = cpr_proj.get_variable('cpr_dep')
cpr_inc = cpr_proj.get_variable('incdir')

nlohmann_json_dep = dependency(
'nlohmann_json',
fallback: ['nlohmann_json', 'nlohmann_json_dep']
)

gistydeps = [nlohmann_json_dep, cpr_dep]

sources = files('gisty.cpp', 'headless.cpp', 'post.cpp', 'sleep.cpp')

executable('gistycpp', sources: sources ,
dependencies: gistydeps, install: true,
install_dir: get_option('datadir') / 'gistycpp',
install_rpath: './')
