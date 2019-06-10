#include <sodium.h>
#include <cstring>
#include <vector>
#include <iostream>

#include "index.hxx"

namespace Hyper {
  namespace Sodium {
    namespace Base64 {
      auto variant = sodium_base64_VARIANT_URLSAFE;

      std::string encode (const std::string& str) {
        auto mlen = sodium_base64_ENCODED_LEN(str.size(), variant);

        std::string res;
        res.resize(mlen);

        auto size = const_cast<char*>(res.data());
        auto data = (const unsigned char*) str.data();

        sodium_bin2base64(size, mlen, data, str.size(), variant);
        res.resize(res.size() - 1);
        return res;
      }

      std::string decode (const std::string& str) {
        size_t bin_len;

        std::string res;
        res.resize(str.size());

        auto size = str.size();
        auto data = res.data();

        sodium_base642bin((uint8_t*) data, size, str.data(), size, 0, &bin_len, 0, variant);

        res.resize(bin_len);
        return res;
      }
    }

    namespace Hex {
      std::string encode (const std::string& str) {
        const size_t len = str.size();

        std::string out;
        out.resize(len * 2);

        sodium_bin2hex(&out[0], len * 2 + 1, (unsigned char*) &str[0], len);
        out.resize(out.size());
        return out;
      }

      std::string decode (const std::string& str) {
        const size_t len = str.length();
        const size_t hexLen = len;
        const size_t binLen = len * 0.5;

        std::vector<uint8_t> out(binLen);

        sodium_hex2bin(&out[0], binLen, &str[0], hexLen, nullptr, nullptr, nullptr);

        std::string s(out.begin(), out.end());
        return s;
      }
    }

  } // namespace Sodium
} // namespace Hyper
