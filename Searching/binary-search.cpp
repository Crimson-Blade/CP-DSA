#include <iostream>
using namespace std;
int BinarySearch(int a[], int n, int x)
{
  int mid;

  int low = 0;

  int high = n - 1;

  do
  {
  
    mid = ((low + high) / 2);
  
    if (a[mid] > x)
    {
    
      high = mid - 1;
    }
    else if (a[mid] < x)
    {
      low = mid + 1;
    
    }
  } while (a[mid] != x && low <= high);

  if (a[mid] == x)
    return 1;
  else
    return 0;
}
int main()
{
  int n, x, i;
  cout << "Enter the number of elements";
  cin >> n;
  int a[n];
  cout << "Enter the elements in the array.";
  for (i = 0; i < n; i++)
    cin >> a[i];
  cout << "Enter the element to be searched";
  cin >> x;
  int q = BinarySearch(a, n, x);
  if (q)
    cout << "Number found";
  else
    cout << "Number not found";
  return 0;
}
