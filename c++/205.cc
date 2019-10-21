#include <iostream>
#include <vector>
#include <string>

void read_vect(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (begin == end) {
        return;
    } else {
        std::cout << *begin << std::endl;
        return read_vect(++begin, end);
    }
}

int main()
{
    std::vector<int> n{1, 2, 3, 4, 5};
    read_vect(n.begin(), n.end());
    
    return 0;
}
