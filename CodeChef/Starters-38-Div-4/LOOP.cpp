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
        int64_t A,B,M;
        cin>>A>>B>>M;
        if(A>B){
            A += B;
            B = A - B;
            A = A - B;
        }
        if(B - A < A + M - B)
            cout<<B-A<<endl;
        else
            cout<<A + M - B<<endl;
    }

    return 0;
}