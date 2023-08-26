#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <vector>
using std::vector;
#include "Screen.h"
#include <iostream>
using std::cout; using std::endl;


class Window_mgr{

public:
    using ScreenIndex = vector<Screen>::size_type ;
    void clear(ScreenIndex i);
    void show(ScreenIndex i);
private:
    vector<Screen> screens{Screen(5,5,'#')};

};

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = string(s.height*s.width,'%');
}

void Window_mgr::show(ScreenIndex i)
{
    cout << screens[i].contents << endl;
}


#endif