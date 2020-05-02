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


template< class T > inline T _abs(T n)
{
    return ( (n) < 0 ? -(n) : (n) );
}
template< class T > inline T _max(T a, T b)
{
    return ( ! ( (a) < (b) ) ? (a) : (b) ) ;
}
template< class T > inline T _min(T a, T b)
{
    return ( ( (a) < (b) ) ? (a) : (b) ) ;
}
template< class T > inline T _swap(T &a, T &b)
{
    T temp=a;
    a=b;
    b=temp;
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd( (b), ( (a) % (b) ) ) ;
}
template< class T > inline T lcm(T a, T b)
{
    return ( (a) / gcd( (a), (b) ) * (b) );
}


//******************DELETE****************
#define shubhashis
#ifdef shubhashis
#define debug(args...) {dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
//******************DELETE****************


class Pair
{
public:
    int priority;
    int value;

    Pair(int priority, int value)
        : priority(priority), value(value) {}
};

// comparison functor
class PairCompare
{
public:
    bool operator()(const Pair &t1, const Pair &t2) const
    {
        return t1.priority > t2.priority;
    }
};

const int maxsz = 200004;
int indeg[maxsz];
vector < vector < int > > adj;
int taka[maxsz];

int main()
{
    READ("inmadeD.txt");
    //WRITE("outD.txt");

    int t;
    getI(t);
    for(int ci=1; ci<=t; ci++)
    {
        int n;
        getI(n);
//        priority_queue < Pair , vector<Pair>, PairCompare> pq;
        CLR(indeg);
        CLR(taka);
        queue <int> pq;
        adj.assign(n+4,vector <int> ());
        for(int i=1; i<=n; i++)
        {
            int k;
            getI(k);
            if(i==1) continue;
            indeg[k]++;
            adj[i].PB(k);
            adj[k].PB(i);
        }
        for(int i=1; i<=n; i++)
        {
            if(indeg[i]==0)
                pq.push(i);
        }
        while(!pq.empty())
        {
            int p = pq.front();
            pq.pop();

//            debug(p.priority,p.value);
            set <int> sett;
            for(int i=0; i<adj[p].size(); i++)
            {
                int l = adj[p][i];
                indeg[l]--;
                sett.insert(taka[l]);
                if(indeg[l]==0) pq.push(l);
            }
            for(int i=1;; i++)
            {
                if(sett.find(i)==sett.end())
                {
                    taka[p]=i;
                    break;
                }
            }
        }
        int sum=0;
        for(int i=1;i<=n;i++)
        {
//            debug(i,taka[i]);
            sum+=taka[i];
        }
        printf("Case #%d: %d\n",ci,sum);

    }

    return 0;
}

