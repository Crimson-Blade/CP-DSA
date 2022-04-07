#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int space = n - 1;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < space; j++)
      cout << " ";

    for (int j = 0; j <= i; j++)
      cout << i + 1 << " ";

    cout << endl;
    space--;
  }

}