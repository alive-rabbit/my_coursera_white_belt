#include <algorithm>
#include <string>

class ReversibleString 
{
public:
  ReversibleString() {}
  ReversibleString(const std::string& s) 
  {
    data = s;
  }
  void Reverse() 
  {
    reverse(begin(data), end(data));
  }
  std::string ToString() const 
  {
    return data;
  }
private:
  std::string data;
};