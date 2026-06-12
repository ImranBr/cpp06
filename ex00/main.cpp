#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cout << "Incorrect number of arg" << std::endl, 1);
    
    ScalarConverter::convert(av[1]);
}