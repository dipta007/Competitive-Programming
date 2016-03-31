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

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); }
template< class T > T lcm(T a, T b) { return (a / gcd(a, b) * b); }


bool adj[24][24];
bool color[22];
int dis[20];

int  BFS(int s,int e)
{
    color[s]=1;
    dis[s]=0;
    CLR(color);
    CLR(dis);
    queue <int> Q;
    Q.push(s);
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=1;i<=20;i++)
        {
            if(color[i]==0 && adj[u][i]==1)
            {
                dis[i]=dis[u]+1;
                color[i]=1;
                Q.push(i);
                if(i==e)
                    return dis[e];
            }
        }
    }
}

int main() {
    //READ("uva 567.txt");
    //WRITE("out.txt");

    int n,ci=1;
    while(~getI(n))
    {
        //debug(n);
        CLR(adj);
        CLR(color);
        CLR(dis);
        for(int i=0;i<n;i++)
        {
            int k;
            getI(k);
            adj[1][k]=1;
            adj[k][1]=1;
        }
        for(int i=2;i<=19;i++)
        {
            getI(n);
            for(int j=0;j<n;j++)
            {
                int k;
                getI(k);
                adj[i][k]=1;
                adj[k][i]=1;
            }
        }
        int k;
        getI(k);
        for(int i=0;i<k;i++)
        {
            int s,e;
            getII(s,e);
            if(i==0)
                printf("Test Set #%d\n",ci++);
            printf("%2d to %2d: %d\n",s,e,BFS(s,e));
            if(i==k-1)
                printf("\n");
        }
    }

    return 0;
}

