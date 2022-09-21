#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int getMedian(int a, int b , int c) {
    int x = a-b;
    int y = b-c;
    int z = a-c;
    if(x*y > 0) return b;
    if(x*z > 0) return c;
    return a;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;          // test cases
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        for(int i=-1000;i<= +1000;i++)
            {
                for(int j=-1000;j<= +1000;j++)
                {
                    for(int k=-1000;k<= +1000;k++)
                    {
                        int median = getMedian(i,j,k);
                        if((i + j + k)/3 == x && median == y)
                        {
                            cout<<i<<" "<<j<<" "<<k<<endl;
                            break;
                        }
                    }
                }
                
            }
        
    }
}
