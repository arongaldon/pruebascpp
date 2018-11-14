#include <iostream>
#include <regex>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr<<"One argument is required."<<std::endl;
        return EXIT_FAILURE;
    }

    std::regex dniPattern(R"(\d{8}-?\w)");

    if (std::regex_match(argv[1], dniPattern))
    {
        std::cout<<"A match!"<<std::endl;
    }

    return EXIT_SUCCESS;
}
