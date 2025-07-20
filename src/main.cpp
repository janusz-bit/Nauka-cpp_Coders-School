// Zadanie
// struct Point {
//   int x;
//   int y;
// }
// Struktura Point ma reprezentować punkt o współrzędnych x i y na mapie. Mamy
// też dane 4 miast:

// Wrocław (x = 17, y = 51)
// Moskwa (x = 37, y = 55)
// Nowy Jork (x = -74, y = 40)
// Sydney (x = 151, y = -33)
// Część A - łatwiejsza
// Stwórz std::map<std::string, Point>, która będzie przechowywać powyższe
// miejsca Sprawdź czy w mapie jest element, który znajduje się w promieniu 70
// od środka układu współrzędnych (0, 0) Pobierz i wypisz współrzędne Sydney
// Zadanie
// struct Point {
//   int x;
//   int y;
// }
// Struktura Point ma reprezentować punkt o współrzędnych x i y na mapie. Mamy
// też dane 4 miast:

// Wrocław (x = 17, y = 51)
// Moskwa (x = 37, y = 55)
// Nowy Jork (x = -74, y = 40)
// Sydney (x = 151, y = -33)
// Część B - trudniejsza
// Skopiuj te dane do mapy std::map<Point, std::string>
// Sprawdź czy w odwróconej mapie jest element, który znajduje się w promieniu
// 70 od środka układu współrzędnych (0, 0) Pobierz i wypisz współrzędne Sydney

#include <cmath>
#include <iostream>
#include <map>
#include <ostream>
#include <string>

struct Point;

float PointDistance(Point point1);

struct Point {
  int x;
  int y;

  bool operator<(const Point &input) const {
    return PointDistance(*this) < PointDistance(input);
  }
};

std::ostream& operator<<(std::ostream& stream, const Point& point)
{
  stream<<"{"<<point.x<<"; "<<point.y<<"}";
  return stream;
}

float PointDistance(Point point1) {
  const int x = point1.x;
  const int y = point1.y;
  return std::sqrt(x * x + y * y);
}

int main() {

  std::map<std::string, Point> myMap = {{"Wrocław", {17, 51}},
                                        {"Moskwa", {37, 55}},
                                        {"Nowy Jork", {-74, 40}},
                                        {"Sydney", {151, -33}}};
  for (auto myPoint : myMap) {
    if (((myPoint.second.x * myPoint.second.x) +
         (myPoint.second.y * myPoint.second.y)) < (70 * 70)) {
      std::cout << myPoint.first << '\n';
    }
  }

  std::map<Point, std::string> myMap2({{{17, 51}, "Wrocław"},
                                       {{37, 55}, "Moskwa"},
                                       {{-74, 40}, "Nowy Jork"},
                                       {{151, -33}, "Sydney"}});


  for (auto it = myMap2.begin(); PointDistance(it->first) < 70 && it != myMap2.end(); ++it) {
    std::cout<<it->second<<": "<<it->first<<'\n';
  }

}
