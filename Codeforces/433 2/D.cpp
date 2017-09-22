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
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
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

#define piii pair <int, pii >
const int SZ = 1e6+4;
vector < pii > jao[SZ], asho[SZ];
int jaoKoita[SZ];
ll jaoCost[SZ];
int ashoKoita[SZ];
ll ashoCost[SZ];

int main()
{
#ifdef dipta007
//        READ("in.txt");
//        WRITE("out.txt");
#endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,m,k;
    while(~getIII(n,m,k))
    {
        FOR(i,1,m)
        {
            int a,b,c,d;
            getIII(a,b,c);
            getI(d);
            if(c==0)
            {
                jao[a].PB(MP(b,d)); /// time = node = tk
            }
            else if(b==0)
            {
                asho[a].PB(MP(c,d));
            }
        }

        set <int > s;
        int tmp[n+4];

        CLR(tmp);
        jaoCost[0] = 0;
        FOR(i,1,1e6)
        {
            jaoCost[i] = jaoCost[i-1];
            for(int in = 0; in<jao[i].size(); in++)
            {
                int node = jao[i][in].ff;
                int cost = jao[i][in].ss;

                s.insert(node);
                if(tmp[node]==0)
                {
                    tmp[node] = cost;
                    jaoCost[i] = jaoCost[i-1] + (ll)cost;
                }
                else if(cost < tmp[node])
                {
                    ll kotoBesi = tmp[node] - cost;
                    jaoCost[i] = (jaoCost[i-1] - kotoBesi);
                    tmp[node] = cost;
                }
            }
            jaoKoita[i] = s.size();
        }

        CLR(tmp);
        s.clear();
        ashoCost[1000001] = 0;
        ROF(i, 1e6, 1)
        {
            ashoCost[i]= ashoCost[i+1];
            for(int in = 0; in < asho[i].size(); in++)
            {
                int node = asho[i][in].ff;
                int cost = asho[i][in].ss;

                s.insert(node);
                if(tmp[node]==0)
                {
                    tmp[node] = cost;
                    ashoCost[i] = ashoCost[i+1] + (ll)cost;
                }
                else if(cost < tmp[node])
                {
                    ll kotoBesi = tmp[node] - cost;
                    ashoCost[i] = (ashoCost[i+1] - kotoBesi);
                    tmp[node] = cost;
                }
            }
            ashoKoita[i] = s.size();
        }

        debug("*")

        int flg = 0;
        ll mini =LONG_LONG_MAX;
        FOR(i,1,1e6)
        {
//            if(i+k+1 > 1000000) break;
//            if(jaoCost[i]>0 && ashoCost[i+k+1] >0)
//            {
////                flg = 1;debug("F")
//                ll tot = jaoCost[i] + ashoCost[i+k+1];
//                mini = min(mini, tot);
//            }
            //debug(i, jaoKoita[i], jaoCost[i], ashoKoita[i+k+1], ashoCost[i+k+1])
            if(jaoKoita[i] == n)
            {
                int berHou = i + k + 1;
                if(berHou <= 1e6 && ashoKoita[berHou]==n)
                {
                    flg = 1;
                    ll tot = jaoCost[i] + ashoCost[berHou];
                    mini = min(mini, tot);
                }
            }
        }

        if(flg == 0) mini = -1;
        printf("%lld\n",mini);
    }

    return 0;
}



