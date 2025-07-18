// Zadanie 💻
// Utwórz wektor v1 z liczbami od 1 do 1000
// Oblicz sumę tych liczb
// Utwórz wektor v2 z 1000 elementów powtarzających się w następującej
// sekwencji: -1, 0, 1, 0, -1, 0, 1, 0, ...
// Oblicz iloczyn skalarny wektorów v1
// i v2
// Oblicz sumę tych liczb z v1, które są na pozycjach dodatnich jedynek z
// wektora v2

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
int main() {
  std::vector<int> v1(1000);
  std::iota(v1.begin(), v1.end(), 1);
  std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, "; "));
  std::cout << '\n';
  std::cout << '\n';
  std::cout << std::reduce(v1.begin(), v1.end());
  std::cout << '\n';
  std::cout << '\n';

  std::vector<int> v2(1000);
  std::generate(v2.begin(), v2.end(), [i = 0, goingDistance = -1]() mutable {
    if (goingDistance == 1 && i == 1) {
      goingDistance = -1;
    } else if (goingDistance == -1 && i == -1) {
      goingDistance = 1;
    }
    i += goingDistance;
    return i;
  });
  std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, "; "));
  std::cout << '\n';
  std::cout << '\n';

  std::cout << std::inner_product(v1.begin(), v1.end(), v2.begin(), 0);
  std::cout << '\n';
  std::cout << '\n';

  std::cout << std::inner_product(v1.begin(), v1.end(), v2.begin(), 0,
                                  std::plus<int>(), [](auto i1, auto i2) {
                                    if (i2 == 1) {
                                      return i1;
                                    } else {
                                      return 0;
                                    }
                                  });
  std::cout << '\n';
  std::cout << '\n';
}