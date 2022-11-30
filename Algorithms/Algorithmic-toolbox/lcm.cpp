#include <iostream>
using namespace std;
int64_t gcd(int64_t a, int64_t b){
    if(a==0) return b;
    return gcd(b % a , a);
}
int64_t lcm(int64_t a,int64_t b){
    if(b>a)
    return a * b / gcd(a,b);
    else
    return a * b / gcd(b,a);
}
int main(){
    int64_t a,b;
    cin>>a>>b;
    cout<<lcm(a,b);
    
}