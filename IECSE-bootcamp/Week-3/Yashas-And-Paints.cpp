// Incomplete
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, count = 0, maxRange;
    pair<int, int> maxRangeIndices;
    cin >> n;
    vector<pair<int, int>> input(n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i].first;
        arr[i] = input[i].first;
        input[i].second = i;
    }
    sort(input.begin(), input.end());
    int min = input[0].first;
    for (int i = 0; input[i].first == min; i++)
    {
        count++;
    }
    for (int i = 0; i < count + 1; i++)
    {
        if ((unsigned)(input[i % count].second - input[(i + 1) % count].second) > maxRange)
        {
            maxRange = (unsigned)(input[i % count].second - input[(i + 1) % count].second);
            maxRangeIndices.first = input[i % count].second;
            maxRangeIndices.second = input[(i + 1) % count].second;
        }
    }
     return 0;
}