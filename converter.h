#ifndef CONVERTER__
#define CONVERTER__
#include <string>
#include <vector>
#include <cmath>
class Converter
{
private:
    void ocktet_cutter(std::string);
    std::vector<std::string> *sub_mask_resolver(int);
    void decimal_to_binary(int);
    std::vector<std::string> ip_in_binary;
    std::vector<std::string> *sub_mask;
    std::string bin_ocktet_int(std::string);

public:
    Converter(std::string);
    std::vector<std::string> get_ip();
    std::string binary_to_decimal();
};
#endif