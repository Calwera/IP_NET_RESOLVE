#ifndef CONVERTER__
#define CONVERTER__
#include <string>
#include <vector>
class Converter
{
private:
    void ocktet_cutter(std::string *);
    std::vector<std::string> *sub_mask_resolver(int);
    std::string decimal_to_binary(int);
    std::vector<std::string> *ip_in_binary;
    std::vector<std::string> *sub_mask;

public:
    Converter(std::string);
    std::vector<string> *get_ip();
};
#endif