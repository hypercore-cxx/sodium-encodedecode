# SYNOPSIS

Libsodium encoding and decoding functions.


# USAGE

This module is designed to work with the [`datcxx`][0] build tool. To add this
module to your project us the following command...

```bash
build add datcxx/sodium-encodedecode
```


# TEST

```bash
build test
```


# EXAMPLE

```c++
#include "deps/datcxx/sodium-encodedecode/index.hxx"
```

### BASE64

```c++
auto encoded = Hyper::Sodium::Base64::encode("Hello, world!");
// encoded == "SGVsbG8sIHdvcmxkIQ=="

auto decoded = Hyper::Sodium::Base64::decode(encoded);
// decoded == "Hello, world!"
```

### HEX

```c++
auto encoded = Hyper::Sodium::Hex::encode("Hello, world!");
// encoded == "48656c6c6f2c20776f726c6421"

auto decoded = Hyper::Sodium::Hex::decode(encoded);
// decoded == "Hello, world!"
```


[0]:https://github.com/datcxx/build
