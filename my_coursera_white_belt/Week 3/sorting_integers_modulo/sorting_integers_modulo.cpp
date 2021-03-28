#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() 
{

    // считываем вектор
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int& x : v) 
    {
        std::cin >> x;
    }

    std::sort(begin(v), end(v),
        [](int l, int r) 
        {
            return abs(l) < abs(r);
        }
    );

    // выводим отсорированный вектор
    for (int x : v) 
    {
        std::cout << x << " ";
    }

    return 0;
}
