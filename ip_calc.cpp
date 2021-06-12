#include "ip_calc.h"
#include <iostream>

Ip_calc::Ip_calc(std::vector<std::string> &ip, std::vector<std::string> &mask)
    : ip_binary(ip), mask_binary(mask) {}

Ip_calc::Ip_calc(std::vector<std::string> &ip, std::vector<std::string> &mask, int num_net)
    : ip_binary(ip), mask_binary(mask), net_numb{num_net} {}

std::vector<std::string> Ip_calc::get_net_add()
{
    std::vector<std::string> net_add;

    for (int i = 0; i < 4; i++)
    {
        std::string tmp;
        for (int j = 0; j < 8; j++)
        {
            if ((mask_binary.at(i)).at(j) == '1')
                tmp += (ip_binary.at(i)).at(j);
            else
                tmp += '0';
        }
        net_add.push_back(tmp);
        tmp = "";
    }
    return net_add;
}
std::vector<std::string> Ip_calc::get_first_host()
{
    std::vector<std::string> first_host;
    first_host = get_net_add();
    first_host.at(3).at(7) = '1';
    return first_host;
}
std::vector<std::string> Ip_calc::get_last_host()
{
    std::vector<std::string> last_host;
    last_host = get_broadcast();
    last_host.at(3).at(7) = '0';
    return last_host;
}
std::vector<std::string> Ip_calc::get_broadcast()
{
    std::vector<std::string> broadcast;
    for (int i = 0; i < 4; i++)
    {
        std::string tmp;
        for (int j = 0; j < 8; j++)
        {
            if ((mask_binary.at(i)).at(j) == '1')
                tmp += (ip_binary.at(i)).at(j);
            else
                tmp += '1';
        }
        broadcast.push_back(tmp);
        tmp = "";
    }
    return broadcast;
}
/*
@possible_to_sub
function checks if subneting is possible

*/
bool Ip_calc::possible_to_sub()
{
    int host_pos{}, tmp{};
    for (int i = 0; i < 4; i++) //couting host bits in mask
    {
        for (int j = 0; j < 8; j++)
        {
            if ((mask_binary.at(i)).at(j) == '0')
                host_pos++;
        }
    }
    for (int i = 1; i < host_pos; i++) //comparing number of possible subnets with given number
    {
        tmp = (int)pow(2, i);
        if (tmp >= net_numb)
            return true;
    }
    return false;
}
void Ip_calc::subnet()
{
    int numb_bits_move{}, tmp{};
    for (int i = 1; tmp <= net_numb; i++)
    {
        tmp = (int)pow(2, i);
        numb_bits_move = i - 1;
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((mask_binary.at(i)).at(j) == '0' && numb_bits_move != 0)
            {
                mask_binary.at(i).at(j) = '1';
                numb_bits_move--;
            }
        }
    }
}
