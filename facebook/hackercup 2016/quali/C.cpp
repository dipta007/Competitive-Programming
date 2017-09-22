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
#define    iseq(a,b)          (fabs(a-b)<EPS)
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

double dp[22][22][20004];
bool vis[22][22][20004];

double call(int in, int dice,int total)
{
    if(in==0)
    {
        if(total==0) return 1.0;
        return 0.0;
    }
    double &ret = dp[in][dice][total];
    if(vis[in][dice][total]) return ret;
    vis[in][dice][total] = 1;

    double res = 0.0;
    FOR(i,1,dice)
    {
        if(total-i>=0)
        {
            res += call(in-1, dice, total-i);
        }
    }
    ret = res/dice;
    return ret;
}


int main() {
    #ifdef dipta007
        READ("in.txt");
        WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    CLR(vis);
    FOR(ci,1,t)
    {
        int h,s;
        cin >> h >> s;
        double ans = 0.0;
        FOR(i,1,s)
        {
            string st;
            cin >> st;
            int hh=h;
            int x=0,y=0,z=0,jog=0;
            int j;
            for(j=0;j<st.size();j++)
            {
                if(st[j]=='d') break;
                x = x*10 + (st[j]-'0');
            }
            for(j=j+1;j<st.size();j++)
            {
                if(st[j]=='+')
                {
                    jog=1;
                    break;
                }
                else if(st[j]=='-')
                {
                    break;
                }
                y= y*10 + (st[j]-'0');
            }
            for(j=j+1;j<st.size();j++)
            {
                z= z*10 + (st[j]-'0');
            }
            if(jog)
            {
                hh -= z;
            }
            else
            {
                hh += z;
            }
            //debug(hh)
            double naP = 0.0;
            FOR(i,0,hh-1)
            {
                naP += call(x,y,i);
            }
            double haP = 1.0 - naP;
            ans = max(ans, haP);
        }
        printf("Case #%d: %.6lf\n",ci,ans);
    }

    return 0;
}



