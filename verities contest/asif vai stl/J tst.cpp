#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    string moves = "ABC";
    //sort(moves.begin(), moves.end());

    while (next_permutation(moves.begin(), moves.end()) )
    {
        cout << moves << endl;
    }
}

