#include <iostream>
#include <fstream>
#include <map>
using namespace std;
int main(){
    int sum=0;
    string line;
    ifstream myFile("input.txt");
    //PART1
    if(myFile.is_open()){
        while(getline(myFile,line)){
            string comp1,comp2;
            comp1 = line.substr(0,line.length()/2);
            comp2 = line.substr(line.length()/2);
            map<char,int> accounted;
            for(char c1:comp1){
                for(char c2:comp2){
                    if(c1 == c2 && accounted[c1]==0){
                        // cout<<c1;
                        sum += (isupper(c1) > 0)?(c1-38):(c1-96);
                        accounted[c1]++;
                    }
                }
            }
        }
        cout<<sum;
        myFile.close();
    }
    // Part2
    if(myFile.is_open()){
        for(int i=0;i<100;i++){
            string comp1,comp2,comp3;
            getline(myFile,comp1);
            getline(myFile,comp2);
            getline(myFile,comp3);
            map<char,int> accounted;
            for(char c1:comp1){
                for(char c2:comp2){
                    if(c1 == c2 && accounted[c1]==0){
                        for(char c3:comp3){
                            if(c1 == c3 && accounted[c1]==0){
                                // cout<<c3;
                                sum += (isupper(c1) > 0)?(c1-38):(c1-96);
                                accounted[c1]++;
                            }
                        }
                    }
                }
            }
        }
        cout<<sum;
        myFile.close();
    }
}