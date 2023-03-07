#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void max_container(vector<int> wt, int c)
{
  // size of array
  int n = wt.size();
    int count = 0;
    int cap=0,pos; // pos is the position of the minimum weight // cap is the capacity of the container
        sort(wt.begin(),wt.end());
    for(int j:wt)
    {
        cap+=j;
            if(cap<=c){
                count++;
            }
            else{
                break;
            }
    }
    cout<<"Maximum no. of containers loaded is "<<count;
}
int main()
{
    vector<int> wt={5,8,3,8,18,3,7,6};
    int c = 40;
    max_container(wt,c);
    return 0;
}
