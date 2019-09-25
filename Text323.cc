#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<int> a(10, 1);
    auto p = a.begin();
    auto p1 = a.end();
    while (p != p1) {
        (*p) *= 2;
        std::cout << *p << " ";
        p++;
    }
    std::cout << std::endl;

    return 0;
}
