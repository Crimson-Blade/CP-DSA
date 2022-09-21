#include <bits/stdc++.h>
using namespace std;
void solve(){
     int64_t n,counter=0;
        cin>>n;
        map<int64_t, int64_t, std::greater<int64_t>>powers1;
        map<int64_t, int64_t>powers2; 
        for(int64_t i=0;i<n;i++){
            int64_t x;
            cin>>x;
            powers1.insert(make_pair(x, i));
        }
        for(int64_t i=0;i<n;i++){
            int64_t x;
            cin>>x;
            powers2.insert(make_pair(x, i));
        }
        vector<int64_t> ans;
        for(auto i:powers1){
            ans.push_back(i.second);
        }
        for(auto i:powers2){
            ans.push_back(i.second);
        }    
        for(int64_t i=0;i<n;i++){
            set<int64_t> SET;
            for(int64_t j=i+1;j<(2 * n);j++){
                if(ans[j]==ans[i]){
                    break;
                }
                else{
                    SET.insert(ans[j]);
                }
            }
            if(SET.size()==(n-1)){
                counter+=1;
            }
        }
        cout<<counter<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}