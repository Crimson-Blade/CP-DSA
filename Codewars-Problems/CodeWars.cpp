#include <string>
#include <iostream>
#include <string_view>
using namespace std;
static bool endsWith(string_view str, string_view suffix)
{
  return str.size() >= suffix.size() && 0 == str.compare(str.size() - suffix.size(), suffix.size(), suffix);
}
bool solution(string const &str, string const &ending)
{
  if (endsWith(str, ending))
    return true;
  else
    return false;
}

int main()
{
  cout << solution("hello", "llo") << "\n";
  cout << "out\n";
}