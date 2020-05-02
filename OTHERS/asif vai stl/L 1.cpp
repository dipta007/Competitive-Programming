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

#define F(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define ALL(p) p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)

#define ff first
#define ss second
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >
#define vi vector < int >
#define vii vector < vector < int > >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
#define PI 3.1415926535897932384626

int main() {
    int t;
    scanf("%d\n",&t);
    for(int C=0;C<t;C++)
    {
        if(C!=0)
            printf("\n");
        map < string , string > m;
        map < string , int > mn;
        int n;
        scanf("%d\n",&n);
//        getchar();
        for(int i=0;i<n;i++)
        {
            string a,b;
            getline(cin,a);
            getline(cin,b);
            m[a]=b;
        }
        int v;
        scanf("%d\n",&v);
//        getchar();
        for(int i=0;i<v;i++)
        {
            string a;
            getline(cin,a);
            if(m.count(a)>0)
                mn[a]++;
        }
        map <string , int > :: iterator it;
        int mx;
        for(it=mn.begin();it!=mn.end();it++)
        {
            if(it==mn.begin())
                mx=it->second;
            else
                mx=max(mx,it->second);
        }
        int cnt=0;
        string a;
        for(it=mn.begin();it!=mn.end();it++)
        {
            if(mx==it->second)
            {
                cnt++;
                a=it->first;
            }
        }
        if(cnt==1)
        {
            printf("%s\n",m[a].c_str());
        }
        else
            printf("tie\n");

    }
}

