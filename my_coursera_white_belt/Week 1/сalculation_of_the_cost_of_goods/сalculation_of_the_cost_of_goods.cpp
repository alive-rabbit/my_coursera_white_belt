#include <iostream>

int main() 
{
    double n, a, b, x, y;
    std::cin >> n >> a >> b >> x >> y;
    if (n > b) 
    {
        n *= (1 - y / 100);
    }
    else if (n > a) 
    {
        n *= (1 - x / 100);
    }
    std::cout << n;

    return 0;
}