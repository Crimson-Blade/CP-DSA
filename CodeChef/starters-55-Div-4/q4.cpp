#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;          // test cases
    cin>>t;
    while(t--){
        std::vector<int> a;
        std::map<int, int> b;
        int x,y;
        cin>>x;
        for(int i=0; i<x;i++){
            int temp;
            cin>>temp;
            a.push_back(temp);
        }
        cin>>y;
        for(int i=0; i<y;i++){
            int temp;
            cin>>temp;
            b[temp]++;
        }

        for(int i=0; i<x;i++){
            if(b[a[i]] == 0)
                cout<<a[i]<<' ';
        }
        cout<<endl;
    }
}