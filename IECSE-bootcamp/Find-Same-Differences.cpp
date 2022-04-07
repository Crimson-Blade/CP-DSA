#include <bits/stdc++.h>
using namespace std;
int run(int a[], int &n)
{
    int count=0;
    for(int i = 0;i < n;i++)
    {
        for(int j = i + 1;j < n;j++){
            if((j-i) == (a[j]-a[i]))
            count++;

        }
    }
    return count;
}
 
// Driver code
int main()
{
    int t,tO;
    cin>>t;
    tO = t;
    int answers[t];
    while(t>0){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    // Print the count of unique pairs
    answers[t-1] = ((run(a, n)));
    t--;
    }
    for(int i = tO;i > 0;i--){
    cout<<answers[i-1]<<"\n";
    }
    return 0;
}