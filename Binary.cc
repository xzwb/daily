#include <iostream>
#include <string>
#include <vector>

int main()
{
    int serch = 5;
    std::vector<int> arr{1, 2, 3, 4, 5, 6};
    auto left = arr.begin();
    auto right = arr.end();
    auto mid = left + arr.size() / 2;
    while (mid != right && *mid != serch) {
        if (serch > *mid) {
            left = mid+1;
        } else {
            right = mid;
        }
        mid = left + (right - left) / 2;
    }
    if (*mid != serch) {
        std::cout << "no serch\n";
    } else {
        std::cout << *mid << std::endl;
    }

    return 0;
}
