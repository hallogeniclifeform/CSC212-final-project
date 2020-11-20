#include <iostream>

int main(int argc, char** argv){
    int x = 0;
    int y = x;
    x++;

    std::cout << x << "," << y << std::endl;
}