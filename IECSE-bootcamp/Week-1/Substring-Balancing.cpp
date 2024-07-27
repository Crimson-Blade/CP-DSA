#include <bits/stdc++.h>
#include <random>
using namespace std;

string generateInput()
{
    // make sure to include the random number generators and such
    // the random device that will seed the generator
    std::random_device seeder;
    // then make a mersenne twister engine
    std::mt19937 engine(seeder());
    // then the easy part... the distribution
    std::uniform_int_distribution<int> dist(1, 2);
    std::uniform_int_distribution<int> len(1, 1000);
    // then just generate the integer like this:
    srand(time(0));
    string s;
    for (int i = 0; i < len(engine); i++)
    {
        int compGuess = dist(engine);
        if (compGuess == 1)
            s.append("a");
        else
            s.append("b");
    }
    return s;
}
int main()
{
    int AB = 0;
    int BA = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; // test cases
    cin >> t;
    while (t > 0)
    {

        string str = generateInput();
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == 'a' && str[i + 1] == 'b')
                AB++;
            if (str[i] == 'b' && str[i + 1] == 'a')
                BA++;
        }
        if (AB == BA)
            ;
        else if (AB > BA)
        {
            if (str[0] == 'a' && str[1] == 'b')
            {
                str[0] = 'b';
            }
            else if (str[0] == 'a' && str[1] == 'a')
            {
                str[0] = 'b';
            }
            else if (str[str.length() - 2] == 'a' && str[str.length() - 1] == 'b')
            {
                str[str.length() - 1] == 'a';
            }
            else if (str[str.length() - 2] == 'b' && str[str.length() - 1] == 'b')
            {
                str[str.length() - 1] == 'a';
            }
        }
        else if (AB < BA)
        {
            if (str[0] == 'b' && str[1] == 'a')
            {
                str[0] = 'a';
            }
            else if (str[0] == 'b' && str[1] == 'b')
            {
                str[0] = 'a';
            }
            else if (str[str.length() - 2] == 'b' && str[str.length() - 1] == 'a')
            {
                str[str.length() - 1] == 'b';
            }
            else if (str[str.length() - 2] == 'a' && str[str.length() - 1] == 'a')
            {
                str[str.length() - 1] == 'b';
            }
        }
        // DELETE bellow
        // AB = BA = 0;
        // for (int i = 0; i < str.length(); i++)
        // {
        //     if (str[i] == 'a' && str[i + 1] == 'b')
        //         AB++;
        //     if (str[i] == 'b' && str[i + 1] == 'a')
        //         BA++;
        // }
        // if (AB != BA)
        //     cout << "Wrong";
        // cout << "AB " << AB << "\n";
        // cout << "BA " << BA << "\n";
        // Delete above
        cout << str << "\n";
        t--;
    }

    return 0;
}