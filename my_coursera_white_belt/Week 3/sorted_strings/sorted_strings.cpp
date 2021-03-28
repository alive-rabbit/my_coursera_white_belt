#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class SortedStrings
{
public:
    void AddString(const std::string& s)
    {
        data.push_back(s);
    }
    std::vector<std::string> GetSortedStrings()
    {
        std::sort(begin(data), end(data));
        return data;
    }
private:
    std::vector<std::string> data;
};
