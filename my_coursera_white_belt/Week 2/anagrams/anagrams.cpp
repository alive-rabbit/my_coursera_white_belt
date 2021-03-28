#include <iostream>
#include <string>
#include <map>

std::map<char, int> BuildCharCounters(const std::string& word)
{
    std::map<char, int> counters;
    for (char c : word) 
    {
        ++counters[c];
    }
    return counters;
}

int main() 
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) 
    {
        std::string first_word, second_word;
        std::cin >> first_word >> second_word;
        if (BuildCharCounters(first_word) == BuildCharCounters(second_word)) 
        {
            std::cout << "YES" << std::endl;
        }
        else 
        {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}