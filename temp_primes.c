#include <stdio.h>
#include <math.h>
int main(){
    int arr[100] = {0},i,j;
    arr[0]=arr[1]=1;
    for( i=2;i<100;i++){
        if(arr[i] % 2 == 0){
            for(j = 2*i; j<100; j += i){
                arr[j]=1;
            }
        }
    }
    for( i=2;i<100;i++){
        if(arr[i] == 0)
        printf("%d ",i);
    }
}