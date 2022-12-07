#include <iostream>
using namespace std;
//MERGE SORT
/**
 * Sort an array using merge sort
 * @param s Start index
 * @param e End index
 * 
 */
void merge(int arr[],int s,int e){
    
    //Finding mid element
    int mid = (s+e)/2;

    //Finding length of LEFT and RIGHT Array
    int len1 = mid - s + 1;
    int len2 = e - mid;

    //Creating FIRST and SECOND array
    int *first = new int[len1];
    int *second = new int[len2];

    //copy values from MAIN to FIRS
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    //copy values from MAIN to SECOND
    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted arrays     
    int index1 = 0; //to traverse FIRST array
    int index2 = 0; //to traverse Second array
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) {
        // COpying value whichever is Small
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }   
    //If len 1 is more than len2s
    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }
    //if len2 is more than len 1
    while(index2 < len2 ) {
        arr[mainArrayIndex++] = second[index2++];
    }
    // Deleting created arrays
    delete []first;
    delete []second;
}
void mergeSort(int arr[],int s,int e){
    //base case
     if(s>=e){
        return ;
    }
        
    //Finding MID element
    int mid=(s+e)/2;
    
    //Sort Left Part
    mergeSort(arr,s,mid);

    //Sort Right Part
    mergeSort(arr,mid+1,e);

    // Merge both the parts
    merge(arr,s,e);

}
int main(){
    int arr[6]={-1,3,2,1,5,4};
    int n=6;
    // quickSort(arr,0,n-1);
    mergeSort(arr,0,n-1);
    //FOr Applying Heap SOrt arr[0] should be random(-1) and n should be last index numbers(1 based indexing)
    //heapsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
