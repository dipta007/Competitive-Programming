#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define CLR(a) memset(a, 0, sizeof(a))

const int SZ = 1e5+4;
ll forwardHashTable[2][SZ];
ll backwardHashTable[2][SZ];
ll power[2][SZ];

class Hashing
{
    const long long mod[2] = {1000000007LL, 2117566807LL};
    const long long base[2] = {1572872831LL, 1971536491LL};
public:
    Hashing()
    {
        power[0][0]=1;
        power[1][0]=1;
        for(int i=0;i<2;i++)
        {
            for(int j=1;j<SZ;j++)
            {
                power[i][j] = (power[i][j-1] * base[i]) % mod[i];
            }
        }
    }

    ll MOD(ll x, int index)
    {
        return (x%mod[index]+mod[index])%mod[index];
    }

    void makeForwardHashTable(string st)
    {
        CLR(forwardHashTable);
        int len = st.size();

        for(int in=0; in<2; in++)
        {
            for(int i=0;i<len;i++)
            {
                int kk = st[i] - ' ';
                if(i)
                {
                    forwardHashTable[in][i] = ((forwardHashTable[in][i-1]*base[in])%mod[in] + kk)%mod[in];
                    continue;
                }
                forwardHashTable[in][i] = kk;
            }
        }
    }

    ll getForwardHashingQuery(int left, int right)
    {
        if(left==0)
        {
            return (forwardHashTable[0][right] << 31) | forwardHashTable[1][right];
        }
        ll ret1 = MOD(forwardHashTable[0][right] - (forwardHashTable[0][left-1] * power[0][right-left+1])%mod[0] , 0);
        ll ret2 = MOD(forwardHashTable[1][right] - (forwardHashTable[1][left-1] * power[1][right-left+1])%mod[1] , 1);
        ll ret = (ret1 << 31) | ret2;
        return ret;
    }
};

string maximumPermutation(string w, string s) {
    // Return the string representing the answer.

    Hashing helper;
    helper.makeForwardHashTable(s);

    int mark[27];
    memset(mark, 0, sizeof mark);

    for(int i=0; i<w.size(); i++)
    {
        int kk = w[i] - 'a';
        mark[kk] ++;
    }

    int cum[26][s.size()+4];
    for(int i=0; i<s.size()-1; i++)
    {
        int kk = s[i] - 'a';
        for(int j=0; j<=25; j++)
        {
            cum[j][i+1] = cum[j][i];
        }
        cum[kk][i+1]++;
    }


    map <long long ,int > mp;
    for(int i=1; i<=s.size()-w.size()+1; i++)
    {
        int r = i+w.size() - 1;
        int flg = 1;
        for(int j=0; j<25; j++)
        {
            if(cum[j][r] - cum[j][i-1] != mark[j])
            {
                flg = 0;
                break;
            }
        }

        if(flg)
        {
            ll val = helper.getForwardHashingQuery(i-1, i+w.size()-2);
            mp[val] ++;
        }
    }

    int maxy = 0;
    long long ans;
    for(auto x: mp)
    {
        if(x.second > maxy)
        {
            maxy = x.second;
            ans = x.first;
        }
    }

    string res = "-1";
    for(int i=0; i<s.size(); i++)
    {
        string tmp = s.substr(i, w.size());
        if(res == "-1") tmp = "A";
        if(helper.getForwardHashingQuery(i, i+w.size()-1) == ans &&  tmp < res)
        {
            res = tmp;
        }
    }
    return res;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int t;
    cin >> t;
    for(int ci=1;ci<=t; ci++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << maximumPermutation(s1, s2) << endl;
    }

    return 0;
}
