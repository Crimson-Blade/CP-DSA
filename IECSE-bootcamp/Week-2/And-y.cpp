#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;          // test cases
    cin>>t;
    while(t>0){

        unsigned int T;
        cin>>T;
        unsigned leastValue = pow(2,(int)log2(T)) -1;
        cout<<leastValue<<"\n";

        t--;
    }

    return 0;
    cout<<"hello";
}