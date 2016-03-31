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
#define    getII(a,b) 	     scanf("%d %d", &a, &b)
#define    getIII(a,b,c)     scanf("%d %d %d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld %lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
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


template< class T > inline T _abs(T n) { return ( (n) < 0 ? -(n) : (n) ); }
template< class T > inline T _max(T a, T b) { return ( ! ( (a) < (b) ) ? (a) : (b) ) ; }
template< class T > inline T _min(T a, T b) { return ( ( (a) < (b) ) ? (a) : (b) ) ; }
template< class T > inline T _swap(T &a, T &b) { T temp=a;a=b;b=temp;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd( (b), ( (a) % (b) ) ) ; }
template< class T > inline T lcm(T a, T b) { return ( (a) / gcd( (a), (b) ) * (b) ); }


//******************DELETE****************
#define shubhashis
#ifdef shubhashis
     #define debug(args...) {dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
//******************DELETE****************

int n,adj[104][104],visited[104],src,dest;
set<int> sett;
int sum=0;
stack <int> st;
queue <int> qu;


void DFS(int s)
{
    //if(s==4) debug("****");
    st.push(s);
    qu.push(s);
    sett.insert(s);
    visited[s]=1;
    for(int i=1;i<=n;i++)
    {
        if(adj[s][i]<0)
        {
            if(i==src && sett.size()==n)
            {
                dest=s;
                return;
            }
            else if(visited[i]==0)
            {
                DFS(i);
            }
        }
        else if(adj[s][i]>0)
        {
            if(i==src && sett.size()==n)
            {
                dest=s;
                sum+=adj[s][i];
                return;
            }
            else if(visited[i]==0)
            {
                sum+=adj[s][i];
                DFS(i);
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
        getI(n);
        CLR(adj);
        for(int i=0;i<n;i++)
        {
            int u,v,w;
            getIII(u,v,w);
            adj[u][v]=-1;
            adj[v][u]=w;
        }
        src=1;
        CLR(visited);
        sett.clear();
        sum=0;
        DFS(src);
        int su=st.top();
        st.pop();
        int qh=qu.front();
        qu.pop();
        int s1=0,s2=0;
        while(!st.empty())
        {
            int sk=st.top();
            st.pop();
            int qk=qu.front();
            qu.pop();
            if(adj[su][sk]>0) s1+=adj[su][sk];
            if(adj[qh][qk]>0) s2+=adj[qh][qk];


//            debug(sk,qk);
            su=sk;
            qh=qk;
        }

//        debug(su,qh);
        if(adj[su][qh]>0) s1+=adj[su][qh];
        if(adj[qh][su]>0) s2+=adj[qh][su];
        printf("Case %d: %d\n",ci,_min(s1,s2));
    }

    return 0;
}

