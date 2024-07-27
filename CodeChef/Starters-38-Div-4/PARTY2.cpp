#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;          // test cases
    cin>>t;
    while(t--){
        //Code Bellow
        int N,X,K;
        cin>>N>>X>>K;
        if(N*X <= K){
            cout<<"Yes\n";
        }
        else
            cout<<"No\n";
    }

    return 0;
}