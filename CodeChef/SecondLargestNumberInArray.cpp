#include <bits/stdc++.h>
using namespace std;

void secondLargest(int arr[], int sizeOfArray)
{
  int i;

  // Checking for at least two elements
  if (sizeOfArray < 2)
  {
    cout<<" Invalid Input "<<endl;
    return;
  }

  // sorting
  sort(arr, arr + sizeOfArray);

  // itterating from second last element
  for (i = sizeOfArray - 2; i >= 0; i--)
  {
    if (arr[i] != arr[sizeOfArray - 1])
    {
      cout << "The second largest element is " << arr[i] << endl;
      return;
    }
  }

  cout<<"No second largest element"<<endl; 
}

int main()
{
  int arr[] = {30, 68, 5, 1337, 34, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  secondLargest(arr, n);
  return 0;
}