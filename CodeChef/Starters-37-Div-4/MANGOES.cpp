#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;          // test cases
    cin>>t;
    while(t>0){
        int X,Y,Z,MAX=0;
        cin>>X>>Y>>Z;
        for(int i = X; i + Y <= Z; i+=X){
            MAX++;
        }
        cout<<MAX<<"\n";
        t--;
    }

    return 0;
}