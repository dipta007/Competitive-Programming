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
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()

#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))

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
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long


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


vector <int> adj[1004];
        int mark[1004];
        int color[1004];
        int c1,c2;

void BFS(int d)
{
    queue <int> Q;
    Q.push(d);
    color[d]=1;
    mark[d]=1;
    c1++;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            if(mark[v]==1) continue;
            if(color[u]==1)
            {
                color[v]=2;
                c2++;
            }
            else if(color[u]==2)
            {
                color[v]=1;
                c1++;
            }
            mark[v]=1;
            Q.push(v);
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
        int n,m,k;
        getIII(n,m,k);

        CLR(mark);
        CLR(color);
        for(int i=0;i<k;i++)
        {
            int x,y;
            getII(x,y);
            adj[x].PB(y);
            adj[y].PB(x);
        }
        int cnt=0;
        for(int i=0;i<n+m;i++)
        {
            if(mark[i]==0)
            {
                c1=0,c2=0;
                BFS(i);
                if(c1<c2) cnt+=c1;
                else cnt+=c2;
                debug(c1,c2);
            }
        }
        debug(n+m-cnt);
    }

    return 0;
}


