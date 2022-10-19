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
void slowTranspose(Sparse a[],Sparse aT[]){
    int k=1;
    aT[0].r = a[0].c;
    aT[0].c = a[0].r;
    aT[0].v = a[0].v;
    for(int i=0;i<a[0].c;i++){
        for(int j=1;j<=a[0].v;j++){
            if(i == a[j].c){
                aT[k].r = a[j].c;
                aT[k].c = a[j].r;
                aT[k].v = a[j].v;
                k++;
            }
        }
    }
}
void fastTranspose(Sparse a[],Sparse aT[]){
    aT[0].r = a[0].c;
    aT[0].c = a[0].r;
    aT[0].v = a[0].v;
    int startIndex[a[0].c] = {0};
    int colFreq[a[0].c] = {0};
    for(int i=1;i<=a[0].v;i++){
        colFreq[a[i].c]++; 
    }
    startIndex[0] = 1;
    for(int i=1;i<a[0].v;i++){
        startIndex[i] = startIndex[i-1] + colFreq[i-1];
    }
    for(int i=1;i<=a[0].v;i++){
        aT[startIndex[a[i].c]].c = a[i].r;
        aT[startIndex[a[i].c]].r = a[i].c;
        aT[startIndex[a[i].c]].v = a[i].v;
    }


}

int main(){
    Sparse a[100];
    Sparse aT[100];
    Sparse aTT[100];
    int m,n;
    cin>>m>>n;
    read(a,m,n);
    display(a);
    slowTranspose(a,aT);
    display(aT);
    fastTranspose(aT,aTT);
    display(aTT);
}
