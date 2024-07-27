#include<iostream>
using namespace std;
//QUICK SORT
int partition(int arr[],int s,int e){
    //Make First element as pivot element
    int pivotElement=arr[s];
    int count=0;
    
    // Finding number of elements less than equal to pivot element to place at correct position
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivotElement)
            count++;
    }
    //Place Pivot Element at Correct position
    int pivotIndex=s+count;
    swap(arr[pivotIndex],arr[s]);

    // Create left part all small elements and right parts large elements'
    int i=s,j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivotElement){
            i++;

        }
            
        while (arr[j]>pivotElement)
        {
            j--;
        }
        if(i<pivotIndex && j>pivotIndex)
            swap(arr[i++],arr[j--]);
        
    }
    return pivotIndex;

}
void quickSort(int arr[],int s,int e){
    //base case
    if(s>=e)
        return ;

    // Create Partition
    int p=partition(arr,s,e);

    //Sort the Left Part
    quickSort(arr,s,p-1);

    //Sort Right Part
    quickSort(arr,p+1,e);
}

int main(){
    int arr[6]={-1,3,2,1,5,4};
    int n=6;
    quickSort(arr,0,n-1);
    //mergeSort(arr,0,n-1);
    //FOr Applying Heap SOrt arr[0] should be random(-1) and n should be last index numbers(1 based indexing)
    //heapsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}