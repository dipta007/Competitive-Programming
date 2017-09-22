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

int w[104][104];
int g[104][104];
int b[104][104];

int queryW(int lr, int lc, int hr, int hc)
{
    if(lr==0 && lc==0) return w[hr][hc];
    if(lr==0) return w[hr][hc] - w[hr][lc-1];
    if(lc==0) return w[hr][hc] - w[lr-1][hc];
    return w[hr][hc] - w[hr][lc-1] - w[lr-1][hc] + w[lr-1][lc-1];
}

int queryG(int lr, int lc, int hr, int hc)
{
    if(lr==0 && lc==0) return g[hr][hc];
    if(lr==0) return g[hr][hc] - g[hr][lc-1];
    if(lc==0) return g[hr][hc] - g[lr-1][hc];
    return g[hr][hc] - g[hr][lc-1] - g[lr-1][hc] + g[lr-1][lc-1];
}

int queryB(int lr, int lc, int hr, int hc)
{
    if(lr==0 && lc==0) return b[hr][hc];
    if(lr==0) return b[hr][hc] - b[hr][lc-1];
    if(lc==0) return b[hr][hc] - b[lr-1][hc];
    return b[hr][hc] - b[hr][lc-1] - b[lr-1][hc] + b[lr-1][lc-1];
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    FOR(ci,1,t)
    {
        CLR(w);
        CLR(g);
        CLR(b);
        int r,c;
        cin >> r >> c;
        string st[r];
        FOR(i,0,r-1)
        {
            cin >> st[i];
        }

        FOR(i,0,r-1)
        {
            FOR(j,0,c-1)
            {
                if(st[i][j]=='w') w[i][j]=1;
                else if(st[i][j]=='g') g[i][j]=1;
                else b[i][j]=1;
            }
        }

        FOR(i,1,r-1)
        {
            w[i][0] += w[i-1][0];
            g[i][0] += g[i-1][0];
            b[i][0] += b[i-1][0];
        }
        FOR(i,1,c-1)
        {
            w[0][i] += w[0][i-1];
            g[0][i] += g[0][i-1];
            b[0][i] += b[0][i-1];
        }

        FOR(i,1,r-1)
        {
            FOR(j,1,c-1)
            {
                w[i][j] = w[i][j] + w[i-1][j] + w[i][j-1] - w[i-1][j-1];
                g[i][j] = g[i][j] + g[i-1][j] + g[i][j-1] - g[i-1][j-1];
                b[i][j] = b[i][j] + b[i-1][j] + b[i][j-1] - b[i-1][j-1];
            }
        }

        debug("*")

//        FOR(i,0,r-1)
//        {
//            FOR(j,0,c-1)
//            {
//                cout << b[i][j] << " ";
//            }
//            cout << endl;
//        }

        int res = 0;

        FOR(i,0,r-1)
        {
            FOR(j,0,c-1)
            {
                int low = 1, high=min(c-j, r-i);
                debug(low, high)
                int now = -1;
                while(low <= high)
                {
                    int mid = (low + high) / 2;

//                    if(i==0 && j==4)
//                    {
//                        debug(mid, queryB(i,j,i+mid-1,j+mid-1), b[i+mid-1][j+mid-1])
//                    }
                    if(st[i][j]=='w')
                    {
                        if(queryW(i,j,i+mid-1,j+mid-1) == mid*mid)
                        {
                            now = mid*mid;
                            low = mid + 1;
                        }
                        else high = mid - 1;
                    }
                    if(st[i][j]=='g')
                    {
                        if(queryG(i,j,i+mid-1,j+mid-1) == mid*mid)
                        {
                            now = mid*mid;
                            low = mid + 1;
                        }
                        else high = mid - 1;
                    }
                    if(st[i][j]=='b')
                    {
                        if(queryB(i,j,i+mid-1,j+mid-1) == mid*mid)
                        {
                            now = mid*mid;
                            low = mid + 1;
                        }
                        else high = mid - 1;
                    }
                }


                res = max(res, now);
            }
        }
        cout << res << endl;
    }

    return 0;
}



