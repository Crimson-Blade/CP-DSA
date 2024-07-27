#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;          // test cases
    cin>>t;
    while(t--){
        
        vector<int> buses = {20,30,10};
        vector<int> passengers = {19,13,26,4,25,11,21,29,31,32};
        int capacity = 2, onTimePassengers = passengers.size(), lastBus;
        int noOfBusses = buses.size();

        sort(passengers.begin(),passengers.end());
        sort(buses.begin(),buses.end());

        lastBus = buses[noOfBusses-1];
        for(int i=0; i<onTimePassengers; i++){
            if(passengers[i] > lastBus) onTimePassengers = i;
        }
        cout<<onTimePassengers;
        // for(int i=onTimePassengers-1; i>=0; i--){
        //     if()
        // }

    }

    return 0;
}