#include <bits/stdc++.h>
//make sure to include the random number generators and such
#include <random>
using namespace std;
int main(){
    // the random device that will seed the generator
    std::random_device seeder;
    // then make a mersenne twister engine
    std::mt19937 engine(seeder());
    // then the easy part... the distribution
    std::uniform_int_distribution<int> dist(1, 2);
    // then just generate the integer like this:
    srand(time(0));
    int len = 10;
    string s;
    for (int i = 0; i < len; i++)
    {
    int compGuess = dist(engine);
        if (compGuess == 1)
            s.append("a");
        else
            s.append("b");
    }
    cout<<s;

    return 0;
}