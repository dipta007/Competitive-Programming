#pragma comment(linker, "/stack:640000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;


// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

int main() {
   ios_base::sync_with_stdio(0);cin.tie(0);

   int a[6][6];
   for(int i=0; i<6; i++)
   {
        for(int j=0; j<6; j++)
        {
            cin >> a[i][j];
        }
   }

   int maxy = -1000000;
   for(int i=0; i<=3; i++)
   {
        // int sum = 0;
        for(int j=0; j<=3; j++)
        {
            int sum = 0;
            sum += a[i][j];
            sum += a[i][j+1];
            sum += a[i][j+2];

            sum += a[i+1][j+1];

            sum += a[i+2][j];
            sum += a[i+2][j+1];
            sum += a[i+2][j+2];

            maxy = max(sum, maxy);
        }
   }

   cout << maxy << endl;

    return 0;
}


