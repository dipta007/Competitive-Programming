#define ONLINE_JUDGE 1
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

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

int tt;
long long dp[20][2];
int vis[20][2];
int len;
vector < int > v;
int k;

ll pwr[11][22];

ll bigmod ( ll b, ll p) {
    ll res = 1, x = b;
    while ( p ) {
        if ( p & 1 ) res = ( res * x );
        x = ( x * x );
        p >>= 1;
    }
    return res;
}

long long call(int in, bool isLow)
{
    if(in >= len)
    {
        return 1;
    }

    long long &ret = dp[in][isLow];
    int &ntt = vis[in][isLow];

    if(ntt == tt) return ret;
    ntt = tt;

    if(isLow)
    {
        int baki = len - in;
        return ret = pwr[k][baki];
    }

    int end;
    end = (isLow == 1) ? k-1 : min(v[in], k-1);

    ret = 0;
    // if(1)
    // {
        for(int i=0; i<=end; i++)
        {
            ret += call(in+1, isLow || (i < v[in]));
        }
    // }
    return ret;
}

long long cal(long long x)
{
    len = 0;
    v.clear();
    while(x)
    {
        int kk = x%10;
        x/=10;
        v.push_back(kk);
        len ++;
    }
    reverse(v.begin(), v.end());

    tt++;
    //cout << tt << endl;
    return call(0, 0);
}


int main() {

    pwr[0][0] = 1;
    for(int i=1; i<=10; i++) pwr[0][i] = 1;
    for(int i=1; i<=10; i++)
    {
        pwr[i][0]=1;
        for(int j=1; j<=20; j++)
        {
            pwr[i][j] = pwr[i][j-1] * i;
        }
    }
    int t;
    scanf("%d",&t);
    tt = 0;
    for(int ci=1;ci<=t;ci++)
    {
        long long a, b;
        scanf("%lld %lld %d",&a, &b, &k);

        //cout << a << b << k << endl;
        if(a==0)
        {
            //cout << "1" << endl;
            printf("%lld\n", cal(b));
        }
        else
        {
            //cout << "2" << endl;
            printf("%lld\n", cal(b) - cal(a-1));
        }
    }

    return 0;
}


