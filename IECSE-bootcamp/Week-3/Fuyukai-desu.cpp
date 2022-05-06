#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l, r, m, type;
    int64_t sum;

    // inputing variables
    cin >> n;

    // inputing vector
    vector<int64_t> unorderedPrices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> unorderedPrices[i];
    }

    // sorting vector into another
    vector<int64_t> orderedPrices(unorderedPrices);
    sort(orderedPrices.begin(), orderedPrices.end());

    // creating vectors and finding prefix sums
    vector<int64_t> unorderedPrefixsum;
    vector<int64_t> orderedPrefixsum;
    unorderedPrefixsum.push_back(0);
    orderedPrefixsum.push_back(0);
    for (auto x : unorderedPrices)
    {
        unorderedPrefixsum.push_back(*(unorderedPrefixsum.end() - 1) + x);
    }
    for (auto x : orderedPrices)
    {
        orderedPrefixsum.push_back(*(orderedPrefixsum.end() - 1) + x);
    }
    // test cases
    cin >> m;
    while (m > 0)
    {
        cin >> type >> l >> r;
        sum = 0;
        if (type == 1)
            sum = unorderedPrefixsum[r] - unorderedPrefixsum[l - 1];
        else if (type == 2)
            sum = orderedPrefixsum[r] - orderedPrefixsum[l - 1];
        cout << sum << "\n";
        m--;
    }

    return 0;
}