#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void solve(){
    // Code Here!
    int64_t n,q,p,k;
    cin>>n;
    vector<int64_t> M(n);
    for(int i=0;i<n;i++)
        cin>>M[i];
    cin>>q;
    for(int j=0;j<q;j++){
        //main
        int64_t final=0;
        cin>>p;
        cin>>k;
        vector<int64_t> favDishes;
        for(auto dish : M){
            if(dish%p == 0)
            favDishes.push_back(dish);
        }
        sort(favDishes.begin(),favDishes.end());
        for(int i=0;i<k;i++){
            if(M[i]%p == 0 && favDishes.size() != 0){
                final += favDishes.back();
                favDishes.pop_back();
            }
            else{
                final += M[i];
            }
        }
        cout<<final<<endl;
    }

    return;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int64_t t;          // test cases
    cin>>t;
    while(t--){
        solve();
    }
}