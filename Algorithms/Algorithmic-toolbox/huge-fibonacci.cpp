#include <iostream>
using namespace std;
int main(){
    int64_t n,m;
    cin>>n>>m;
    int64_t curr, prev;
    curr = 1;
    prev = 0;
    for(int i = 1 ; i<n ; i++){
        int64_t temp = (curr + prev) % m;
        prev = curr;
        curr = temp;
    }
    cout<<curr;
}