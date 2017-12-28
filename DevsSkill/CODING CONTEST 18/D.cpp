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

#define MAX 1000005
#define MOD 1000000007

int fact[MAX], inv[MAX], inv2[MAX];

ll bigmod ( ll b, ll p, ll m ) {
    ll res = 1 % m, x = b % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1;
    }
    return res;
}
ll modularInverse(int a, int m) {
    return bigmod(a, m-2, m);
}

void generate(){
    int i, j;
    /// generating fact
    fact[0] = 1;
    for (i = 1; i < MAX; i++) fact[i] = ((long long)i * fact[i - 1]) % MOD;
    /// generating inv fact
    inv[MAX - 1] = modularInverse(fact[MAX-1], MOD);
    for (i = MAX - 2; i >= 0; i--)
        inv[i] = ((long long)inv[i + 1] * (i + 1)) % MOD;

    inv2[1] = 1;
    for (i = 2; i < MAX; i++){
        inv2[i] = MOD - ((MOD / i) * (long long)inv2[MOD % i]) % MOD;
        if (inv2[i] < 0) inv2[i] += MOD;
    }
}

long long binomial(int n, int k){
    if (k > n) return 0;
    return (((long long)fact[n] * inv[k] % MOD) * inv[n - k]) % MOD;
}

int main() {

    generate();

    int t;
    cin >> t;
    for(int ci=1;ci <=t; ci++)
    {
        int n;
        cin >> n;
        ll cnt = 1;
        for(int i=1; i<=n; i++)
        {
            int x;
            cin >> x;
            int kk = x - n;
            if(kk < 0)
            {
                cnt = 0;
            }
            else if(kk > 0)
            {
                //cout << kk << " " << n << endl;
                cnt *= (binomial(kk + n -1, kk));
                cnt %= MOD;            
            }
        }

        printf("Case %d: %lld\n",ci, cnt);
    }

    return 0;
}


