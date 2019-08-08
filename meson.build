project('rand48_r', 'c',
  version : '0.2',
  default_options : ['warning_level=3'])

shlib = both_libraries('rand48_r', ['rand48_r.c'],
  install : true,
  soversion : 0,
)

rand48_r_dep = declare_dependency(
  include_directories: include_directories('.'),
  link_with : shlib)

install_headers('rand48_r.h')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name : 'rand48_r',
  filebase : 'rand48_r',
  description : 'drand48_r(3) implementation',
  subdirs : 'rand48_r',
  libraries : shlib,
  version : meson.project_version(),
)
