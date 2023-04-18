#include <levenshtein.h>

#include <iostream>
#include <iterator>
#include <sstream>

int main(int argc, char const *argv[]) {
  std::string input = argv[1];
  std::stringstream ss(argv[2]);
  std::istream_iterator<std::string> begin(ss);
  std::vector<std::string> options(begin, {});
  std::string expected = argv[3];

  std::string result = levenshtein::suggest(input, options);

  return !(result == expected);
}
