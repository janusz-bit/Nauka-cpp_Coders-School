// Zadanie #1

//     Otwórz dokumentację wektora na cppreference.com
//     Stwórz nowy plik i napisz funkcję main()
//     Stwórz wektor o wartościach {1, 2, 4, 5, 6}
//     Usuń pierwszą wartość
//     dodaj wartość 5 na końcu wektora
//     dodaj wartość 12 na początku wektora korzystając z metody emplace()
//     Wypisz rozmiar wektora i maksymalny możliwy rozmiar
//     Wypisz zawartość wektora
//     Wyczyść wektor
//     Wypisz rozmiar wektora

#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 4, 5, 6};
  vec.erase(vec.begin());
  vec.push_back(5);
  vec.emplace(vec.begin(), 12);
  std::cout << "vec.size(): " << vec.size() << '\n';
  std::cout << "vec.max_size(): " << vec.max_size() << '\n';
  for (auto i : vec) {
    std::cout<<i<<", ";
  }
  std::cout<<'\n';

  vec.clear();
  std::cout << "vec.size(): " << vec.size() << '\n';
}