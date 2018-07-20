//#include <algorithm>
//#include <bitset>
//#include <cassert>
//#include <cctype>
//#include <climits>
//#include <cmath>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <fstream>
//#include <iostream>
//#include <iomanip>
//#include <iterator>
//#include <list>
//#include <map>
//#include <numeric>
//#include <queue>
//#include <set>
//#include <sstream>
//#include <stack>
//#include <string>
//#include <utility>
//#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
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
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	              vector < int >
#define    vii 	              vector < vector < int > >
#define    pii 	              pair< int, int >
#define    ff 	              first
#define    ss 	              second
#define    ll	              long long
#define    ull 	              unsigned long long
#define    sf scanf
#define    pf printf
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

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

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************

int t, n, m;

int dp[100][2][2];
int vis[100][2][2];
vi A, B;
int tt, lim;

ll andd[64], orr[64];

int call(int pos, int high_flag, int low_flag) {

    int &ret = dp[pos][high_flag][low_flag];
    if (pos == lim) return ret = 0;

    int &v = vis[pos][high_flag][low_flag];
    if (v == tt) return ret;
    v = tt;

    int lo = low_flag ? A[pos] : 0;
    int hi = high_flag ? B[pos] : 1;
    ret = (1<<lim)-1;
    for (int i = lo; i <= hi; i++) {
        andd[pos] &= i;
        orr[pos] |= i;
        ret = ret & call(pos+1, high_flag&(i==hi), low_flag&(i==lo));
    }

    return ret;
}

void Cal( ll l, ll r )
{
    /// Give predefined conditions if needed
//    if(l < 0) return 0;
    A.clear();
    B.clear();
    while( l )
    {
        A.PB(l%2);
        l/=2;
    }
    while(r)
    {
        B.PB(r%2);
        r/=2;
    }
    while(A.size() != B.size())
    {
        if(A.size() < B.size()) A.PB(0);
        else B.PB(0);
    }

    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());

    trace(A.size(), B.size());
    lim = A.size();

    tt++;
    FOR(i,0,63) andd[i] = 1, orr[i] = 0;
    call(0, 1, 1);
    return;
}


int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    tt = 0;
    CLR(vis);
    FOR(ci,1,t)
    {
        ll l, r;
        getLL(l,r);

        Cal(l, r);

        ll ans1, ans2, c;
        ans1 = ans2 = 0;
        c = 1;
        ROF(i,lim-1,0)
        {
            ans1 = ans1 + andd[i] * c;
            ans2 = ans2 + orr[i] * c;
            c *= 2;
        }
        pf("Case %d: %lld %lld\n", ci, ans2, ans1);
    }

    return 0;
}


