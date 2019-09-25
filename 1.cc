#include <iostream>
#include <vector>
/* int buf_size(void) 
{
    int i = 2;
    return i;    
}

int main()
{
    unsigned int buf = 1024;
    int a[buf_size()];
    int a1[4*7-14];
    int a2[buf];
    buf++;
    a2[1024] = 1;
    std::cout << a2[1024];
    char a3[11] = "12345678912"; 错误
} */

/* int main()
{
    int a[10];
    int n = 0;
    for (auto &i : a) {
        i = n;
        std::cout << a[n] << " ";
        n++;
    }
    int b[10];
    for (int i = 0; i != 10; i++) {
        b[i] = a[i];
    }
    return 0;
} */

int main()
{
    int a[4] = {0, 1, 2, 3};
    std::vector<int> b(std::begin(a), std::end(a));
    for (auto i : b) {
        std::cout << i << std::endl;
    }

}
