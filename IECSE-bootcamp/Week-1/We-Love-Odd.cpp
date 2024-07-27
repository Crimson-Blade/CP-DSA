#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
    return a>b;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;          // test cases
    cin>>t;
    while(t>0){
        //declaration
        int n,counter=0;
        cin>>n;
        set<int,greater<int>> input;
        set<int,greater<int>> :: iterator itr;

        //Inputing Array (Only Even numbers)
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            if(temp%2==0){
                input.insert(temp);
            }
        }
        //Solution
        
        while(input.size()>0){

            itr = input.begin();
            input.erase(*itr);
            if(*itr%2==0 && (*itr/2)%2==0)
            input.insert(*itr/2);
            counter++;
        }
        cout<<counter<<"\n";
        t--;
    }
    return 0;
}