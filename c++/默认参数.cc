#include <iostream>
#include <string>

std::string make_plural(size_t ctr, const std::string &word, const std::string &ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

int main()
{
    std::cout << make_plural(2, "success", "es") << std::endl;
    std::cout << make_plural(2, "apple") << std::endl;
}
