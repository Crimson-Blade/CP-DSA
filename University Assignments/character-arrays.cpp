#include <iostream>
using namespace std;
int main(){
    // array of strings
    char *str[4] = {"Geeks", "for", "Geeks", "A computer portal"};
    // print the strings
    for (int i = 0; i < 4; i++)
        cout << str[i] << " ";
    //array of strings part 2
    char *str1[3];
    str1[0] = "lol";
    str1[2] = "rofl";
    str1[1] = "lmaoooooooooooooooooooooo";
    // print the strings
    for (int i = 0; i < 3; i++)
        cout << &str1[i] << " ";
}