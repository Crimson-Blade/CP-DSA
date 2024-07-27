/**
 * * Generation of subsets using bit representation of integers
 * Each subset of a set of n elements can be represented as a sequence
 * of n bits, which corresponds to an integer between 0 ... 2^n -1.
 * The 1s indicate which elements are included in the subset.
 * 
 * ? Generate bit value for subset {0,3,4}.
 * ! It is 25 aka 11001
 */

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> subsets;
    for(int b = 0; b < (1<<n); b++){
        vector<int> subset;
        for(int i =0; i<n; i++){
            if (b&(1<<i)) subset.push_back(i);
        }
        subsets.push_back(subset);
    }
    for(auto x: subsets)
    {
        for( auto y: x)
            cout<<y<<" ";
        cout<<endl;
    }
}
