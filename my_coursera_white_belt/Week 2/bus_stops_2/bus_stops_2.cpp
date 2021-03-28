#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() 
{
    int q;
    std::cin >> q;

    std::map<std::vector<std::string>, int> buses;

    for (int i = 0; i < q; ++i) 
    {
        int n;
        std::cin >> n;
        std::vector<std::string> stops(n);
        for (std::string& stop : stops)
        {
            std::cin >> stop;
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
