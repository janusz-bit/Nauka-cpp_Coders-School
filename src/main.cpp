// Zadanie 💻

//     Utwórz std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
//     Usuń wszystkie duplikaty z v
//     Wypisz wszystkie elementy, używając std::copy i std::ostream_iterator
//     Pomieszaj losowo wszystkie elementy
//     Wypisz je raz jeszcze

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

void printVector(const std::vector<int> &v) {
  std::ranges::for_each(v, [](auto i) { std::cout << i << "; "; });
  std::cout << '\n';
}

int main() {
  std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
  printVector(v);
  std::ranges::sort(v);
  auto it = std::unique(v.begin(),v.end());
  v.erase(it,v.end());
  
  std::copy(v.begin(),v.end(),std::ostream_iterator<int>(std::cout,"; "));

}