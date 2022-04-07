#include <bits/stdc++.h>
using namespace std;
int main()
{
    // map<int,int> m;
    // for(int i=0;i<100;i++){
    //     m[i] = 2 * i;
    // }
    // // cout<<m[10]<endl;
    // // cout<<m.count(10);
    // for ( pair x : m){
    //     cout<<x.first<<" : "<<x.second<<endl;
    // }

    // map<string,int> numberOfSkillIssues({{"Lance",1},{"DH",2},{"Slay",3}});
    // cout<<numberOfSkillIssues["DH"];

    set<int> s;
    s = {1,1,1,1,3,4,4,5,2,2,2,2,7,6,5,4,3,2,1};
    int arr[] = {1,2,31,4,234,3,34,324,324,234};
    cout<<&arr<<endl;
    cout<<arr + 10<<endl;
    for(int i=0; i<=10;i++){
        cout<<arr[i]<<endl;
    }
    //sort(arr, arr + 10);
    vector<int> v;
    for(int x : s){
        cout<<x<<endl;
        v.push_back(x);
    }
    cout<<endl<<endl;
    for(int x : arr){
        cout<<x<<endl;
        
    }

}