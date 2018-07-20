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

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)          freopen(f, "w", stdout)

#define    MP(x, y)          make_pair(x, y)
#define    SZ(c)             (int)c.size()
#define    PB(x)             push_back(x)

#define    F(i,L,R)          for (int i = L; i < R; i++)
#define    FF(i,L,R)         for (int i = L; i <= R; i++)
#define    FR(i,L,R)         for (int i = L; i > R; i--)
#define    FRF(i,L,R)        for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p)            p.begin(),p.end()
#define    ALLR(p)           p.rbegin(),p.rend()

#define    SET(p)            memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    CPY(d, s)         memcpy(d, s, sizeof(s))

#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d %d", &a, &b)
#define    getIII(a,b,c)     scanf("%d %d %d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld %lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)

#define    vi    vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    psi   pair< string, int >
#define    ff    first
#define    ss    second
#define    ll    long long
#define    ull   unsigned long long
#define    ui    unsigned int
#define    us    unsigned short
#define    ld    long double


template< class T > inline T _abs(T n) { return ( (n) < 0 ? -(n) : (n) ); }
template< class T > inline T _max(T a, T b) { return ( ! ( (a) < (b) ) ? (a) : (b) ) ; }
template< class T > inline T _min(T a, T b) { return ( ( (a) < (b) ) ? (a) : (b) ) ; }
template< class T > inline T _swap(T &a, T &b) { T temp=a;a=b;b=temp;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd( (b), ( (a) % (b) ) ) ; }
template< class T > inline T lcm(T a, T b) { return ( (a) / gcd( (a), (b) ) * (b) ); }


//******************DELETE****************
#define shubhas
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

struct point
{
    int x,y;
};

struct data
{
    int y,ase;
};

const int max_n=104;
int n,w,k;
point p[max_n];
int dp[max_n][max_n];
vector <data> pp;
int szpp;

bool cmp(const data &a,const data &b)
{
    if(a.y<b.y) return true;
    else if(a.y==b.y) return a.ase<b.ase;
    return false;
}

int call(int pos,int baki)
{
    if(pos<0 || pos>=szpp) return 0;
    if(baki>=k) return 0;

    if(dp[pos][baki]!=-1) return dp[pos][baki];

    int prof1=0;
    int prof2=0;
    int bad=0,low=pp[pos].y,high=low+w;
    int ppos=szpp;
    for(int i=pos;i<szpp;i++)
    {
        if(pp[i].y>=low && pp[i].y<=high) bad+=pp[i].ase;
        else
        {
            ppos=i;
            break;
        }
    }
    if(bad>0)
        prof1=bad+call(ppos,baki+1);
    prof2=call(pos+1,baki);
    //debug(prof1,prof2);
    return (dp[pos][baki]=max(prof1,prof2));
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int t;
    getI(t);
    for(int ci=1;ci<=t;ci++)
    {
        pp.clear();
        SET(dp);
        getIII(n,w,k);
        set <int> ps;
        map <int,int> mp;
        for(int i=0;i<n;i++)
        {
            getII(p[i].x,p[i].y);
            if(ps.find(p[i].y)==ps.end())
            {
                data k;
                k.y=p[i].y;
                k.ase=0;
                pp.PB(k);
            }
            ps.insert(p[i].y);
            mp[p[i].y]++;
        }
        for(int i=0;i<pp.size();i++)
        {
            pp[i].ase = mp[pp[i].y];
            //debug(pp[i].y,pp[i].ase);
        }
        sort(ALL(pp),cmp);
        szpp=pp.size();
        printf("Case %d: %d\n",ci,call(0,0));
    }

    return 0;
}
