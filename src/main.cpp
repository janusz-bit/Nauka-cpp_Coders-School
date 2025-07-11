// Napisz funkcję `compressGrayscale()`.
// Powinna ona przyjąć jeden argument typu `std::array<std::array<uint8_t, 240>,
// 160>` określający rozkład odcieni szarości na obrazku 2D (który w dalszej
// części nazywać będziemy bitmapą) i zwróci `std::vector<std::pair<uint8_t,
// uint8_t>>` zawierający skompresowaną bitmapę.

// Kompresja powinna przebiegać w następujący sposób:

// * Bitmapę rysujemy od górnego lewego rogu przechodząc w prawo, następnie
// poziom niżej.
// * Jeżeli obok siebie występuje ten sam kolor więcej niż 1 raz, funkcja
// powinna wrzucić do  `std::vector` wartość tego koloru (liczba z przedziału 0
// – 255) jako pierwszy element pary oraz ilość jego powtórzeń jako drugi
// element pary.
// * Jeżeli obok siebie występują różne odcienie to funkcja powinna wypełnić
// `std::vector` wartością odcienia oraz liczbą wystąpień równą 1 (w tym
// przypadku pogarszamy optymalizację, gdyż przechowujemy 2x tyle danych, jednak
// najczęściej te same kolory są położone obok siebie).

#include <array>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

std::vector<std::pair<uint8_t, uint8_t>>
compressGrayscale(std::array<std::array<uint8_t, 10>, 3> input) {
  std::vector<std::pair<uint8_t, uint8_t>> output;

  uint8_t counter{};
  uint8_t color = input[0][0];

  for (const auto &row : input) {
    for (const auto &i : row) {
      if (color == i) {
        ++counter;

      } else {
        output.push_back(std::make_pair(color, counter));
        counter = 1;
        color = i;
      }
    }
  }
  output.push_back(std::make_pair(color, counter));

  return output;
}

int main() {
  std::array<std::array<uint8_t, 10>, 3> input = {
      {{{0, 0, 0, 1, 1, 2, 3, 0, 0, 0}},
       {{0, 0, 4, 4, 4, 1, 1, 1, 1, 1}},
       {{2, 2, 2, 2, 2, 1, 2, 2, 2, 2}}

      }};

  auto output = compressGrayscale(input);

  std::cout<<"{";
  bool isFirst{1};
  for (auto pair : output) {
    if (isFirst) {
      isFirst = 0;
    } else {
      std::cout << ", ";
    }
    std::cout<<"{"<<static_cast<int>(pair.first)<<", "<<static_cast<int>(pair.second)<<"}";
  }
  std::cout<<"}";
}