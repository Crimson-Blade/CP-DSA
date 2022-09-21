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
        cin>>n;
        vector<int64_t> arr1(n);
        vector<int64_t> arr2(n);
        vector<pair<int64_t, int64_t>> pairs(n);
        for(int i=0;i<n;i++){
            cin>>arr1[i];
        }
        for(int i=0;i<n;i++){
            cin>>arr2[i];
        }
        for(int i=0;i<n;i++){
            pairs[i] = make_pair(arr1[i], arr2[i]);
        }
        sort(pairs.begin(), pairs.end(), greater<pair<int64_t, int64_t>>());
        int64_t count = 1;
        int64_t max = pairs[0].second;
        for(int i=1; i<n; i++){
            if(pairs[i].second > max){
                count++;
                max = pairs[i].second;
            }
        }
        cout<<count<<endl;
    }
    int a;
}