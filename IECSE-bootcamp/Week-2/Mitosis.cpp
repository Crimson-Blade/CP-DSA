#include <bits/stdc++.h>
using namespace std;
int count_one(int n)
{
    int count=0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        int n;
        cin >> n;
        cout << count_one(n) << "\n";

    return 0;
}
