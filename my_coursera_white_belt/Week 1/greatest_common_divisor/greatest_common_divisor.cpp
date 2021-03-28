#include <iostream>

int main() 
{
    int a, b;
    std::cin >> a >> b;

    while (a > 0 && b > 0) 
    {
        if (a > b) 
        {
            a %= b;
        }
        else 
        {
            b %= a;
        }

    }

    std::cout << a + b;

    return 0;
}