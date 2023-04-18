#include "levenshtein.h"

#include <algorithm>
#include <string>

namespace levenshtein {
int distance(const std::string_view &a, const std::string_view &b) {
  if (b.size() == 0) {
    return a.size();
  }

  if (a.size() == 0) {
    return b.size();
  }

  if (a[0] == b[0]) {
    return distance(a.substr(1), b.substr(1));
  }

  return 1 + std::min({distance(a.substr(1), b), distance(a, b.substr(1)),
                       distance(a.substr(1), b.substr(1))});
}

std::string suggest(const std::string_view &input,
                    const std::vector<std::string> &options) {
  return *std::min_element(options.begin(), options.end(),
                           [&input](const auto &s1, const auto &s2) {
                             const auto d1 = std::abs(distance(input, s1));
                             const auto d2 = std::abs(distance(input, s2));

                             return d1 < d2;
                           });
}
} // namespace levenshtein