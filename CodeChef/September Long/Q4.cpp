#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int64_t t;          // test cases
    cin>>t;
    while(t--){
        int n;
        map<int64_t, int64_t> m;
        cin>>n;
        for(int i=0;i<n;i++){
            int64_t x;
            cin>>x;
            m[x]++;
        }
        int64_t count = 0;
        for(auto p : m){
            if(p.second>1){
                count+= (p.second * (p.second-1)) /2 ;
            }
        }
        cout<<count<<endl;

    }
}