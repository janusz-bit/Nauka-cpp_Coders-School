#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <iterator>
#include <ranges>
#include <set>

template <typename Container>
void print(const Container &container, int newLine = 1) {
  std::copy(
      container.begin(), container.end(),
      std::ostream_iterator<typename Container::value_type>(std::cout, "; "));
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

  print(myMap, 2);

  auto number2 = std::views::iota(0, 40);

  std::multiset<int> myMultiMap;
  for (auto it : number2) {
    myMultiMap.insert(it);
  }
  myMultiMap.insert({-10, 0, 10, 100, -100});

  print(myMultiMap, 2);

  std::multiset<int> endContainer;

  for (auto it : myMap) {
    endContainer.insert(it);
  }

  for (auto it : myMultiMap) {
    endContainer.insert(it);
  }

  print(endContainer,2);

  for (auto it : endContainer) {
    if (it == 0 || it ==50) {
      std::cout<<it<<"; ";
    }
  }
}
