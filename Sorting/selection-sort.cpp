#include <iostream>
using namespace std;
void selectionsort(int a[], int n)
{
  int i, j, sm, s;
  for (i = 0; i < n - 1; i++)
  {
    s = i;
    sm = a[i];
    for (j = i + 1; j < n; j++)
    {
      if (sm > a[j])
      {
        sm = a[j];
        s = j;
      }
    }
    a[s] = a[i];
    a[i] = sm;
  }
}
int main()
{
  int i, n;
  cout << "Enter the length of array";
  cin >> n;
  int a[n];
  cout << "Enter the elements in the array";
  for (i = 0; i < n; i++)
    cin >> a[i];
  selectionsort(a, n);
  for (i = 0; i < n; i++)
    cout << " " << a[i];
  return 0;
}
