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

int check(int n)
{
    int even = 0;
    int odd = 0;
    while(n)
    {
        int kk = n%10;
        n/=10;

        if(kk%2==0) even += kk;
        else odd += kk;
    }

    return abs(even - odd);
}

int main() {
   ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    for(int ci=1; ci<=t; ci++)
    {
        int n;
        cin >> n;

        long long res = 0;
        int i;
        for(i=2; i<=n+1; i++)
        {
            res += (long long) check(i) * min(i-1, n);
        }

        //cout << res << endl;

        int baki = n-1;
        for(i=n+2; i<=n+n; i++, baki--)
        {
            res += (long long) check(i) * min(n, baki);
        }

        cout << res << endl;
    }

    return 0;
}


