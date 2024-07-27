// INCOMPLETE
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, count = 0;
    cin >> n;
    map<int, int> entercar;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        entercar[x] = i;
    }
    map<int, int> exitcar;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        exitcar[x] = i;
    }
    int arrt[n+1]={0};
    for (int i = 1; i <= n; i++)
    {
        auto search1 = entercar.find(i);
        auto search2 = exitcar.find(i);
        if (arrt[i]=(search2->second - search1->second) - arrt[i-1] >0 )
        {
            arrt[i]=(search2->second - search1->second) - arrt[i-1];
        }
        else if ((search2->second - search1->second) < 0 )
        {
            arrt[i]=0;
        }
    }
    for(int i =0;i<n+1;i++)
    {
        count+=arrt[i];
    }
    cout<<count;
    return 0;
}
