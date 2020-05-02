
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

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)
#define    bitCheck(N,in)    ((bool)(a&(1<<(k))))
#define    bitOff(N,in)      (a&(~(1<<(k))))
#define    bitOn(N,in)       (a|(1<<(k)))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long

template< class T > inline T _abs(T n)
{
    return ((n) < 0 ? -(n) : (n));
}
template< class T > inline T _max(T a, T b)
{
    return (!((a)<(b))?(a):(b));
}
template< class T > inline T _min(T a, T b)
{
    return (((a)<(b))?(a):(b));
}
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

#ifdef dipta007
#define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;

vii adjlist;

map <string, int> mp;
map <int, string> mps;

#define NODE 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int disc[NODE], low[NODE];
int vis[NODE];
int globalCnt = 0;
int flg;

vector<int> tarjan;

int cycle[NODE];

int SCC ( int s )
{
    vis[s] = GRAY;
    disc[s] = low[s] = globalCnt++;
    tarjan.push_back(s);

    for ( int i = 0; i < adjlist[s].size(); i++ )
    {
        int t = adjlist[s][i];

        if ( vis[t] == WHITE )   ///This is tree edge
        {
            SCC ( t );
            low[s] = min ( low[s], low[t] );
        }
        else if ( vis[t] == GRAY )   ///This is back edge
        {
            ///Cycle detected
            //flagCycle = true;
            low[s] = min ( low[s], low[t] );
        }
    }

    if ( disc[s] == low[s] )
    {
        while ( 1 )
        {
            int lastNode = tarjan.back();
//            cycle[lastNode] = s;
            tarjan.pop_back();
            vis[lastNode] = BLACK;
            if(flg) printf(", ");
            flg=1;
            printf("%s",mps[lastNode].c_str());
            if ( lastNode == s )
            {
                break;
            }
            //printf(", ");
        }
        puts("");
        flg=0;
    }

}


int main()
{
#ifdef dipta007
    READ("in.txt");
//        WRITE("out.txt");
#endif // dipta007

    int n,m,ci=1;
    while(getII(n,m))
    {
        if(n==0 && m==0) break;
        if(ci>1) printf("\n");
        mp.clear();
        mps.clear();
        tarjan.clear();
        int c=1;
        adjlist.assign(n+4, vi());
        FOR(i,1,m)
        {
            string s1,s2;
            cin >> s1 >> s2;
            if(mp[s1]==0)
            {
                mp[s1]=c;
                mps[c]=s1;
                c++;
            }
            if(mp[s2]==0)
            {
                mp[s2]=c;
                mps[c]=s2;
                c++;
            }
            adjlist[mp[s1]].PB(mp[s2]);
        }
        CLR(vis);
        globalCnt=1;
        printf("Calling circles for data set %d:\n",ci++);
        FOR(i,1,n)
        {
            flg=0;
            if(vis[i]==0) SCC(i);
        }

    }

    return 0;
}


