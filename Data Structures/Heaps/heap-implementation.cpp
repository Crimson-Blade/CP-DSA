#include <iostream>
using namespace std;
namespace max_heap{
    void insert(int a, int arr[],int n){
        arr[n] = a;
        int index = n;
        while(index > 0){
            if(arr[index/2] < arr[index])
              swap(arr[index/2],arr[index]);
            index/=2;
        }
    }
    int delete_root(int arr[],int n){
        int a = arr[0];
        arr[0] = arr[n-1];
        arr[n-1] = 0;
        int index = n-1;
        while(index > 0){
            if(arr[index/2] < arr[index])
              swap(arr[index/2],arr[index]);
            index/=2;
        }
        return a;
    }
    void sort_heap(int arr[],int n){
        for(int i=0;i<n;i++){
            arr[n-i-1] = delete_root(arr,n-i);
        }
    }
}

int main(){
    int arr[100] = {50,30,20,15,10,8,16};
    // max_heap::insert(60,arr,7);
    // for(auto a:arr) cout<<a<<" ";
    // cout<<max_heap::delete_root(arr,7)<<endl;
    max_heap::sort_heap(arr,7);
    for(auto a:arr) cout<<a<<" ";

}
