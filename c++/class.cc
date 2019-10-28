#include <iostream>
#include <string>
#include <vector>

class Person {
    friend std::istream &read(std::istream &is, Person *item);
    friend std::ostream &print(std::ostream &os, Person *item);
private:        
    std::string name;
    std::string address;
public:    
    Person() : name(""), address("") {}
    std::string get_name() const { return name; }
    std::string get_address() const { return address; }
}

std::istream &read(std::istream &is, Person *item)
{
    return is >> item.name >> item.address;
}

std::ostream &print(std::ostream &os, const Person &item)
{
    return os << item.name << " " << item.address;
}
