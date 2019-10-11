#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<int> a;
    if (a.empty()) {
        std::cout << "空的" << std::endl;
    } else {
        std::cout << a[0] << std::endl;
    }
    // push_back函数把一个值当做vector对象的尾元素
    for (int i = 0; i != 100; ++i) {
        a.push_back(i);
    }
    std::cout << a[50] << std::endl;
    // 读取元素个数
    std::cout << a.size() << std::endl;
    // 判断是否为空
    if (a.empty()) {
        std::cout << "空的" << std::endl;
    } else {
        std::cout << a[0] << std::endl;
    }
    // 拷贝替换
    std::vector<int> b;
    b = a;
    std::cout << b[50] << std::endl;
    // 相等
    if (a == b) {
        std::cout << "相等" << std::endl;
    } else {
        std::cout << "不相等" << std::endl;
    }
    // 关于大于等于小于
    // std::vector<int> c{1, 2, 3};
    // std::vector<int> d{1, 2};
    // std::vector<int> c{1, 2, 3};
    // std::vector<int> d{1, 3, 2};
    std::vector<int> c{1, 2, 3};
    std::vector<int> d{1, 3};
    if (c < d) {
        std::cout << "c < d" << std::endl;
    } else {
        std::cout << "c > d" << std::endl;
    }
    if (c == d) {
        std::cout << "相等" << std::endl;
    }
}
