#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;          // test cases
    cin>>t;
    while(t>0){
        int ans=0;
        int n; cin>>n;
        int arr[n];
        map<int,int> diff;
        map<int,int> counter;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            diff[i] = arr[i] - i;
            counter[diff[i]]++;
        }
        for(auto x:counter){
            ans+= (x.second * (x.second -  1))/2;
        }
        cout<<ans<<"\n";
        t--;
    }

    return 0;
}