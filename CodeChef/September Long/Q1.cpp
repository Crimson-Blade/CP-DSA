#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int64_t t;          // test cases
    cin>>t;
    while(t--){
        int64_t n;      // number of elements
        cin>>n;
        int64_t arr[n];
        for(int64_t i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr, arr+n);
        int64_t sqArr[n];
        for(int64_t i=0;i<n;i++){
            sqArr[i] = arr[i]*arr[i];
        }
        auto largest = max_element(sqArr, sqArr+n);
        int64_t max = *largest;
        auto smallest = min_element(sqArr, sqArr+n);
        int64_t min = *smallest;
        int64_t otherMin = arr[0] * arr[n-1];
        cout<<((min<otherMin)?min:otherMin)<<" ";
        cout<<max<<endl;
    }
}