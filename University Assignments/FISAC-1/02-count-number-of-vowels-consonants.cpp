// Count the number of vowels and consonants in a string using pointers

#include <iostream>
using namespace std;

int solve(char *ptr)
{
    int vowels = 0, consonants = 0;
    while (*ptr != '\0')
    {
        if (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u' || *ptr == 'A' || *ptr == 'E' || *ptr == 'I' || *ptr == 'O' || *ptr == 'U')
        {
            vowels++;
        }
        else if (*ptr >= 'a' && *ptr <= 'z' || *ptr >= 'A' && *ptr <= 'Z')
        {
            consonants++;
        }
        ptr++;
    }
    cout << "Number of vowels: " << vowels << endl;
    cout << "Number of consonants: " << consonants << endl;
    return 0;
}
int main(){
    char str[100];
    cin.getline(str, 100);
    solve(str);
}