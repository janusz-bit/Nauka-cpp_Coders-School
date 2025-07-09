
// Znajdź dokumentację std::forward_list na cppreference.com
// Skorzystaj z kodu z zadania std::list
// Stwórz listę jednokierunkową zawierającą elementy od 0 do 6
// Wyświetl listę
// Usuń trzeci element z listy
// Dodaj na początek i na koniec listy wartość 10
// Wyświetl listę
// Dodaj na czwartej pozycji liczbę 20
// Wyświetl listę

#include <forward_list>
#include <iostream>
#include <iterator>
int main() {
  std::forward_list<int> flist{0, 1, 2, 3, 4, 5, 6};
  for (auto it : flist) {
    std::cout << it<<", ";
  }
  std::cout<<'\n';
  auto it = flist.begin();
  std::advance(it,1);
  flist.erase_after(it);
  flist.push_front(10);

  it = flist.begin();
  auto itNext = it;
  ++itNext;
  while (itNext != flist.end()) {
    ++it;
    ++itNext;
  }
  flist.emplace_after(it, 10);
  
  
  for (auto it : flist) {
    std::cout << it<<", ";
  }
  std::cout<<"\n";

  it = flist.begin();
  std::advance(it,2);
  flist.insert_after(it,20);
  for (auto it : flist) {
    std::cout << it<<", ";
  }
  
}
