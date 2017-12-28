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
#define    SZ(c) 	         (int)c.size()
#define    PB(x)             push_back(x)

#define    F(i,L,R)	         for (int i = L; i < R; i++)
#define    FF(i,L,R) 	     for (int i = L; i <= R; i++)
#define    FR(i,L,R) 	     for (int i = L; i > R; i--)
#define    FRF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()

#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    CPY(d, s)         memcpy(d, s, sizeof(s))

#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getC(n)           scanf("%c",&n)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    ui    unsigned int
#define    us 	 unsigned short
#define    ld 	 long double

#define    debug(a)     { cout << a <<endl; }
#define    debugI()     { cout << "*" <<endl; }
#define    debugII()    { cout << "**" <<endl; }
#define    debugIII()   { cout << "***" <<endl; }

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }

vector <int> adj[20004];
int color[20004];
int visited[20004];
int c1=0,c2=0;

void BFS(int src)
{
    c1=0,c2=0;
    queue <int> Q;
    Q.push(src);
    if(c1>c2)
    {
        color[src]=1;
        c1++;
    }
    else
    {
        color[src]=2;
        c2++;
    }
    visited[src]=1;
    while(!Q.empty())
    {
        int u=Q.front();
        int k=color[u];
//        debugI();
//        debug(k);
//        debugI();
        Q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
//            debug(v);
            if(visited[v]==-1)
            {
//                debugII();
                Q.push(v);
                visited[v]=1;
            }
            if(k==1 && color[v]==0)
            {
                color[v]=2;
                c2++;
            }
            else if(k==2 && color[v]==0)
            {
                color[v]=1;
                c1++;
            }
        }
    }
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int t;
    getI(t);
    for(int ci=1;ci<=t;ci++)
    {
        int n;
        getI(n);
        CLR(color);
        CLR(visited);
        int src;
        for(int i=0;i<=20000;i++)
            adj[i].clear();
        for(int i=0;i<n;i++)
        {
            int u,v;
            getII(u,v);
            if(i==0) src=u;
            visited[u]=-1;
            visited[v]=-1;
            adj[u].PB(v);
            adj[v].PB(u);
        }

        c1=0,c2=0;
        int flg=1;
        int res=0;
        while(flg)
        {
            BFS(src);
            flg=0;
            for(int i=1;i<=20000;i++)
            {
                if(visited[i]==-1)
                {
                    flg=1;
                    src=i;
                    break;
                }
            }
//            debug(src);
            res+=_max(c1,c2);
//            debug(c1);
//            debug(c2);
        }

        printf("Case %d: %d\n",ci,res);
    }


    return 0;
}

