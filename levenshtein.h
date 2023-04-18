#include <string_view>
#include <vector>

namespace levenshtein {
int distance(const std::string_view &a, const std::string_view &b);

std::string suggest(const std::string_view &input,
                    const std::vector<std::string> &options);
} // namespace levenshtein