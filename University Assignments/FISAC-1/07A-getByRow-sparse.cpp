/*
Write the code snippet for the getByRow method,
 which returns the value in the matrix at the specified row and column by 
 traversing the matrix along the list corresponding to the specified row. 
(Of course, if the needed object does not exist in the list, the value must be -1.)
*/

#include <iostream>
using namespace std;
class Sparse{
    public:
    int r,c,v;
};
void read(Sparse a[],int m,int n){
    a[0].r = m;
    a[0].c = n;
    int k = 1;
    for(int i =0;i< m; i++){
        for(int j =0;j< n; j++){
        
            int temp;
            cin>>temp;
            if(temp != 0){
                a[k].r = i;
                a[k].c = j;
                a[k].v = temp;
                k++;
            }
        }
    }
    a[0].v = k-1;
}
void display(Sparse a[]){
    cout<<"R  C  V"<<endl;
    int k = a[0].v;
    for(int i =0;i <= k; i++){
        cout<<a[i].r<<"  "<<a[i].c<<"  "<<a[i].v<<"  "<<endl;
    }
    cout<<endl;
}
// 7A
int getByRow(Sparse a[],int r,int c){
    int k = a[0].v;
    for(int i =1;i <= k; i++){
        if(r == a[i].r && c == a[i].c) return a[i].v;
    }
    return -1;
}
// 7B
int getNumElementsInColumn(Sparse a[],int c){
    int k = a[0].v, colCount=0;
    for(int i =1;i <= k; i++)
        if(c == a[i].c) colCount++;
    return colCount;
}
int main(){
    Sparse a[100];
    int m,n;
    cin>>m>>n;
    read(a,m,n);
    // display(a);
    cout<<getByRow(a,2,2)<<endl;
    cout<<getNumElementsInColumn(a,1)<<endl;

}