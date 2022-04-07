#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
        cin>>N;
        //Input given arr
        int arr[N];
        for(int i=0;i<N;i++)
            cin>>arr[i];

int number = arr[0];
int mode = number;
int count = 1;
int countMode = 1;

for (int i=1; i<N; i++)
{
      if (arr[i] == number) 
      { // count occurrences of the current number
         ++count;
      }
      else
      { // now this is a different number
            if (count > countMode) 
            {
                  countMode = count; // mode is the biggest ocurrences
                  mode = number;
            }
           count = 1; // reset count for the new number
           number = arr[i];
  }
}

cout << "mode : " << mode << endl;
}