project('base64', 'cpp',
  version : '0.1',
  default_options : [
    'warning_level=3',
    'cpp_std=c++17',
    'cpp_args=-Wall -Wextra -Wpedantic -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wformat=2 -Wimport -Winvalid-pch -Wlogical-op -Wmissing-declarations -Wmissing-field-initializers -Wmissing-format-attribute -Wmissing-include-dirs -Wmissing-noreturn -Wpacked -Wpointer-arith -Wredundant-decls -Wstack-protector -Wstrict-null-sentinel -Wswitch-enum -Wundef -Wwrite-strings'
])

executable('tests',
           'tests.cpp',
           dependencies : [ dependency('doctest') ],
           install : false)

executable('gen',
           'gen.cpp',
           install : false)
