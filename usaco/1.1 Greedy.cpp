/*
ID: iamdipt
PROG: gift1
LANG: C++
*/

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
    READ("gift1.in");
    WRITE("gift1.out");
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        getchar();
        map <string , int> ix,fx;
        map <int,string> it;
        for(int i=0;i<n;i++)
        {
            string s1;
            getline(cin,s1);
            ix[s1]=0;
            fx[s1]=0;
            it[i]=s1;
        }
        for(int i=0;i<n;i++)
        {
            string s1;
            getline(cin,s1);
            int l,k;
            scanf("%d %d",&l,&k);
            getchar();
            ix[s1]=l;
            int tk;
            if(k!=0)
                tk=l/k;
            for(int j=0;j<k;j++)
            {
                string s2;
                getline(cin,s2);
                fx[s2]=fx[s2]+tk;
            }
            tk=ix[s1]-(tk*k);
            fx[s1]=fx[s1]+tk;
        }
        for(int i=0;i<n;i++)
        {
            printf("%s %d\n",it[i].c_str(),fx[it[i]]-ix[it[i]]);
        }
    }
    return 0;
}

