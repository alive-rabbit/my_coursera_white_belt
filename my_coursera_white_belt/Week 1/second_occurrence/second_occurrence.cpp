#include <iostream>
#include <string>

int main() 
{
    std::string s;
    std::cin >> s;

    int result = -2;

    for (int i = 0; i < s.size(); ++i) 
    {
        if (s[i] == 'f') 
        {

            if (result == -2) 
            {
                result = -1;
            }
            else if (result == -1) 
            {
                result = i;
                break;
            }
        }
    }
    std::cout << result;
    
    return 0;
}