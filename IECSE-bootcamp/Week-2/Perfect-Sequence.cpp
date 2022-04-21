#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,count=0;
    cin>>n;
    list<int> input;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        input.push_back(temp);
    }
    for(auto i = input.begin();i != --input.end() ;){
        if(gcd(*i,*i++) != 1){
            input.insert(i,1);
            count++;
        }
    }
    cout<<count<<"\n";
    for(auto i = input.begin();i != input.end() ;i++){
        cout<<*i<<" ";
    }
    return 0;
}