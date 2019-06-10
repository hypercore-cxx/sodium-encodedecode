#include <iostream>
#include <sodium.h>

#include "../deps/heapwolf/cxx-tap/index.hxx"
#include "../index.hxx"

std::string getRandomString () {
  const char chars[] =
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";

  int stringLength = sizeof(chars) - 1;

  std::string str;

  const int r = rand() % stringLength + 1;

  for (int i = 0; i < r; i++) {
    str.push_back(chars[rand() % stringLength]);
  }

  return str;
}

int main() {
  TAP::Test t;

  t.test("sanity", [](auto t) {
    t->ok(true, "true is true");
    t->end();
  });

  t.test("init sodium", [](auto t) {
    if (sodium_init() < 0) {
      t->fail("coult not init sodium");
      t->end();
    }

    t->pass("initialized sodium");
    t->end();
  });

  t.test("base64 encode", [](auto t) {
    std::string str = "Hello, world!";

    auto expectedEncoded = std::string("SGVsbG8sIHdvcmxkIQ==");

    auto encoded = Hyper::Sodium::Base64::encode(str);
    t->equal(encoded, expectedEncoded, "encoded matches output");
    t->end();
  });

  t.test("base64 encode/decode random size/length", [](auto t) {
    auto str = getRandomString();
    auto encoded = Hyper::Sodium::Base64::encode(str);
    auto decoded = Hyper::Sodium::Base64::decode(encoded);

    t->equal(decoded, str, "base64 decoded expected");
    t->end();
  });

  t.test("hex encode/decode", [](auto t) {
    std::string v("Hello, world");
    std::string expected("48656c6c6f2c20776f726c64");

    auto encoded = Hyper::Sodium::Hex::encode(v);
    t->equal(encoded, expected, "hex encoded matched");

    auto decoded = Hyper::Sodium::Hex::decode(encoded);

    t->equal(decoded, v);
    t->end();
  });

  t.test("hex encode/decode random size/length", [](auto t) {
    auto str = getRandomString();

    auto encoded = Hyper::Sodium::Hex::encode(str);
    auto decoded = Hyper::Sodium::Hex::decode(encoded);
    t->equal(decoded, str, "hex decoded matched");
    t->end();
  });
}
