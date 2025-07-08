// Zadanie #2

//     Otwórz dokumentację wektora na cppreference.com
//     Stwórz nowy plik i napisz funkcję main()
//     Stwórz pusty wektor
//     Wypisz rozmiar i pojemność wektora
//     Zmień rozmiar wektora na 10 i wypełnij go wartościami 5
//     Wypisz rozmiar i pojemność wektora
//     Zarezerwuj pamięć na 20 elementów
//     Wypisz rozmiar i pojemność wektora
//     Zredukuj pojemność wektora metodą shrink_to_fit()
//     Wypisz rozmiar i pojemność wektora

#include <iostream>
#include <vector>

void readVec(std::vector<int> &vec) {
  std::cout << "vec.size(), vec.capacity(): " << vec.size() << ", "
            << vec.capacity() << '\n';
}

int main() {
  std::vector<int> vec;
  readVec(vec);
  vec.resize(10, 5);
  readVec(vec);
  vec.reserve(20);
  readVec(vec);
  vec.shrink_to_fit();
  readVec(vec);

}