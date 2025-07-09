
// Znajdź dokumentację std:deque na cppreference.com
// Stwórz nowy plik i napisz funkcję main()
// Stwórz pusty deque
// Dodaj do niego pięć dowolnych wartości
// Wyświetl deque
// Usuń drugi i czwarty element
// Dodaj na początek i koniec wartość 30
// Wyświetl deque
// Dodaj na czwartej pozycji liczbę 20
// Wyświetl deque

#include <deque>
#include <iostream>
int main() {
  std::deque<int> deque;
  deque = {1,2,3,4,5};
  for (auto it : deque) {
    std::cout<<it<<", ";
  }
  std::cout<<'\n';
  deque.erase(deque.begin()+1);
  deque.erase(deque.begin()+2);
  deque.insert(deque.begin(),30);
  deque.insert(deque.end(),30);
  for (auto it : deque) {
    std::cout<<it<<", ";
  }
  std::cout<<'\n';
  deque.insert(deque.begin()+3,20);
  for (auto it : deque) {
    std::cout<<it<<", ";
  }
  std::cout<<'\n';
}