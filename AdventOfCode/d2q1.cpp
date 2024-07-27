#include <iostream>
#include <fstream>
#include <map>
using namespace std;
int main(){
    int score=0;
    string line;
    ifstream myFile("d2q1.txt");
    map<char,int> weight={
        {'A',1},
        {'X',1},
        {'B',2},
        {'Y',2},
        {'C',3},
        {'Z',3}
        };
    map<int,int> roundScores={
        {0,3},
        {-1,6},
        {-2,0},
        {1,0},
        {2,6}
    };

    //Part1
    if(myFile.is_open()){
        while(getline(myFile,line)){
            // cout<< line.length() << '\n';
            score += weight[line[2]] + roundScores[weight[line[0]] - weight[line[2]]];
        }
        myFile.close();
    }
    cout<<score;
    // Part2
    if(myFile.is_open()){
        while(getline(myFile,line)){
            int a=weight[line[0]],b=weight[line[2]];
            if(b == 2) 
                score+=a + 3;
            else if(b == 1){
                score+= (a - 1)?a-1:3;
            }
            else 
                score+= (a)%3 + 1 + 6;
        }
        myFile.close();
    }
    cout<<score;
    return 0;
}