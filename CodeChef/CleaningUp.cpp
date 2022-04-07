#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
class Rectangle
{
public:
  int length, breath;
  Rectangle(){};
  Rectangle(int a)
  {
    length = a;
  }

private:
  int area()
  {
    return length * breath;
  }
};
int main()
{
  Rectangle r1, r2(3);
  Rectangle *p;
  p = new Rectangle();
  cin >> r1.length;
  p->breath = r1.length;
  cout << r2.length << p->breath;
  cout << endl;
}