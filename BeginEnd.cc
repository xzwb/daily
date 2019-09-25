#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<int> a;
    // 容器为空时begin和end指向同一个迭代器:尾后迭代器
    if (a.begin() == a.end()) {
        std::cout << "空的" << std::endl;
    } else {
        std::cout << a[0] << std::endl;
    }
    // 赋值
    // 尽量使用!=而不使用<
    for (int i = 0; i != 100; ++i) {
        a.push_back(i);
    }
    auto b = a.begin();
    std::cout << *b << std::endl;
    std::cout << *(++b) << std::endl;

    return 0;
}
