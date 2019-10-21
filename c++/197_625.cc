#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    // char*转string
    std::string s;
    for (int i = 0; i < argc; ++i) {
        s = s + argv[i];
    }
    std::cout << s << std::endl;

    // string转char*
    // 等号左边用const或者等号右边用(char*)强制转化
    const char *char_s = s.data();
    std::cout << char_s << std::endl;
    // c_str方法
    const char *p = s.c_str();
    std::cout << p << std::endl;
    // copy方法
    std::string str = "hello";
    char a[10];
    str.copy(a, 6, 0);
    // 手动加结束符
    *(a+5) = '\0';
    std::cout << a << std::endl;
    // string转char[]
    char c[10];
    for (int i = 0; i < str.length(); ++i) {
        c[i] = str[i];
    }
    std::cout << a << std::endl;

    return 0;
}
