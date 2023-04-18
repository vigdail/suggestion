#include <levenshtein.h>

#include <iostream>

int main(int argc, char const *argv[]) {
  std::string_view a = argv[1];
  std::string_view b = argv[2];
  const int expected = std::stoi(argv[3]);
  return !(levenshtein::distance(a, b) == expected);
}
