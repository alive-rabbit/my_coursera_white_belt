#include <iostream>
#include <cmath>

int main() 
{
    double A, B, C;
    std::cin >> A >> B >> C;

    double D = B * B - 4 * A * C;

    if (A == 0) 
    {
        if (B != 0) 
        {
            std::cout << -C / B << std::endl;
        }
    }
    else if (D == 0) 
    {
        std::cout << -B / (2 * A) << std::endl;
    }
    else if (D > 0) 
    {
        double r1 = (-B + sqrt(D)) / (2 * A);
        double r2 = (-B - sqrt(D)) / (2 * A);

        std::cout << r1 << " " << r2 << std::endl;
    }

    return 0;
}
