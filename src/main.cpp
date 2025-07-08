// Znajdź dokumentację std::list<T> na cppreference.com
// Stwórz nowy plik i napisz funkcję main()
// Stwórz listę zawierającą elementy od 0 do 5
// Wyświetl listę
// Usuń trzeci element z listy
// Dodaj na początek i na koniec listy wartość 10
// Wyświetl listę
// Dodaj na czwartej pozycji liczbę 20
// Przepisz listę do std::array<T, N>
// Wyświetl <std::array<T, N>

#include <array>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <list>

int main() {
  std::list<int> list{0, 1, 2, 3, 4, 5};

  for (auto it : list) {
    std::cout << it<<", ";
  }
  std::cout<<"\n";

  auto it = list.begin();
  std::advance(it,2);
  std::cout<<*(list.erase(it))<<"\n";
  list.emplace_front(10);
  list.emplace_back(10);
  it = list.begin();
  std::advance(it,4);
  list.insert(it,20);
  std::array<int, 8> array;


  auto itt = list.begin();
  for (size_t i{}; i<list.size(); ++i) {
    array.at(i)=*itt;
    std::advance(itt,1);
  }

  for (auto it : array) {
    std::cout << it<<", ";
  }
  std::cout<<"\n";
}
