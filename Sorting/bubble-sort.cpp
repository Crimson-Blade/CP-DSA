#include <iostream>
using namespace std;
void BubbleSort(int a[], int n)
{
  int i, j, temp;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (a[j] > a[j + 1])
      {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
}
int main()
{
  int i, n;
  cout << "Enter the number of elements ";
  cin >> n;
  cout << "Enter the elements in the array ";
  int a[n];
  for (i = 0; i < n; i++)
    cin >> a[i];
  BubbleSort(a, n);
  cout << " \nThe elements after sorting is  " << endl;
  for (i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  return 0;
}
