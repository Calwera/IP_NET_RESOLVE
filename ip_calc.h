#ifndef IP_CALC__
#define IP_CALC__
#include <string>
#include <vector>
#include <cmath>
class Ip_calc
{
public:
    Ip_calc(std::vector<std::string> &ip_binary, std::vector<std::string> &mask_binary);
    Ip_calc(std::vector<std::string> &ip_binary, std::vector<std::string> &mask_binary, int num_net);
    int net_numb{};
    std::vector<std::string> ip_binary;
    std::vector<std::string> mask_binary;
    std::vector<std::string> get_net_add();
    std::vector<std::string> get_first_host();
    std::vector<std::string> get_last_host();
    std::vector<std::string> get_broadcast();
    bool possible_to_sub();
    void subnet();
};
#endif