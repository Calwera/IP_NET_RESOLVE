#include "ip_calc.h"
#include <iostream>
Ip_calc::Ip_calc(std::vector<std::string> ip, std::vector<std::string> mask)
    : ip_binary(ip), mask_binary(mask) {}

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
