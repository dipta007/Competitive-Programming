
#include <iostream>
#include <iomanip>
using namespace std;
// Function prototypes

int sumsq(int);

int main()
{
 int n,sum;

   // Testing function sumsq(n)
 cout << "Testing function sumsq(n)"
      << endl;
 cout << "Enter a value for n: ";
 cin >> n;
 sum = sumsq(n);
 cout << "Sum of squares of first " << n
      << " integers is " << sum
      << endl;
 cout << "Tested"
      << endl;

} // End of main

// Function Definitions

int sumsq(int n)
  {
    int sum = 0;
    int i;
    for (i = 1; i <= n; i++)
        sum += i * i;

    return sum;
  } // End of sumsq
