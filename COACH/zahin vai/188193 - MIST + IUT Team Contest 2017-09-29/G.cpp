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
#include <unordered_map>
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
#define    FOR(i,L,R) 	     for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R) 	     for (int i = (int)(L); i >= (int)(R); i--)
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
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    bitCount(a)        __builtin_popcount(a)
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifdef dipta007
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

int n,k;
int p[1004];

//int call(int in, bitset <1004> &now)
//{
//    if(in >= k) return now.count();
//    if(vis[in][now]==1) return mp[in][now];
//    vis[in][now] = 1;
//
//    int ret = call(in+1, now);
//
//    int d = p[in];
//    for(int i = d; i<=n; i+=d)
//    {
//        now.flip(i);
//    }
//    ret = max(ret, call(in+1, now));
//
//    return mp[in][now] = ret;
//}


int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        getII(n,k);
        FOR(i,0,k-1)
        {
            getI(p[i]);
        }
        sort(p,p+k);
        vi v;

        int nn = sqrt(n);

        FOR(i,0,k-1)
        {
            if(p[i] <= nn) v.PB(p[i]);
        }

        int maxy = 0;
        int sz  = (1<< (int)v.size());
        FOR(i,0,(int)sz-1)
        {
            bitset < 1004 > now;
            now.reset();

            FOR(j,0,(int)v.size()-1)
            {
                if(bitCheck(i,j)==1)
                {
                    for(int ik = v[j]; ik<=n; ik+=v[j])
                    {
                        now.flip(ik);
                    }
                }
            }

            if(now.count() > maxy)
            {
                maxy = now.count();
//                maxBit = now;
            }

            debug(i, now.count())
            FOR(ik,0,k-1)
            {
                if(p[ik] > nn)
                {
                    int cnt = 0;

                    for(int j=p[ik]; j<=n; j+=p[ik])
                    {
                        if(now.test(j)==1) cnt--;
                        else cnt++;
                    }

                    if(cnt>0)
                    {
                        for(int j=p[ik]; j<=n; j+=p[ik])
                        {
                            now.flip(j);
                        }
                    }
                }
                if(now.count() > maxy)
                {
                    maxy = now.count();
    //                maxBit = now;
                }
            }

            if(now.count() > maxy)
            {
                maxy = now.count();
//                maxBit = now;
            }
        }

        printf("Case #%d: %d\n",ci, maxy);
    }

    return 0;
}



