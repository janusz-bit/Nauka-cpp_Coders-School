
// Utwórz std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9}; (ten sam
// co ostatnio) Znajdź wszystkie elementy większe od 6 i wypisz je Znajdź
// wszystkie elementy równe 2, 4, 6 lub 8 i wypisz je Przeszukaj wektor v w
// poszukiwaniu zakresów {6, 6} i {7, 7} Użyj std::adjacent_find na wektorze v

#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};

  auto begin = v.begin();
  while (1) {
    begin = std::find_if(begin, v.end(), [](int i) {
      if (i > 6) {
        return true;
      }
      return false;
    });
    if (begin == v.end()) {
      break;
    } else {
      std::cout << *begin << '\n';
      begin++;
    }
  }

  std::cout << "---\n";

  std::vector<int> Find = {2, 4, 6, 8};

  auto begin1 = v.begin();
  while (1) {
    begin1 = std::find_first_of(begin1, v.end(), Find.begin(), Find.end());
    if (begin1 == v.end()) {
      break;
    }
    std::cout << *begin1 << '\n';
    begin1++;
  }
  std::cout << "---\n";

  std::vector<std::vector<int>> search = {{6, 6}, {7, 7}};

  for (auto it : search) {

    auto begin2 = v.begin();
    while (1) {
      begin2 = std::search(begin2, v.end(), it.begin(), it.end());
      if (begin2 == v.end()) {
        break;
      }
      std::cout << begin2 - v.begin() << '\n';
      begin2++;
    }
  }

  return 0;
}