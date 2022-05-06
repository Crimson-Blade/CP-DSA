
//WRONG

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; // test cases
    cin >> t;
    while (t > 0)
    {
        int n;
        cin >> n;
        map<int, int> recCount;
        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            recCount[input]++;
        }
        map<int, int>::iterator it = recCount.end();

        if ((*prev(it, 1)).second == (*prev(it, 2)).second)
        {
            cout << "CONFUSED";
            break;
        }

        cout << ((*(prev(it, 1))).first) << "\n";

        t--;
    }

    return 0;
}