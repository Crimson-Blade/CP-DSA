
// WRONG

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;          // test cases
    cin>>t;
    while(t--){
        //Code Bellow
        int64_t N,X,check=1;
        cin>>N>>X;
        vector<int64_t>S(N);
        vector<int64_t>prefixSum(N+1);
        set<int64_t> Aj;
        cin>>S[0];
        prefixSum[0]=0;
        for(int i = 1;i<N;i++){
            cin>>S[i];
        }
        sort(S.begin(),S.end());
        for(int i = 1;i<=N;i++){
            prefixSum[i] = prefixSum[i-1] + S[i-1];
            int Bruh = prefixSum[i] - i * X;
            if(Aj.find(prefixSum[i] - i * X) != Aj.end() || prefixSum[i] - i * X == 0)
                {
                    cout<<"YES\n";
                    check=0;
                    break;
                }
            Aj.insert(prefixSum[i] - i * X);
        }
        if(check)
        cout<<"NO\n";
pair<int,int> array[10];
    }

    return 0;
    

}