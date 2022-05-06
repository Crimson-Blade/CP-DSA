#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;          // test cases
    cin>>t;
    int H,X;
    while(t>0){
        cin>>X>>H;
        if(X>=H)
            cout<<"YES\n";
        else
            cout<<"NO\n";
        t--;
    }

    return 0;
}