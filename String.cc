#include <iostream>
#include <string>

int main()
{
    std::string str;
    str = "hello world";
    std::cout << sizeof(str) << std::endl;
    getline(std::cin, str);
    std::cout << str << std::endl;
    std::cout << str.size() << std::endl;
    if (!str.empty()) {
            std::cout << str << std::endl;
    } else {
        std::cout << "空的" << std::endl;
    }
    for (char c : str) {
        std::cout << c;
    }
    std::cout << std::endl;
    for (char &c : str) {
        c = 'a';
    }
    std::cout << str << std::endl;

    return 0;
}
