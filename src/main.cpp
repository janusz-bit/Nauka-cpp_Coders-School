#include <iostream>
#include <SDL3/SDL.h>

int main()
{
    std::cout << "Piwo\n";
    SDL_Log("Hello, SDL3!\n\n");

    int i = 5; auto j = i++ - 1;
    std::cout << "a = " << j << std::endl;
    return 0;
}