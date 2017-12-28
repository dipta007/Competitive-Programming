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
//    ios_base::sync_with_stdio(0);cin.tie(0);
    int k;
    while( cin >> k )
    {
        int kk = k - 1;
        long sum = 0;
        for(int i=1; i<=kk; i++)
        {
            sum += i;
        }

        sum++;

        long odd = sum *2LL - 1;

        long res = 0;
        for(int i=0, j=1; j<=k; i+=2, j++)
        {
            res += i;
        }
        res += (odd * k);
        cout << res << endl;
    }

    return 0;
}


