#include <iostream> 
using namespace std;
//function to sort an array using pointers
void sort(int *ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (*(ptr + j) < *(ptr + i))
            {
                int temp = *(ptr + j);
                *(ptr + j) = *(ptr + i);
                *(ptr + i) = temp;
            }
        }
    }
}
int main()
{
    cout<<"Input size of array\n";
    int n;
    cin >> n;
    cout<<"Input array elements\n";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
