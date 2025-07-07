#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

// Implement createMap. It should take a vector and list and
// return a map of merge them as keys from the vector and values from the list
std::map<int, std::string> createMap(std::vector<int> vec,
                                     std::list<std::string> list) {

  std::map<int, std::string> map;
  auto itList = list.begin();
  for (auto itVec : vec) {
    map[itVec] = *itList;
    ++itList;
  }
  return map;
}

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  std::list<std::string> list{"One", "Two", "Three", "Four", "Five"};
  auto map = createMap(vec, list);

  for (const auto &pair : map)
    std::cout << pair.first << " | " << pair.second << '\n';

  return 0;
}