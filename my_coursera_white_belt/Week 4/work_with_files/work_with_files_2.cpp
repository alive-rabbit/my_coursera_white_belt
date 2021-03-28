#include <iostream>
#include <fstream>
#include <string>

int main() 
{
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    std::string line;
    while (std::getline(input, line)) 
    {
        output << line << std::endl;
    }

    return 0;
}