#include <iostream>
#include <string>
#include <map>
#include <set>

int main() 
{
    int q;
    std::cin >> q;

    std::map<std::string, std::set<std::string>> synonyms;

    for (int i = 0; i < q; ++i) 
    {
        std::string operation_code;
        std::cin >> operation_code;

        if (operation_code == "ADD") 
        {
            std::string first_word, second_word;
            std::cin >> first_word >> second_word;

            // второе слово добавляем в список синонимов первого...
            synonyms[first_word].insert(second_word);
            // и наоборот
            synonyms[second_word].insert(first_word);
        }
        else if (operation_code == "COUNT") 
        {
            std::string word;
            std::cin >> word;
            std::cout << synonyms[word].size() << std::endl;
        }
        else if (operation_code == "CHECK") 
        {
            std::string first_word, second_word;
            std::cin >> first_word >> second_word;

            // ищём второе слово во множестве синонимов первого
            // (можно было сделать и наоборот)
            if (synonyms[first_word].count(second_word) == 1) 
            {
                std::cout << "YES" << std::endl;
            }
            else 
            {
                std::cout << "NO" << std::endl;
            }
        }
    }

    return 0;
}
