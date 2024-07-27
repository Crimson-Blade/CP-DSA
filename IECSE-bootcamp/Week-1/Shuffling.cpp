#include <bits/stdc++.h>
using namespace std;

int t,n;
int arr[110];
bool cmp(int a,int b)
{
    return a>b;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;          // test cases
    cin>>t;
    while(t>0){
        
        cin>>n;
        for (int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        if(n==1)
        {
            cout<<arr[0]<<endl;
            continue;
        }
        sort(arr,arr+n,cmp);
        for (int i=0; i<n;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");

        t--;
    }

    return 0;
}