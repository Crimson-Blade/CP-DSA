#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int64_t> numbers(n);
    for (int64_t i = 0; i < n; ++i)
    {
        std::cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end(), std::greater<int64_t>());
    int64_t ans = numbers[0] * numbers[1];
    std::cout <<ans;
    return 0;
}