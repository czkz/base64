# Base64
Base64 encoding/decoding library for C++17.

- Fast
- Header-only
- No dependencies
- Public domain (0BSD)

# Installation
Copy `base64.h` into your project folder.

# Usage
`base64.h` has function declarations in the beginning of the file for quick reference.

## Encoding:
```cpp
string s1 = to_base64("Hello, World!");

string s2 = to_base64(buf, buf_len);
```

## Decoding:
```cpp
string s1 = from_base64("SGVsbG8sIFdvcmxkIQ==");

string s2 = from_base64(buf, buf_len);
```

## Decoding in-place:
```cpp
// With data in std::string:
string s3 = "SGVsbG8sIFdvcmxkIQ==";
from_base64_inplace(s3);

// With data in void*:
size_t len = from_base64_inplace(buf, buf_len);
```

## Note on input validation:

Validating base64 doesn't seem to be very useful, since data
from a trusted source doesn't need to be validated,
and data from an untrusted source
must be validated after decoding anyway.

For performance reasons `from_base64()` doesn't validate it's input
nor requires it to be validated beforehand - output data won't
make much sense, but it won't impact the stability of the program.

# Tests and benchmarks
Required dependencies: `benchmark`, `doctest`.
```bash
# Tests
meson setup build/
meson compile -C build/ tests
./build/tests

# Benchmarks
./bench.sh

# Code coverage
meson setup build_cov/ -Db_coverage=true
meson test -C build_cov/
ninja -C build_cov/ coverage
```
