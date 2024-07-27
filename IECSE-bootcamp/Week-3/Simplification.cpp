#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    int t = pow(2,n);
    cout<< m % t;
    return 0;
}
int powEven(int x, int y){
    return powEven(x,y/2) * pow()
}