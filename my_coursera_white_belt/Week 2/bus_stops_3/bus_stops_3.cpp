#include <iostream>
#include <string>
#include <set>
#include <map>

int main() 
{
    int q;
    std::cin >> q;

    std::map<std::set<std::string>, int> buses;

    for (int i = 0; i < q; ++i) 
    {
        int n;
        std::cin >> n;
        std::set<std::string> stops;
        for (int j = 0; j < n; ++j) 
        {
            std::string stop;
            std::cin >> stop;
            stops.insert(stop);
        }
        if (buses.count(stops) == 0) 
        {
            const int new_number = buses.size() + 1;
            buses[stops] = new_number;
            std::cout << "New bus " << new_number << std::endl;
        }
        else 
        {
            std::cout << "Already exists for " << buses[stops] << std::endl;
        }
    }

    return 0;
}