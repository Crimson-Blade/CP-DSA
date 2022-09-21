#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;          // test cases
    cin>>t;
    while(t--){
        vector<int64_t> v = {1,0,1,4};
        int64_t result = 1;
        int64_t a,b,c;
        cin>>a>>b>>c;
        // hlm
        for(int i=0; i<25; ++i){
            result = result * v[((b>>i)&1) + ((a>>i)&1) + ((c>>i)&1)];
        }
        cout<<result<<endl;
    }
}