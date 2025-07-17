// Zadanie 💻

// struct Point { int x, y; }

//     Utwórz std::deque<Point> d = {{1, 3}, {0, 0}, {1, 2}, {2, 4}, {4, 1}, {0,
//     2}, {2, 2}}; Utwórz funkcję do wypisywania zawartości kontenera d Napisz
//     2 komparatory:
//         pointXCompare, który porównuje tylko wartości x ze struktury Point
//         pointYCompare, który porównuje tylko wartości y ze struktury Point
//     Sprawdź czy d jest posortowane względem pointXCompare oraz pointYCompare
//     Użyj stable_sort do posortowania d względem wartości x
//     Użyj sort do posortowania d względem wartości y

#include <algorithm>
#include <deque>
#include <iostream>

struct Point {
  int x, y;
};

void printDeque(std::deque<Point> input) {
  std::for_each(input.begin(), input.end(), [](auto i) {
    std::cout << "{" << i.x << "; " << i.y << "}\n";
  });
}

int main() {
  std::deque<Point> d = {{1, 3}, {0, 0}, {1, 2}, {2, 4},
                         {4, 1}, {0, 2}, {2, 2}};
  printDeque(d);
  auto pointXCompare = [](Point input1, Point input2) {
    return input1.x < input2.x;
  };
  auto pointYCompare = [](Point input1, Point input2) {
    return input1.y < input2.y;
  };

  if (std::is_sorted(d.begin(), d.end(), pointXCompare)) {
    std::cout << "Posortowane \"pointXCompare\"\n";
  } else {
    std::cout << "Nie posortowane \"pointXCompare\"\n";
  }

  if (std::is_sorted(d.begin(), d.end(), pointYCompare)) {
    std::cout << "Posortowane \"pointYCompare\"\n";
  } else {
    std::cout << "Nie posortowane \"pointYCompare\"\n";
  }

  std::stable_sort(d.begin(),d.end(),pointXCompare);
  printDeque(d);
  if (std::is_sorted(d.begin(), d.end(), pointXCompare)) {
    std::cout << "Posortowane \"pointXCompare\"\n";
  } else {
    std::cout << "Nie posortowane \"pointXCompare\"\n";
  }

  std::sort(d.begin(),d.end(),pointYCompare);
  printDeque(d);
  if (std::is_sorted(d.begin(), d.end(), pointYCompare)) {
    std::cout << "Posortowane \"pointYCompare\"\n";
  } else {
    std::cout << "Nie posortowane \"pointYCompare\"\n";
  }

}