#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;          // test cases
    cin>>t;
    while(t--){
        //Code Bellow
        int64_t n,h;
        cin>>n>>h;
        vector<int64_t> v(n);
        for(int64_t i=0;i<n;i++){
            cin>>v[i];
        }
        if(h==0){
            cout<<0<<endl;
            continue;
        }
        sort(v.begin(),v.end(), greater<int64_t>());
        int64_t ans=0;
        if(v[0]>0) ans = v[0];
        int64_t b=1;
        for(int64_t i=1;i<n;i++){
            if(v[i] != v[i-1]){
                b++;
            }
            if(b<=h){
                if(v[i] < 0) continue;
                else ans+=v[i];
            }
            else{
                break;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}