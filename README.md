# SYNOPSIS
Libsodium base64 functions.


# USAGE
This module is designed to work with the [`datcxx`][0] build tool. To add this
module to your project us the following command...

```bash
build add datcxx/sodium-base64
```


# TEST

```bash
build test
```


# EXAMPLE

```c++
#include "deps/datcxx/sodium-base64/index.hxx"

auto encoded = Hyper::Sodium::base64Encode("Hello, world!");
// encoded == "SGVsbG8sIHdvcmxkIQ=="

auto decoded = Hyper::Sodium::base64Decode(encoded);
// decoded == "Hello, world!"
```


[0]:https://github.com/datcxx/build
