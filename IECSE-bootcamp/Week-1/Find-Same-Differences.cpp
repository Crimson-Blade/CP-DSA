#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout<<"testcases";
    int t;          // test cases
    cin>>t;
    while(t>0){

    cout<<"size of arr";
        int n; cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int x:arr){
            cout<<x<<"\n";
        }

        t--;
    }

    return 0;
}