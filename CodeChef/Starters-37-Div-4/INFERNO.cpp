#include <bits/stdc++.h>
using namespace std;

int case1(int X, vector<int> healthpoints){
    int secs=0;
    for( auto x : healthpoints){
        while(x>0){
            x-=X;
            secs++;
        }
    }
    return secs;
}
int case2(int X, vector<int> healthpoints){
    sort(healthpoints.begin(),healthpoints.end());
    int secs = healthpoints[healthpoints.size()-1];
    return secs;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;          // test cases
    cin>>t;
    while(t>0){
        int N,X;
        cin>>N>>X;
        vector<int> healthpoints(N);
        for( auto &x : healthpoints){
            cin>>x;
        }
        int t1,t2;
        t1 = case1(X,healthpoints);
        t2 = case2(X,healthpoints);
        int timee = t1<t2?t1:t2;
        cout<<timee<<"\n";
        t--;
    }

    return 0;
}