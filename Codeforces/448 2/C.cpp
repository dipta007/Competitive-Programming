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

#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    bitFlip(a,k)      (a^(1<<(k)))

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

int a[100004];
int pp[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
int b[100004][10];
int n;
long long mod = 1e9+7;
long long dp[10004][(1<<4)+4];

long long call(int in, int mask)
{
    if(in >= n)
    {
        //cout << in << " " << mask << endl;
        return mask == 0;
    }

    long long ret = dp[in][mask];
    if(ret != -1) return ret;

    ret = 0;
    ret += call(in+1, mask);
    ret %= mod;
    int tmp = mask;
    for(int i=0; i<=8; i++)
    {
        if(bitCheck(tmp, i)==0 && b[in][i]%2==1) tmp = bitOn(tmp, i);
        else if(bitCheck(tmp,i)==1 && b[in][i]%2==1) tmp = bitOff(tmp, i);
    }

    if(b[in][9] == 0 ) 
        ret += call(in+1, tmp);
    ret %= mod;

    return ret;
}

#define MAX 1000005
long long MOD =1e9+7;
#define ll long long

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

int baki[] = {29,31, 37, 41, 43, 47, 53, 59, 61, 67,58, 62};

int main() {
   ios_base::sync_with_stdio(0);cin.tie(0);

    // int n;
   generate();
    while( cin >> n )
    {
        map <int, int> mp;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }

        memset(b, 0, sizeof b);
        for(int i=0;i<n;i++)
        {
            for(int j=0; j<=8; j++)
            {
                int cnt = 0;
                while(a[i] % pp[j]==0)
                {
                    a[i] /= pp[j];
                    cnt++;
                }

                b[i][j] = cnt;
                
            }
            if(a[i]!=1)
            {
                if(a[i]<29)
                {
                    for(int kk=0; kk<=8; kk++)
                    {
                        if(a[i]==pp[kk])
                        {
                            b[i][kk] += 1;
                        }
                    }
                }
                else b[i][9] = 1;
            } 
        }

        long long cnt = 0;
        memset(dp, -1, sizeof dp);

        cnt += (call(0,0)-1+mod)%mod;

        // long long way = cnt;

        for(int i=0; i<=11; i++)
        {
            int kk = baki[i];

            int mx = mp[kk];
            long long way = 0;
            for(int j=2; j<=mx; j+=2)
            {
                way += binomial(mx, j);
            }
            if(way==0) continue;
            //cout << cnt << endl;
            cnt += (cnt * way)%mod;
            cnt %= mod;
            cnt += way;
            cnt %= mod;
        }

        ;

        
        cnt %= mod;

        cout << cnt << endl;
        // printf("%lld\n", ;
    }

    return 0;
}


