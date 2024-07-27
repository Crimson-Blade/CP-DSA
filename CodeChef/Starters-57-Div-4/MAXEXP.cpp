#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void solve(){
    // Code Here!
    vector<char> numbers;
    vector<char> ops;
    vector<char> final;
    int64_t n;
    cin>>n;
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        if(c == '+' || c == '-')
            ops.push_back(c);
        else
            numbers.push_back(c);
    }
    sort(ops.begin(),ops.end(),greater<char>());
    sort(numbers.begin(),numbers.end());
    for(int i=0;i<n;i++){
        if(i<numbers.size())
        final.push_back(numbers[i]);
        if(i<ops.size())
        final.push_back(ops[i]);
    }
    for(int i = n-1;i>=0;i--) cout<<final[i];
    cout<<endl;
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