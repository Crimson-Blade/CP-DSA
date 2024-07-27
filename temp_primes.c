#include <stdio.h>
#include <string.h>
int main(){
    char carr[100][100];
    int i;
    for(int i=0; i<1;i++){
        gets(carr[i]);
    }
    for(int i=0; i<1;i++)
        puts(carr[i]);
    for(i=0;i<strlen(carr[0]);i++){
        char t;
        if(strcmp(&carr[0][i],&carr[0][i+1])>0){
        // strcpy(&t,&carr[0][i]);
        // strcpy(&carr[0][i],&carr[0][i+1]);
        // strcpy(&carr[0][i+1],&t);
        t = carr[0][i];
        carr[0][i] = carr[0][i+1];
        carr[0][i+1] = t;
        }
    }
    for(int i=0; i<1;i++)
        puts(carr[i]);
}