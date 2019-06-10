#ifndef HYPER_SODIUM_ENCODEDECODE_H
#define HYPER_SODIUM_ENCODEDECODE_H

#include <string>
#include <sodium.h>

///
/// namespace Hyper
///
namespace Hyper {

  ///
  /// namespace Sodium
  ///
  namespace Sodium {

    ///
    /// namespace Base64
    ///
    namespace Base64 {

      ///
      /// function encode(const std::string& str)
      /// comment base64 encodes a string.
      /// param str the string to be encoded.
      ///
      /// return std::string
      /// comment provides the base64 encoded string.
      ///
      std::string encode(const std::string& str);

      ///
      /// function decode(const std::string& str)
      /// comment decodes a base64 encoded string.
      /// param str the string to be decoded.
      ///
      /// return std::string
      /// comment provides the decoded string.
      ///
      std::string decode(const std::string& str);
    }

    ///
    /// namespace Hex
    ///
    namespace Hex {

      ///
      /// function encode(const std::string& str)
      /// comment encodes a binary string to hex.
      /// param str a const reference to the source string.
      ///
      /// return std::string
      /// comment a new hex encoded string.
      ///
      std::string encode(const std::string& str);

      ///
      /// function decode(const std::string& str)
      /// comment decodes a hex string to bin
      /// param str a const reference to the source string.
      ///
      /// return std::string
      /// comment a new bin encoded string.
      ///
      std::string decode(const std::string& str);
    }

  } // namespace Sodium
} // namespace Hyper

#endif
