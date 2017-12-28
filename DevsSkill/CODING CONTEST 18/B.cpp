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

    int t;
    cin >> t;
    for(int ci=1; ci<=t; ci++)
    {
        int n;
        cin >> n;
        string st;
        cin >> st;

        int lft[n+4], rgt[n+4];

        memset(lft, 0, sizeof lft);
        memset(rgt, 0, sizeof rgt);

        for(int i=1; i<n; i++)
        {
            if(st[i]=='1' && st[i-1]=='0')
            {
                lft[i] += lft[i-1] + 1;
            }
            else lft[i] += lft[i-1];
        }

        for(int i=n-2; i>=0; i--)
        {
            if(st[i]=='0' && st[i+1]=='1')
            {
                rgt[i] += rgt[i+1] + 1;
            }
            else rgt[i] += rgt[i+1];
        }

        long long cnt = 0;
        for(int i=1; i<n;i++)
        {
            if(st[i]=='0' && st[i-1]=='1')
            {
                if(i-2 >= 0)
                {
                    cnt += lft[i-2];
                }

                if(i+1 < n)
                {
                    cnt += rgt[i+1];
                }
            }
        }

        printf("%lld\n", cnt);
    }

    return 0;
}


