#include <algorithm>
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

class IncreasingSequencesEasy
{
public:
    ll mod = 998244353;
    ll dp[304][10016];

    ll call(vector <int> &l, vector <int> &r, int in, int last)
    {
        if(in >= l.size() - 1)
        {
            int kk = r[in] - last + 1;
            if(kk < 0) return 0;
            return kk;
        }

        ll &ret = dp[in][last];
        if(ret!=-1) return ret;

        ret = 0;
        for(int i=last; i<=r[in]; i++)
        {
            int kk = max(i+1, l[in+1]);
            ll now = call(l, r, in+1, kk);
            dp[in][i] = now;
        }

        for(int i=r[in]; i>=last; i--)
        {
            if(dp[in][i+1] != -1)
            {
                dp[in][i] += dp[in][i+1];
                dp[in][i] %= mod;
            }
        }
        return dp[in][last];
    }

	int count(vector <int> l, vector <int> r)
    {
        memset(dp, -1, sizeof dp);
        return call(l,r, 0, l[0]);
    }
};
