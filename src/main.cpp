// Zadanie #2

//     Znajdź dokumentację std::array<T, N> na cppreference.com
//     Stwórz nowy plik i napisz funkcję main()
//     Stwórz std::array przechowujący wartości całkowitoliczbowe o rozmiarze 10
//     Wypełnij ją wartościami 5
//     Do czwartego elementu przypisz wartość 3
//     Stwórz inną tablicę o tym samym rozmiarze
//     Podmień tablice
//     Wypisz obie tablice, każdą w osobnej linii

#include <array>
#include <iostream>
int main()
{
  std::array<int, 10> array;
  array.fill(5);
  array[3]=3;
  std::array<int, 10> array2;
  array.swap(array);
  for (auto i : array) {
    std::cout<<i<<", ";
  
  }
  std::cout<<"\n";
  for (auto i : array2) {
    std::cout<<i<<", ";
  
  }
  std::cout<<"\n";
}
