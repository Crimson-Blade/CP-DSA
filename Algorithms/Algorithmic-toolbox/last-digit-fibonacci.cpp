#include <iostream>
using namespace std;

int main() {
  int n; // Number of fibonacci terms to display; n to be entered by the user
  int lastFibTerm = 0; // The last term in this sequence (considering the term before 1 to be 0)
  int currFibTerm = 1; // The current sum of all terms ie the new term in the sequence (The sum of first 1 term is 1)
  cin >> n;

  for (int i = 0; i < n; i++) {
    // cout << currFibTerm << " ";
    int temp = currFibTerm;
    currFibTerm += lastFibTerm; // Add the last term to the sum of the current digit to get the next term

    lastFibTerm = temp; // The last currFibTerm is the new last term'
    // Extracting Last digit
    lastFibTerm %= 10;
    currFibTerm %= 10;
  }

  cout << lastFibTerm << endl;

  return 0;
}