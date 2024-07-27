#include <bits/stdc++.h>
using namespace std;
void findPrimes(int m, vector<int> &primes){
    vector<int> flag(m);
    flag[0]=flag[1]=1;
    for(int i=2;i<=m;i++){
        if(flag[i]!=1){
            primes.push_back(i);
            for(int j=2*i;j<m;j+=i)
                flag[j] = 1;
        }
    }
}
// dirver code
int main(){
    int m = 100;
    vector<int> primes;
    findPrimes(m,primes);
    for( auto x : primes){
        cout<<x<<"\n";
    }
}