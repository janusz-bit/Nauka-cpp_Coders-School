#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <iterator>
#include <ranges>
#include <set>

template <typename Container, typename Type>
void print(
    const Container &container, const int &newLine = 1,
    bool (*ptr)(Type i) = [](Type) { return true; }) {
  std::cout << '{';
  std::copy_if(
      container.begin(), container.end(),
      std::ostream_iterator<typename Container::value_type>(std::cout, "; "),
      ptr);
  std::cout << '}';
  if (newLine) {
    for (size_t i{}; i < newLine; ++i) {
      std::cout << '\n';
    }
  }
}

int main() {
  std::set<int, std::greater<int>> myMap;

  auto number = std::views::iota(-20, 21);
  for (auto it : number) {
    myMap.insert(it);
  }

  myMap.insert({-10, 0, 10, 100, -100});

  print<std::set<int, std::greater<int>>, int>(myMap);

  auto number2 = std::views::iota(0, 40);

  std::multiset<int> myMultiMap;
  for (auto it : number2) {
    myMultiMap.insert(it);
  }
  myMultiMap.insert({-10, 0, 10, 100, -100});

  print<std::multiset<int>, int>(myMultiMap);

  std::multiset<int> endContainer;

  for (auto it : myMap) {
    endContainer.insert(it);
  }

  for (auto it : myMultiMap) {
    endContainer.insert(it);
  }

  print<std::multiset<int>, int>(endContainer);

  print<std::multiset<int>, int>(endContainer, 1, [](auto i) {
    if (i == 0 || i == 50) {
      return true;
    }
    return false;
  });
}
