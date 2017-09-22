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

#ifdef dipta00
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

bool check(char st[1004])
{
    debug(st)
    int len = strlen(st);

    if(st[0]==st[len-1]) return 0;
    FOR(i,0,len-2)
    {
        if(st[i]==st[i+1]) return 0;
    }
    return 1;
}

int main()
{
#ifdef dipta007
//    READ("in.txt");
//    WRITE("out.txt");
#endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n,r,o,y,g,b,vv;
        getI(n);
        getIII(r,o,y);
        getIII(g,b,vv);

        vi v;
        v.PB(r);
        v.PB(y);
        v.PB(b);

        sort(ALL(v));

        printf("Case #%d: ",ci);
        //if(v[0]+v[1]<=v[2])
        {
            vector < char > W,B;
            int rf,yf,bf;
            rf=yf=bf=1;
            FOR(i,0,0)
            {
                if(v[i]==r && rf==1)
                {
                    rf=0;
                    FOR(j,1,r)
                    {
                        W.PB('R');
                    }
                }
                else if(v[i]==y && yf==1)
                {
                    yf=0;
                    FOR(j,1,y)
                    {
                        W.PB('Y');
                    }
                }
                else if(v[i]==b && bf==1)
                {
                    bf=0;
                    FOR(j,1,b)
                    {
                        W.PB('B');
                    }
                }
            }
            int i =2;
            if(v[i]==r && rf==1)
            {
                rf=0;
                FOR(j,1,r)
                {
                    B.PB('R');
                }
            }
            else if(v[i]==y && yf==1)
            {
                yf=0;
                FOR(j,1,y)
                {
                    B.PB('Y');
                }
            }
            else if(v[i]==b && bf==1)
            {
                bf=0;
                FOR(j,1,b)
                {
                    B.PB('B');
                }
            }

            i=1;
            int cnt = (int)v[1];
            vector < char > X;
            while(cnt--)
            {
                char ch;
                if(rf==1) ch='R';
                if(yf==1) ch='Y';
                if(bf==1) ch='B';
                X.PB(ch);
            }

            FOR(i,0,(int)W.size()-1) debug("W",W[i]);
            FOR(i,0,(int)B.size()-1) debug("B",B[i]);
            debug(W.size(), B.size())

            if(n%2==0)
            {
                int cnt = X.size();
                while(cnt--)
                {
                    char ch;
                    if(rf==1) ch='R';
                    if(yf==1) ch='Y';
                    if(bf==1) ch='B';
                    if(W.size()<B.size()) W.PB(ch);
                    else B.PB(ch);
                }
                if(W.size()!=B.size())
                {
                    printf("IMPOSSIBLE\n");
                    continue;
                }
                else
                {
                    char res[n+2];
                    reverse(ALL(B));
                    for(int i=0,in=0; i<n; i+=2,in++)
                    {
                        res[i] = B[in];
                    }
                    for(int i=1,in=0; i<n; i+=2,in++)
                    {
                        res[i] = W[in];
                    }
                    res[n] = NULL;
                }
            }
            else
            {
                if(W.size()<B.size())
                {

                    int cnt = X.size();
                    while(cnt--)
                    {
                        char ch;
                        if(rf==1) ch='R';
                        if(yf==1) ch='Y';
                        if(bf==1) ch='B';
                        if(W.size()<B.size()) W.PB(ch);
                        else B.PB(ch);
                    }

                    char res[n+2];
                    res[0] = B[0];

                    reverse(ALL(B));
                    int i,in;
                    for(int i=2,in=0; in<B.size()-1 && i<n; i+=2,in++)
                    {
                        res[i] = B[i];
                    }
                    for(int i=1,in=0; i<n; i+=2,in++)
                    {
                        res[i] = W[i];
                    }
                    res[n] = NULL;
                    if(check(res)==0) strcpy(res,"IMPOSSIBLE");
                    printf("%s\n",res);
                }
                else
                {
                    int cnt = X.size();
                    while(cnt--)
                    {
                        char ch;
                        if(rf==1) ch='R';
                        if(yf==1) ch='Y';
                        if(bf==1) ch='B';
                        if(W.size()<B.size()) W.PB(ch);
                        else B.PB(ch);
                    }

                    char res[n+2];
                    res[0] = W[0];

                    reverse(ALL(W));
                    int i,in;
                    for(int i=2,in=0; in<W.size()-1 && i<n; i+=2,in++)
                    {
                        res[i] = W[i];
                    }
                    for(int i=1,in=0; i<=n; i+=2,in++)
                    {
                        res[i] = B[i];
                    }
                    res[n] = NULL;
                    if(check(res)==0) strcpy(res,"IMPOSSIBLE");
                    printf("%s\n",res);
                }
            }
        }
        //else printf("IMPOSSIBLE\n");
    }

    return 0;
}




