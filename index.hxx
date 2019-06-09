#ifndef HYPER_SODIUM_H
#define HYPER_SODIUM_H

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
    /// function base64Encode(const std::string& str)
    /// comment base64 encodes a string.
    /// param str the string to be encoded.
    ///
    /// return std::string
    /// comment provides the base64 encoded string.
    ///
    std::string base64Encode(const std::string& str);

    ///
    /// function base64Decode(const std::string& str)
    /// comment decodes a base64 encoded string.
    /// param str the string to be decoded.
    ///
    /// return std::string
    /// comment provides the decoded string.
    ///
    std::string base64Decode(const std::string& str);

  } // namespace Sodium
} // namespace Hyper

#endif
