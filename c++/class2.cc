#include <iostream>
#include <string>

class Screen {
public:
    using pos = std::string::size_type;
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), wight(wd), contents(ht * wd, c);
    char get() const {
        return contents[cursor];
    }
    char get(pos ht, pos wd);
    Screen &move(pos r, pos c);
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    
    return *this;
}

char Screen::get(pos r, pos c)
{
    pos row = r * width;
    
    return contents[row + c];
}



