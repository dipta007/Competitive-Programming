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
#define pii pair <int, int>
#define ff first
#define ss second

pii add(pii a, pii b)
{
    pii tmp;
    tmp.ff = a.ff + b.ff;
    tmp.ss = a.ss + b.ss;
    return tmp;
}

int mark[54][2];
pii dp[54][2];
int n, a[54];

pii call(int in, int flg)
{
    if(in >= n) return make_pair(0,0);

    pii &ret = dp[in][flg];
    if(mark[in][flg]) return ret;
    mark[in][flg] = 1;

    if(flg==0)
    {
        pii p = add( make_pair(a[in], 0), call(in+1, !flg) );
        pii q = add( make_pair(0, a[in]), call(in+1, flg) );

        if(p.ff >= q.ff) return ret = p;
        else return ret = q;
    }
    else
    {
        pii p = add( make_pair(a[in], 0), call(in+1, flg) );
        pii q = add( make_pair(0, a[in]), call(in+1, !flg) );

        if(p.ss >= q.ss) return ret = p;
        else return ret = q;
    }
}

int main() {
//    ios_base::sync_with_stdio(0);cin.tie(0);

    while( cin >> n )
    {
        for(int i=0; i<n ;i++)
        {
            cin >> a[i];
        }

        memset(mark, 0, sizeof mark);
        pii res = call(0, 1);
        cout << res.ff << " " << res.ss << endl;
    }

    return 0;
}


