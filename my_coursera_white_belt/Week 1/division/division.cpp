#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;

    if (b == 0)
    {
        std::cout << "Impossible" << std::endl;
    }
    else 
    {
        std::cout << a / b << std::endl;
    }

    return 0;
}