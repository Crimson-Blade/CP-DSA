#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;          // test cases
    cin>>t;
    while(t>0){
        int64_t a,b,c,x,y;
        cin>>a>>b>>c>>x>>y;
        if(((x-a)>0?x-a:0) + ((y-b)>0?y-b:0) <= c)
            cout<<"YES\n";
        else
            cout<<"NO\n";
        t--;
    }

    return 0;
}