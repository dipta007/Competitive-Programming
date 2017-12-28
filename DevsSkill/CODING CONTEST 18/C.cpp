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

#define ll long long
#define mod 1006000007

ll bigMod(ll b, ll e)
{
    if(e==1) return b;
    if(e%2==0)
    {
        ll x = bigMod(b, e/2) %mod;
        x = x * x;
        x %= mod;

        return x;
    }
    else
    {
        ll x = bigMod(b, e-1) % mod;
        x *= b;
        x %= mod;

        return x;
   
    }
}

vector < ll > v;
int n;
ll dp[1004][1004];

ll call(int in, int cnt)
{
    if(in >= n) return 1;

    ll &ret = dp[in][cnt];
    if(ret!=-1) return ret;

    ret = call(in+1, cnt);
    ret += v[in] * call(in+1, cnt+1);
    ret %= mod;

    return ret;
}

int main() {

    int t;
    cin >> t;
    for(int ci=1; ci<=t; ci++)
    {
        cin >> n;

        // ll res = 0;

        v.clear();
        for(int i=1; i<=n; i++)
        {
            ll x;
            cin >> x;
            v.push_back(x);
        }

        memset(dp, -1, sizeof dp);

        ll res = call(0,0) - 1 + mod;
        res %= mod;
        printf("Case %d: %lld\n",ci, res);
    }

    return 0;
}


