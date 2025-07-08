#include <array>
#include <iostream>
 
int main()
{
    std::array<int, 4> numbers{3, 1, 4, 1};
    std::array<int, 0> no_numbers;
    std::array<int, 3> numbers2;
 
    std::cout << std::boolalpha;
    std::cout << "numbers.empty(): " << numbers.empty() << '\n';
    std::cout << "no_numbers.empty(): " << no_numbers.empty() << '\n';
    std::cout << "numbers2.empty(): " << numbers2.empty() << '\n';
    for (auto i : numbers2) {
      std::cout<<i<<", ";
    
    }
    std::cout<<"\n"; //clang give initialized elements: 0, gcc not
}