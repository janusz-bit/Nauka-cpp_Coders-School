

// Utwórz poniższy wektor:

//  std::vector<std::pair<int, std::string>> v {
//      {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5,
//      "Five"}
//  };

// Utwórz wektor intów v2 i wypełnij go wszystkimi intami (pierwszymi elementami
// pary) z wektora v Utwórz wektor stringów v3 i wypełnij go konkatenacją string
// + dwukropek + int ze wszystkich par z wektora v Utwórz wektor charów v4 i
// wypełnij go co drugą literą alfabetu

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>

int main() {
  std::vector<std::pair<int, std::string>> v={{0, "Zero"}, {1, "One"},
                                             {2, "Two"},  {3, "Three"},
                                             {4, "Four"}, {5, "Five"}};
  std::vector<int> v2;
  std::transform(v.begin(), v.end(), std::back_inserter(v2),
                 [](auto i) { return i.first; });

  std::ranges::for_each(v2, [](auto i) { std::cout << i << '\n'; });


  std::vector<std::string> v3;
  for (auto it : v) {
    v3.push_back(std::to_string(it.first)+ ": " + it.second);
  }
  std::ranges::for_each(v3,[](auto i){
    std::cout<<i<<'\n';
  });


  const int numbers = 'z'-'a';
  std::vector<std::string> v4((numbers+1)/2);

  

  std::generate_n(v4.begin(),(numbers+1)/2,[a{'a'-1}]() mutable {
    a+=2;
    return a;
  });

  
  

  std::ranges::for_each(v4,[](auto i){
    std::cout<<i<<'\n';
  });





  return 0;
}