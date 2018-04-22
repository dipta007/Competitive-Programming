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
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	              vector < int >
#define    vii 	              vector < vector < int > >
#define    pii 	              pair< int, int >
#define    ff 	              first
#define    ss 	              second
#define    ll	              long long
#define    ull 	              unsigned long long
#define    POPCOUNT           __builtin_popcount
#define    POPCOUNTLL         __builtin_popcountll
#define    RIGHTMOST          __builtin_ctzll
#define    LEFTMOST(x)        (63-__builtin_clzll((x)))

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#define dipta00
#ifdef dipta007
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
     #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
        template <typename Arg1>
        void __f(const char* name, Arg1&& arg1){
            cerr << name << " : " << arg1 << std::endl;
        }
        template <typename Arg1, typename... Args>
        void __f(const char* names, Arg1&& arg1, Args&&... args){
            const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
        }
#else
    #define debug(args...)  /// Just strip off all debug tokens
    #define trace(...) ///yeeeee
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

int n;
ll a[100004];
map <int, int> mp;
vector < pii > vp, vp1;

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    while( cin >> n )
    {
        mp.clear();
        vp.clear();
        vp1.clear();

        FOR(i,0,n-1)
        {
            cin >> a[i];
            mp[a[i]]++;
        }

        for(auto p: mp)
        {
            ///       val   cnt
            vp.PB( MP(p.ff, p.ss ) );
            vp1.PB( MP(p.ff, p.ss ) );
        }

        ll res = 0;
        FOR(i,1,(int)vp.size()-1)
        {
            ll l = vp[i-1].ff;
            ll r = vp[i].ff;
            ll cntL = vp[i-1].ss;
            ll cntR = vp[i].ss;

            debug("prev", i, l, r, cntL, cntR, res);

            while(l < r && cntL > cntR)
            {
                res += cntR;
                cntR *= 2LL;
                r--;
            }

            debug("prev", i, l, r, cntL, cntR, res);
            if(l == r)
            {
                vp[i].ff = r;
                vp[i].ss += vp[i-1].ss;
            }
            else
            {
                vp[i].ff = r;
                vp[i].ss = cntR;
            }

            if(i+1 < vp.size())
            {
                if(vp[i+1].ss + 1 == vp[i].ss) /// soman kora jai 1 ta komaia
                {
                    if(vp[i-1].ff < vp[i].ff-1) /// choto kore mixed hoi na
                    {
                        if(vp[i].ss > 2)
                        {
                            res++;
                            vp[i].ss--;
                        }
                    }
                    else if(vp[i-1].ss + 1 <= vp[i].ss - 1) /// mixed hoileo kom thake
                    {
                        res++;
                        vp[i].ss--;
                    }
                }
            }
        }

        ll res2 = 0;
        ll l = vp1[0].ff;
        ll r = vp1[1].ff;
        ll cntL = vp1[0].ss;
        ll cntR = vp1[1].ss;

        if(cntR+1 == cntL && l > 1)
        {
            res2++;
            vp1[0].ss --;
        }
        FOR(i,1,(int)vp1.size()-1)
        {
            ll l = vp1[i-1].ff;
            ll r = vp1[i].ff;
            ll cntL = vp1[i-1].ss;
            ll cntR = vp1[i].ss;

            debug("prev", i, l, r, cntL, cntR);

            while(l < r && cntL > cntR)
            {
                res2 += cntR;
                cntR *= 2LL;
                r--;
            }

            debug("prev", i, l, r, cntL, cntR);
            if(l == r)
            {
                vp1[i].ff = r;
                vp1[i].ss += vp1[i-1].ss;
            }
            else
            {
                vp1[i].ff = r;
                vp1[i].ss = cntR;
            }

            if(i+1 < vp1.size())
            {
                if(vp1[i+1].ss + 1 == vp1[i].ss) /// soman kora jai 1 ta komaia
                {
                    if(vp1[i-1].ff < vp1[i].ff-1) /// choto kore mixed hoi na
                    {
                        if(vp1[i].ss > 2)
                        {
                            res2++;
                            vp1[i].ss--;
                        }
                    }
                    else if(vp1[i-1].ss + 1 <= vp1[i].ss - 1) /// mixed hoileo kom thake
                    {
                        res2++;
                        vp1[i].ss--;
                    }
                }
            }
        }


        cout << min(res,res2) << endl;
    }


    return 0;
}

