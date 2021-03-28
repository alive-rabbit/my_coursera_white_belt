std::set<std::string> BuildMapValuesSet(const std::map<int, std::string>& m) 
{
  std::set<std::string> values;
  for (const auto& item : m) 
  {
    values.insert(item.second);
  }
  return values;
}