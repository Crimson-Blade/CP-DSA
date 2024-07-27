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
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int m,t,i,j=0,temp=0;
    cin>>m>>t;
    vector<int> primes;
    findPrimes(m,primes);
    for(i=0;temp<=m;i++){
        temp= primes[i] + primes[i+1] + 1;
        auto result = find(primes.begin(),primes.end(),temp);
        if(result != primes.end()){
            j++;
        }
    }
    if(t == j)
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}
