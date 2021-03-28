#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main()
{
    std::ifstream input("input.txt");

    double a;

    std::cout << std::fixed << std::setprecision(3);

    while (input >> a)
    {
        std::cout << a << std::endl;
    }

    return 0;
}