#include <iostream>
using namespace std;

int main() {
  int n; // Number of fibonacci terms to display; n to be entered by the user
  int lastFibTerm = 0; // The last term in this sequence (considering the term before 1 to be 0)
  int fibSum = 1; // The current sum of all terms ie the new term in the sequence (The sum of first 1 term is 1)
  cin >> n;

  for (int i = 0; i < n; i++) {
    // cout << fibSum << " ";
    fibSum += lastFibTerm; // Add the last term to the sum of the current digit to get the next term

    lastFibTerm = fibSum - lastFibTerm; // The last fibsum is the new last term
  }
  cout << lastFibTerm << endl;

  return 0;
}