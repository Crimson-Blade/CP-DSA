#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;
 
// function to print string in sorted order
void sortString(string &str)
{
    int charIndex = 0;
    // Hash array to keep count of characters.
    // Initially count of all characters is
    // initialized to zero.
    int charCount[MAX_CHAR] = {0};
     
    // Traverse string and increment
    // count of characters
    for (int i=0; i<str.length(); i++)
 
        // 'a'-'a' will be 0, 'b'-'a' will be 1,
        // so for location of character in count
        // array we will do str[i]-'a'.
        charCount[str[i]-'a']++;   
     
    // Traverse the hash array and print
    // characters
    for (int i=0;i<MAX_CHAR;i++)
        for (int j=0;j<charCount[i];j++){
            str[charIndex] =(char)('a'+i);
            charIndex++;
        }
}
int main(){
    int t;
    cin>>t;
    while (t>0){
        int len,countMatch=0;
        string str,strSorted;
        cin>>len;
        cin>>str;
        strSorted = str;
        sortString(strSorted);

        //Traversing both strings (as character arrays) and comparing, a match increases the counter
        for (int i=0; i<str.length(); i++){
            if(str[i]==strSorted[i])
                countMatch++;
        }

        //Number of characters to be selected for permutation = length of string - number of characters that matched
        cout<<str.length()-countMatch<<"\n";

        t--;
    }
    return 0;
}
