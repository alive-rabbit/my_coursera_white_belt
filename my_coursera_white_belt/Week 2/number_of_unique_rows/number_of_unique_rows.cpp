#include <iostream>
#include <string>
#include <set>

int main() 
{
    int n;
    std::cin >> n;
    std::set<std::string> strings;
    for (int i = 0; i < n; ++i) 
    {
        std::string s;
        std::cin >> s;
        strings.insert(s);
    }
    std::cout << strings.size() << std::endl;

    return 0;
}