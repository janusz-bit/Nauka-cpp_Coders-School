
// Utwórz std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
// Policz, ile jest elementów większych lub równych 5
// Sprawdź, czy istnieje element mniejszy od 1
// Sprawdź, czy wszystkie elementy są większe od 1

#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
  std::cout<<std::ranges::count_if(v, [](int i) {
    if (i >= 5) {
      return true;
    }
    return false;
  })<<"\n";
  std::cout<<std::ranges::any_of(v,[](int i){
    return i<1;
  })<<'\n';
  std::cout<<std::ranges::all_of(v,[](int i){return i>1;})<<'\n';
}