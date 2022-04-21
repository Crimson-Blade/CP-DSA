#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;          // test cases
    cin>>t;
    while(t>0){
        int64_t n,k;
        cin>>n>>k;
        if ((k * k) <= n && (n + k) % 2 == 0){
            cout<<"YES"<<"\n";
        }
        else
            cout<<"NO"<<"\n";

        t--;
    }

    return 0;
}