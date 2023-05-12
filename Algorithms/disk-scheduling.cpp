#include<bits/stdc++.h>
#include<utility>
#include<algorithm>
#include <vector>
using namespace std;

void fcfs(int arr[], int n, int in){
    int sum=0;
    sum+=abs(in-arr[0]);
    for(int i=0;i<n-1;i++){
        cout<<arr[i]<<" ------ "<<arr[i+1]<<endl;
        sum+=abs(arr[i]-arr[i+1]);
    }
    cout<<"Total sum using fcfs: "<<sum<<endl;
}


void sstf(int arr[], int n, int in){
    int sum=0;
    sort(arr, arr+n);
    sum+=abs(in-arr[0]);
    for(int i=0;i<n-1;i++){
        cout<<arr[i]<<" ------------ "<<arr[i+1]<<endl;
        sum+=abs(arr[i] - arr[i+1]);
    }
    cout<<"Total sum using sstf: "<<sum<<endl;
}

int index(vector<int> ref, int in){
    for(int i=0; i<ref.size(); i++){
        if(ref[i] == in){
            return i;
        }
    }
}

void scan(vector<int> ref, int in, char ch){
    vector<pair<int,int>> arr;
    int sum = 0;
    ref.push_back(in);
    sort(ref.begin(), ref.end());
    int ind = index(ref, in);
    if(ch=='l'){
        for(int i=ind;i>0;i--){
            arr.push_back({ref[i], ref[i-1]});
        }
        arr.push_back({ref[0], 0}); // DIFF BETQWEEN CSCAN AND SCAN
        arr.push_back({0, ref[ind+1]});
        for(int i=ind+1;i<ref.size()-1;i++){
            arr.push_back({ref[i], ref[i+1]});
        }
        for(int i=0;i<arr.size();i++){
            cout<<arr[i].first<<" --- "<<arr[i].second<<endl;
            sum+=abs(arr[i].first - arr[i].second);
        }
        cout<<"Total Head Moment: "<<sum<<endl;
        
    }
    else{
        for(int i=ind;i<ref.size()-1;i++){
            arr.push_back({ref[i], ref[i+1]});
        }
        arr.push_back({ref[ref.size()-1], 199});
        arr.push_back({199, ref[ind-1]});
        for(int i=ind-1;i>0;i--){
            arr.push_back({ref[i], ref[i-1]});
        }
        for(int i=0;i<arr.size();i++){
            cout<<arr[i].first<<" --- "<<arr[i].second<<endl;
            sum+=abs(arr[i].first - arr[i].second);
        }
        cout<<"Total Head Moment: "<<sum<<endl;
    }
}

void cscan(vector <int> ref, int in, char ch){
    
    ref.push_back(in);
    sort(ref.begin(), ref.end());
    int ind = index(ref, in);
    int sum = 0;
    vector<pair<int, int>> arr;
    if(ch=='l'){
        for(int i=ind; i>0;i--){
            arr.push_back({ref[i], ref[i-1]});
        }
        arr.push_back({ref[0], 0});
        arr.push_back({0, 199});
        arr.push_back({199, ref[ref.size()-1]});
        for(int i=ref.size()-1; i>ind+1;i--){
            arr.push_back({ref[i], ref[i-1]});
        }
        for(int i=0;i<arr.size();i++){
            cout<<arr[i].first<<"---"<<arr[i].second<<endl;
            sum+=abs(arr[i].first - arr[i].second);
        }
        cout<<"Sum: "<<sum<<endl;
    }
    else{
        for(int i= ind; i<ref.size() -1; i++){
            arr.push_back({ref[i], ref[i+1]});
        }
        arr.push_back({ref[ref.size()-1], 199});
        arr.push_back({199, 0});
        arr.push_back({0, ref[0]});
        for(int i=0; i<ind-1; i++){
            arr.push_back({ref[i], ref[i+1]});
        }
        for(int i=0; i<arr.size(); i++){
            cout<<arr[i].first<<"---"<<arr[i].second<<endl;
            sum+=abs(arr[i].first - arr[i].second);
        }
        cout<<"Total head count is : "<<sum<<endl;
    }

}

int main(){
    int n=8;
    int arr[n] ={176, 79, 34, 60, 92, 11, 41, 114};
    vector <int> ref = {176, 79, 34, 60, 92, 11, 41, 114};
    // fcfs(arr, n, 50);
    sstf(arr, n, 50);
    // scan(ref, 50, 'l');
    // cscan(ref, 50, 'l');
    return 0;
}