#ifndef SCREEN_H
#define SCREEN_H

#include <string>
using std::string;
#include <iostream>
using std::ostream; using std::endl;
// #include "Window_mgr.h"//不应该加这个头文件

class Screen{
    friend class Window_mgr;
public: 
    typedef string::size_type pos;
    // using pos = string::size_type;
    Screen() = default;
    Screen(pos ht,pos wd):height(ht),width(wd),contents(ht*wd,' ') {};
    Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht*wd,c) {};

    char get() const
    {
        return contents[cursor];
    }

    inline char get(pos ht,pos wd) const ;

    Screen &move(pos r,pos c);

    inline Screen &set(char c);
    inline Screen &set(pos r,pos c,char ch);

    inline Screen &display(ostream &os)
    {
        to_display(os);
        return *this;
    }

    inline const Screen &display(ostream &os) const
    {
        to_display(os);
        return *this;
    }

private:
    pos cursor=0;
    pos height=0,width=0;
    string contents;

    void to_display(ostream &os) const
    {
        os << contents << endl;
    }  

};

inline char Screen::get(pos r,pos c) const
{
    pos row = r*width;
    return contents[row + c];
}

Screen & Screen::move(pos r,pos c)
{
    pos row = r*width;
    cursor = row + c;
    return *this;//返回调用此函数的对象
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r,pos c,char ch)
{
    pos row = r * width;
    contents[row+c] = ch;
    return *this;
}
#endif