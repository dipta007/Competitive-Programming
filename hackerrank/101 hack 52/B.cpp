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

#define ll long long

ll bigmod ( ll b, ll p, ll m ) {
    ll res = 1 % m, x = b % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1;
    }
    return res;
}

ll mod = 1e9 + 7;

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out
long countArray(int n, int k, int x) {
    // Return the number of ways to fill in the array.

    long ans = 1;
    if(n==3)
    {
        if(x==1) return k-1;
        else return k-2;
    }
    else
    {
        for(int i=2; i<n; i++)
        {
            if(i==n-1)
            {
                ans *= (k-2);
                ans %= mod;
            }
            else
            {
                ans *= (k-1);
                ans %= mod;
            }
        }

        ll now = bigmod(k-1,n-4, mod);
        now -= bigmod(k-1, n-5, mod);

        ans += now;
        ans %= mod;
        return ans;
    }

}

int nn,kk,xx;
ll dp[1004][104];

ll cntArray(int in, int last)
{
    //cout << in << " " << nn << endl;
    if(in==nn) 
    {
        if(last == xx) return 0;
        return 1;
    }

    ll &ret = dp[in][last];
    if(ret!=-1) return ret;
    

    ret = 0;
    for(int i=1; i<=kk; i++)
    {
        if(i==last) continue;
        ret += cntArray(in+1, i);
        ret %= mod;
    }
    return ret;
}

int main() {
    int n;
    int k;
    int x;
    while( cin >> n >> k >> x )
    {
        long answer = countArray(n, k, x);
        // if(x==1) answer++;
        nn = n;
        kk = k;
        xx = x;
        memset(dp, -1, sizeof dp);
        long bans = cntArray(2, 1);
        cout << answer << " " << bans << endl;
        // cout << bans << endl;
        // cout << answer << endl;
    }
    return 0;
}


