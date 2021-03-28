void EnsureEqual(const std::string& s, const std::string& t)
{
    if (s != t)
    {
        throw std::runtime_error(s + " != " + t);
    }
}
