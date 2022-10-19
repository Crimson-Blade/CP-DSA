#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int64_t n;
    cin>>n;
    unordered_map<int64_t, int64_t> m(n);
    for (int i = 0; i < n; i++)
    {
        int64_t x;
        cin >> x;
        m[x]++;
    }
    vector<pair<int64_t, int64_t>> v;
    for (auto i : m)
    {
        v.push_back(make_pair(i.second, i.first));
    }
    sort(v.begin(), v.end());
    for (auto i : v)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout<<endl;
    vector<pair<int64_t, int64_t>> vPrefix(v.size());
    vPrefix[0] = make_pair(v[0].second, v[0].first);
    for (int i = 1; i < v.size(); i++)
    {
        vPrefix[i] = make_pair(v[i].first, vPrefix[i - 1].second + v[i].second * v[i].first);
    }
    for (auto i : vPrefix)
    {
        cout << i.first << " " << i.second << endl;
    }
    int64_t q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        int64_t small=0,big=0;
        for(auto i:vPrefix){
            if(i.first >= a){
                small = i.second;
                break;
            }
        }
        for(auto i:vPrefix){
                big = i.second;
            if(i.first >= a){
                break;
            }
        }
    cout<<big-small<<endl;
    }
    return 0;

}
