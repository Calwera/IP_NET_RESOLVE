#include "menu.h"
void Menu::welcome()
{
    cout << "==========================================" << endl;
    cout << "________WELCOME TO IP NET RESOLVE_________" << endl;
    cout << "==========================================" << endl;
}
bool Menu::create_menu()
{
    char choice{};
    cout << "1 <- Resolve basic network addreses (1 host, broadcast, etc)" << endl;
    cout << "2 <- Calculate number of subnets networks perspective" << endl;
    cout << "3 <- Calculate number of subnets host perspective" << endl;
    cout << "4 <- Exit the program!" << endl;
    cout << "Please choose what You want to do: ";
    cin >> choice;
    switch (choice)
    {
    case '1':
        break;
    case '2':
        break;
    case '3':
        break;
    case '4':
    case 'q':
    case 'Q':
        return false;
    default:
        cout << "Invalid option..." << endl;
        break;
    }
    return true;
}