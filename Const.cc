#include <iostream>

int main()
{
    int i = 1;
    const int &a = i;
    i = 5;
    std::cout << a << std::endl;
}
