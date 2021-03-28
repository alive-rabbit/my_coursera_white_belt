#include <algorithm>
#include <map>
#include <vector>
#include <string>

std::vector<std::string> FindNamesHistory(const std::map<int, std::string>& names_by_year,
    int year) 
{
    std::vector<std::string> names;
    for (const auto& item : names_by_year) 
    {
        if (item.first <= year && (names.empty() || names.back() != item.second)) 
        {
            names.push_back(item.second);
        }
    }
    return names;
}

std::string BuildJoinedName(std::vector<std::string> names) 
{
    if (names.empty()) 
    {
        return "";
    }
    reverse(begin(names), end(names));

    std::string joined_name = names[0];

    for (int i = 1; i < names.size(); ++i) 
    {
        if (i == 1) 
        {
            joined_name += " (";
        }
        else 
        {
            joined_name += ", ";
        }
        joined_name += names[i];
    }

    if (names.size() > 1) 
    {
        joined_name += ")";
    }

    return joined_name;
}

std::string BuildFullName(const std::string& first_name, const std::string& last_name) 
{
    if (first_name.empty() && last_name.empty()) 
    {
        return "Incognito";
    }
    else if (first_name.empty()) 
    {
        return last_name + " with unknown first name";
    }
    else if (last_name.empty()) 
    {
        return first_name + " with unknown last name";
    }
    else 
    {
        return first_name + " " + last_name;
    }
}

class Person 
{
public:
    void ChangeFirstName(int year, const std::string& first_name)
    {
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const std::string& last_name)
    {
        last_names[year] = last_name;
    }

    std::string GetFullName(int year) 
    {
        const std::vector<std::string> first_names_history = FindFirstNamesHistory(year);
        const std::vector<std::string> last_names_history = FindLastNamesHistory(year);

        std::string first_name;
        std::string last_name;
        if (!first_names_history.empty()) 
        {
            first_name = first_names_history.back();
        }
        if (!last_names_history.empty()) 
        {
            last_name = last_names_history.back();
        }
        return BuildFullName(first_name, last_name);
    }

    std::string GetFullNameWithHistory(int year)
    {
        const std::string first_name = BuildJoinedName(FindFirstNamesHistory(year));
        const std::string last_name = BuildJoinedName(FindLastNamesHistory(year));
        return BuildFullName(first_name, last_name);
    }

private:
    std::vector<std::string> FindFirstNamesHistory(int year)
    {
        return FindNamesHistory(first_names, year);
    }
    std::vector<std::string> FindLastNamesHistory(int year)
    {
        return FindNamesHistory(last_names, year);
    }

    std::map<int, std::string> first_names;
    std::map<int, std::string> last_names;
};
