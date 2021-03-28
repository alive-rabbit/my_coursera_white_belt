vector<int> Reversed(const std::vector<int>& input)
{
    std::vector<int> result;
    for (int i = input.size() - 1; i >= 0; --i) 
	{
        result.push_back(input[i]);
    }
    return result;
}