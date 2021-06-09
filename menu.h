#ifndef MENU__
#define MENU__
#include <iostream>
#include <limits>
using namespace std;
class Menu
{
public:
    Menu(){};
    bool create_menu();
    void welcome();
    string print_give_ip();
    int print_give_mask();
};
#endif