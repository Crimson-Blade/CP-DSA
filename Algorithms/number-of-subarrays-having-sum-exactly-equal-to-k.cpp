// https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {10, 2, -2, -20, 10};
    int k = -10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int count=0;
    vector<int> prefixSum(n);
    prefixSum[0] = arr[0];
    for(int i = 1 ; i<n; i++){
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }
    for(int i = 0 ; i<n; i++){
        if(prefixSum[i] == k)
            count++;
    }
    cout<<count;
}