// ## Zadanie 2 - `length-sort`

// Napisz funkcję `lengthSort()`.

// Ma ona przyjąć `std::forward_list<std::string>` i zwrócić
// `std::deque<std::string>` z posortowanymi słowami od najkrótszego do
// najdłuższego. Jeżeli dwa lub więcej słów ma tyle samo znaków posortuj je
// leksykograficznie.

// * Input: `std::forward_list<std::string>{"Three", "One", "Four", "Two"}`
// * Output: `std::deque<std::string>{"One", "Two", "Four", "Three"}`

#include <algorithm>
#include <deque>
#include <forward_list>
#include <functional>
#include <iostream>
#include <string>

std::deque<std::string>
lengthSort(const std::forward_list<std::string> &input) {
  std::deque<std::string> output;
  for (const auto& String: input) {
    output.push_back(String);
  }
  std::sort(output.begin(),output.end(),[](std::string a, std::string b){
    if (a.length() == b.length()) {
      return std::less<std::string>{}(a,b);
    }
    else 
    {
      return a.length()<b.length();
    }
  });
  return output;
}

int main()
{
  std::forward_list<std::string> input{"Three", "One", "Four", "Two"};
  std::deque<std::string> output = lengthSort(input);

  std::cout<<"{";
  bool isFirst = true;
  for (auto i : output) {
    
    if(isFirst)
    {
      isFirst = false;
    }
    else {
      std::cout<<", ";
    }
    std::cout<<"\""<<i<<"\"";
  }
  std::cout<<"}\n";
}