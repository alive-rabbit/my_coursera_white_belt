#include <iostream>
#include <string>
#include <map>

int main() 
{
    int q;
    std::cin >> q;

    std::map<std::string, std::string> country_to_capital;

    for (int i = 0; i < q; ++i) 
    {
        std::string operation_code;
        std::cin >> operation_code;

        if (operation_code == "CHANGE_CAPITAL") 
        {

            std::string country, new_capital;
            std::cin >> country >> new_capital;
            if (country_to_capital.count(country) == 0) 
            {
                std::cout << "Introduce new country " << country << " with capital " << new_capital << std::endl;
            }
            else 
            {
                const std::string& old_capital = country_to_capital[country];
                if (old_capital == new_capital) 
                {
                    std::cout << "Country " << country << " hasn't changed its capital" << std::endl;
                }
                else 
                {
                    std::cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << std::endl;
                }
            }
            country_to_capital[country] = new_capital;

        }
        else if (operation_code == "RENAME") 
        {

            std::string old_country_name, new_country_name;
            std::cin >> old_country_name >> new_country_name;
            if (old_country_name == new_country_name || country_to_capital.count(old_country_name) == 0 || country_to_capital.count(new_country_name) == 1) 
            {
                std::cout << "Incorrect rename, skip" << std::endl;
            }
            else 
            {
                std::cout << "Country " << old_country_name << " with capital " << country_to_capital[old_country_name] <<
                    " has been renamed to " << new_country_name << std::endl;
                country_to_capital[new_country_name] = country_to_capital[old_country_name];
                country_to_capital.erase(old_country_name);
            }
        }
        else if (operation_code == "ABOUT") 
        {
            std::string country;
            std::cin >> country;
            if (country_to_capital.count(country) == 0) 
            {
                std::cout << "Country " << country << " doesn't exist" << std::endl;
            }
            else 
            {
                std::cout << "Country " << country << " has capital " << country_to_capital[country] << std::endl;
            }
        }
        else if (operation_code == "DUMP") 
        {
            if (country_to_capital.empty()) 
            {
                std::cout << "There are no countries in the world" << std::endl;
            }
            else 
            {
                for (const auto& country_item : country_to_capital) 
                {
                    std::cout << country_item.first << "/" << country_item.second << " ";
                }
                std::cout << std::endl;
            }
        }
    }

    return 0;
}
