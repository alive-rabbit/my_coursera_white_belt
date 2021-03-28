void MoveStrings(std::vector<std::string>& source, std::vector<std::string>& destination)
{
    for (auto w : source) 
    {
        destination.push_back(w);
    }
    source.clear();
}