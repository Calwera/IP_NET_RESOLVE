#include "converter.h"
#include <iostream> //testing
Converter::Converter(int mask, std::string addres)
{
    subnet_mask_to_bin(mask);
    ocktet_cutter(addres);
}
void Converter::ocktet_cutter(std::string addres)
{
    std::string ocktet;
    for (auto add : addres)
    {
        if (add != '.' && add != '\0')
            ocktet += add;
        else
        {
            decimal_to_binary(std::stoi(ocktet));
            ocktet = "";
        }
    }
    decimal_to_binary(std::stoi(ocktet));
}

void Converter::decimal_to_binary(int ip_decimal)
{

    int ocktet_counter{8};
    std::string ip_binary{};
    while (ip_decimal > 0)
    {
        if (ip_decimal % 2 == 0)
            ip_binary.insert(0, "0");
        else
            ip_binary.insert(0, "1");

        ip_decimal /= 2;
        ocktet_counter--;
    }
    if (ocktet_counter != 0) //inserting 0 to fill ocktet
        while (ocktet_counter > 0)
        {
            ip_binary.insert(0, "0");
            ocktet_counter--;
        }

    ip_in_binary.push_back(ip_binary);
}
std::vector<std::string> &Converter::get_ip()
{
    return ip_in_binary;
}
std::string Converter::binary_to_decimal(std::vector<std::string> ip)
{

    std::string ip_decimal;
    std::string temp;
    for (auto vec : ip)
    {
        temp += vec;
        if (temp.size() == 8)
        {
            ip_decimal += bin_ocktet_int(temp);
            ip_decimal += ".";
            temp = "";
        }
    }
    ip_decimal.pop_back(); //erase last
    return ip_decimal;
}
std::string Converter::bin_ocktet_int(std::string ocktet)
{
    std::string num = ocktet;
    int dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    int base = 1;

    int len = num.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return std::to_string(dec_value);
}
void Converter::subnet_mask_to_bin(int mask)
{
    int tmp_mask = mask;
    std::string temp;
    for (int i = 1; i < 33; i++)
    {
        if (tmp_mask < i)
            temp += '0';
        else
            temp += '1';
        if (temp.size() == 8)
        {
            sub_mask.push_back(temp);
            temp = "";
        }
    }
}
std::vector<std::string> &Converter::get_mask()
{
    return sub_mask;
}
int Converter::mask_to_cidr(std::vector<std::string> &mask)
{
    int maskint{};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((mask.at(i)).at(j) == '1')
                maskint++;
        }
    }
    return maskint;
}