// ## Zadanie 1 - `remove-Vowels`

// Napisz funkcję `removeVowels()`, która przyjmie `std::vector<std::string>`
// oraz usunie wszystkie samogłoski z tych wyrażeń.

// * Input: `{"abcde", "aabbbccabc", "qwerty"}`
// * Output: `{"bcd", "bbccbc", "qwrt"}`

#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> &removeVowels(std::vector<std::string> &input) {
  constexpr std::array<char, 6> Vowels{
      'e', 'y', 'u', 'i', 'o', 'a',
  };
  for (auto &String : input) {

    for (auto itVowels = Vowels.begin(); itVowels != Vowels.end(); ++itVowels) {

      String.erase(std::remove(String.begin(), String.end(), *itVowels),
                   String.end());
    }
  }
  return input;
}

void print(const std::vector<std::string> &input) {
  std::cout << "{";
  bool isFirst = true;
  for (const auto &it : input) {
    if (isFirst) {
      isFirst = false;
    } else {
      std::cout << ", ";
    }
    std::cout << "\"" << it << "\"";
  }
  std::cout << "}\n";
}

int main() {
  std::vector<std::string> input{"abcde", "aabbbccabc", "qwerty"};
  print(input);
  removeVowels(input);
  print(input);
}