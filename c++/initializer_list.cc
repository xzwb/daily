#include <iostream>
#include <string>

void print(std::initializer_list<int> n) 
{
    for (auto beg = n.begin(); beg != n.end(); ++beg) {
        std::cout << *beg << std::endl;
    }
}

int main()
{
    print({1, 2, 3, 4});
    print({1, 2, 3});
}
