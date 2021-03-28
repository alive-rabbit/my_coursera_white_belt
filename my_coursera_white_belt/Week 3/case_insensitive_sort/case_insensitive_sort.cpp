#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() 
{
    // считываем вектор строк
    int n;
    std::cin >> n;
    std::vector<std::string> v(n);
    for (std::string& s : v) 
    {
        std::cin >> s;
    }

    // сортируем
    sort(begin(v), end(v),
        [](const std::string& l, const std::string& r) 
        {
            return lexicographical_compare(
                begin(l), end(l),
                begin(r), end(r),
                [](char cl, char cr) { return tolower(cl) < tolower(cr); }
            );
        }
    );

    for (const std::string& s : v) 
    {
        std::cout << s << ' ';
    }

    return 0;
}
