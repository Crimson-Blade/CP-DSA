#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;          // test cases
    cin>>t;
    while(t>0){
        int N;
        cin>>N;
        map<int,int> vals;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            vals[x]++;
        }
        while(vals[0] + vals [1] > 1){
            if(vals[0]>0)
                vals[0]--;
            else
                vals[1]--;
            if(vals[0] + vals [1] > 1){
                if(vals[0]>0){
                    if(vals[1]>0)
                    vals[1]--;
                    else
                    vals[0]--;
                }
                else
                vals[1]--;
            }
        }
        if(vals[0]>0)
            cout<<0<<'\n';
        else
            cout<<1<<'\n';
        t--;
    }

    return 0;
}