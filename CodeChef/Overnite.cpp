// C++ implementation of finding all k
// such that arr[i]%k is same for each i
#include<bits/stdc++.h>
using namespace std;
 
// Prints all k such that arr[i]%k is same for all i
int printEqualModNumbers (int arr[], int n)
{
    int ans;
    // sort the numbers
    sort(arr, arr + n);
 
    // max difference will be the difference between
    // first and last element of sorted array
    int d = arr[n-1] - arr[0];
     
    // Case when all the array elements are same
    if(d==0){
        ans = -1;
    }
 
    // Find all divisors of d and store in
    // a vector v[]
    vector <int> v;
    for (int i=1; i*i<=d; i++)
    {
        if (d%i == 0)
        {
            v.push_back(i);
            if (i != d/i)
                v.push_back(d/i);
        }
    }
 
    // check for each v[i] if its modulus with
    // each array element is same or not
    for (int i=0; i<v.size(); i++)
    {
        int temp = arr[0]%v[i];
 
        // checking for each array element if
        // its modulus with k is equal to k or not
        int j;
        for (j=1; j<n; j++)
            if (arr[j] % v[i] != temp)
                break;
 
        // if check is true print v[i]
        if (j == n)
            ans = v[i];
    }
    return ans;
}
 
// Driver function
int main()
{
    int T;
    cin>>T;
    while(T>0){
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    int y = printEqualModNumbers(arr, n);
    if(y==-1){
        cout<<0;
        return 0;
    }
    int count=0;
    for (int i=0; i<n; i++){
    if(arr[i]%y == arr[i]);
    else
    count++;
    }
    cout<<count;
        T--;
    }
    return 0;
}