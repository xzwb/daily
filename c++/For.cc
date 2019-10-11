#include <iostream>
#include <string>
#include <vector>

int main()
{
    int a[6] = {1, 2, 3, 4, 5, 6};
    std::vector<int> b(10, 1);
    std::string c("hello world");

    for (auto i : a) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (auto &i : a) {
        i *= 2;
    }
    for (auto i : a) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
