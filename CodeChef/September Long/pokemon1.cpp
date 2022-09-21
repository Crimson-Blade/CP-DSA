#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int64_t t;          // test cases
    cin>>t;
    while(t--){
        int64_t n;
        cin>>n;
        list<pair<int64_t, int64_t>>::iterator iteratorToPowerA[n+1], iteratorToPowerB[n+1];
        list<pair<int64_t, int64_t>> powerA, powerB;
        map<int64_t, int64_t> mapForStrength;
        for(int64_t i=1;i<=n;i++){
            int64_t x;
            cin>>x;
            powerA.push_front(make_pair(x, i));
            iteratorToPowerA[i] = powerA.begin();
        }
        powerA.sort(greater<pair<int64_t, int64_t>>());

        for(int64_t i=1;i<=n;i++){
            int64_t x;
            cin>>x;
            powerB.push_front(make_pair(x, i));
            iteratorToPowerB[i] = powerB.begin();
        }
        powerB.sort(greater<pair<int64_t, int64_t>>());

        for(int64_t i=1;i<=n;i++){
            set<int64_t> setForWins;
            list<pair<int64_t, int64_t>>::iterator itA = iteratorToPowerA[i];
            list<pair<int64_t, int64_t>>::iterator itB = iteratorToPowerB[i];
            advance(itA, 1);
            advance(itB, 1);
            while(itA!=powerA.end()){
                // cout<<itA->second<<" ";
                setForWins.insert(itA->second);
                advance(itA, 1);
            }
            while(itB!=powerB.end()){
                // cout<<itB->second<<" ";
                setForWins.insert(itB->second);
                advance(itB, 1);
            }            
            // cout<<"Wins of "<<i<<endl;
            // for(auto x : setForWins){
            //     cout<<x<<" ";
            // }
            // cout<<endl;
            mapForStrength[i] = setForWins.size();
        }
        




        // cout<<"pointer A:"<<endl;
        // for(int i=1;i<=n;i++){
        //     cout<<iteratorToPowerA[i]->first<<" "<<iteratorToPowerA[i]->second<<endl;
        // }
        // cout<<"List A:"<<endl;
        // for(auto p : powerA){
        //     cout<<p.first<<" "<<p.second<<endl;
        // }
        // cout<<"List B:"<<endl;
        // for(auto p : powerB){
        //     cout<<p.first<<" "<<p.second<<endl;
        // }
        // cout<<"Map:"<<endl;
        // for(auto p : mapForStrength){
        //     cout<<p.first<<" "<<p.second<<endl;
        // }
        // cout<<"Mode: "<<endl;
        unordered_map<int64_t,int64_t> hashMap;   
        for(auto p : mapForStrength){
            hashMap[p.second]++;
        }
        // find the max frequency
        int max_count = 0, res = -1;
        for (auto i : hashMap) {
            if (max_count < i.second) {
                res = i.first;
                max_count = i.second;
            }
        }
        cout<<max_count<<endl;
    }
}