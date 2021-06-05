#include "converter.h"
Converter::Converter(std::string addres)
{
    ip_in_binary = new std::vector<std::string>;
    ocktet_cutter(addres);
}
void ocktet_cutter(std::string *addres)
{
    std::string ocktet;
    for (auto add : *addres)
    {
        if (add != '.')
            ocktet += add;
        else
        {
            (*ip_in_binary).push_back(decimal_to_binary(std::stoi(ocktet)));
            ocktet = "";
        }

        //czyta po znaku trzeba zamienic na inta!
    }
}
std::vector<string> *sub_mask_resolver(int);
std::string decimal_to_binary(int ip_decimal)
{
    std::string ip_binary;
    while (ip_decimal > 0)
    {
        ip_binary += ip_decimal % 2;
        ip_decimal /= 2;
    }
    return ip_binary;
}
