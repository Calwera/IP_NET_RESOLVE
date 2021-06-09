#include "menu.h"
#include "converter.h"
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
    {

        Converter Test(print_give_ip(), print_give_mask());

        for (auto vec : Test.get_ip())
            cout << vec;
        cout << "\n"
             << Test.binary_to_decimal() << endl;

        break;
    }
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
string Menu::print_give_ip()
{
    string ip_addres;
    int condition{1}; // ocktet counter from 1 to 4.
    cout << "Please type IP: " << endl;
    do
    {
        string tmp_ockt;

        cout << condition << " ocktet: ";
        cin >> tmp_ockt;
        bool good_value{true};
        for (auto val : tmp_ockt)
        {
            if (val <= 47 || val > 57) // ASCII to only consider num values
            {
                cout << "invalid ocktet please try again!" << endl;
                good_value = false;
            }
        }
        if (good_value)
        {
            ip_addres += tmp_ockt;
            ip_addres += '.';
            condition++;
        }
    } while (condition < 5);
    ip_addres.pop_back(); // erase last dot
    return ip_addres;
}
int Menu::print_give_mask()
{
    int sub_mask{};
    bool cond{true};
    while (cond)
    {
        cout << "Please type Subnet mask in CIDR notation (Classless Inter-Domain Routing): " << endl;
        cin >> sub_mask;
        while (1)
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "You have entered wrong input" << endl;
                cout << "Please type Subnet mask in CIDR notation (Classless Inter-Domain Routing): " << endl;
                cin >> sub_mask;
            }
            if (!cin.fail())
                break;
        }

        cout << sub_mask << endl;
        if (sub_mask > 30 || sub_mask <= 0)
            cout << "Bad mask number try again" << endl;
        else
            cond = false;
    }
    return sub_mask;
}
