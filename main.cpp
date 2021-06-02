#include <iostream>
#include "menu.h"
int main()
{
    bool check{true};
    Menu command;
    command.welcome();
    while (check)
    {
        check = command.create_menu();
    }
    return 0;
}