#include <iostream>
using namespace std;
void f(int *a,int *b){
    *b=*a;
    *a=*b;
}  
int main(){
    int a=10,b=20;
    f(&a,&b);
    cout<<a<<b;
}