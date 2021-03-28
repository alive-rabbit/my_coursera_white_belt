bool IsPalindrom(std::string s) 
{

    for (size_t i = 0; i < s.size() / 2; ++i) 
    {
        if (s[i] != s[s.size() - i - 1]) 
        {
            return false;
        }
    }

    return true;
}

std::vector<std::string> PalindromFilter(std::vector<std::string> words, int min_length)
{
    std::vector<std::string> result;
    for (auto s : words) 
    {
        if (s.size() >= min_length && IsPalindrom(s)) 
        {
            result.push_back(s);
        }
    }
    return result;
}
