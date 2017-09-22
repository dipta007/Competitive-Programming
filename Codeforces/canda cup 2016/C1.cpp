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

vii adj;
char res[2][13];


int main()
{
#ifdef dipta007
    READ("in.txt");
    //WRITE("out.txt");
#endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    string st;
    while(getline(cin,st))
    {
        adj.assign(30, vi());
        int len = st.size();
        int flg=1,mid;
        FOR(i,0,len-1)
        {
            int now = st[i]-'A';
            if(i==0)
            {
                int rgt = st[i+1]-'A';
                if(now==rgt) flg=0;
                adj[now].PB(rgt);
            }
            else if(len-1)
            {
                int lft = st[i-1]-'A';
                if(lft==now) flg=0;
                adj[now].PB(lft);
            }
            else
            {
                int lft = st[i-1]-'A';
                adj[now].PB(lft);
                int rgt = st[i+1]-'A';
                adj[now].PB(rgt);
                if(lft==now || rgt==now) flg=0;
            }
            if(flg==0) break;
            if(adj[now].size()>1)
            {
                mid = now;
            }
        }

        if(flg==0)
        {
            printf("Impossible\n");
            continue;
        }

        string lftSide, rgtSide, cycle;
        lftSide = rgtSide = cycle = "";
        int cf = 0;
        FOR(i,0,len-1)
        {
            if(st[i]==(char)(mid +'A'))
            {
                cf++;
                continue;
            }
            if(cf==0)
            {
                lftSide += st[i];
            }
            else if(cf==1)
            {
                cycle += st[i];
            }
            else
            {
                rgtSide += st[i];
            }
        }
        int cycleSz = cycle.size();

        if(cycleSz%2==1)
        {
            pii midPos;
            midPos.ff = 0;
            midPos.ss = 12-cycleSz/2;
            res[0][midPos.ss] = (mid + 'A');

            int in = 0;
            FOR(i,midPos.ss+1,12)
            {
                res[0][i] = cycle[in++];
            }
            ROF(i,12,midPos.ss)
            {
                res[1][i] = cycle[in++];
            }

            reverse(ALL(lftSide));
            in=0;
            ROF(i,midPos.ss-1, 0)
            {
                if(in>=lftSide.size()) break;
                res[0][i] = lftSide[in++];
            }

            if(in<lftSide.size())
            {
                FOR(i,0,midPos.ss-1)
                {
                    if(in>=lftSide.size()) break;
                    res[1][i] = lftSide[in++];
                }
            }

            in=0;
            ROF(i,midPos.ss-1,0)
            {
                if(in>=rgtSide.size()) break;
                res[1][i] = rgtSide[in++];
            }
            if(in<rgtSide.size())
            {
                FOR(i,0,midPos.ss)
                {
                    if(in>=rgtSide.size()) break;
                    res[0][i] = rgtSide[in++];
                }
            }
//            printf("Impossible\n");
//            continue;
        }
        else
        {
            pii midPos;
            midPos.ff = 0;
            midPos.ss = 13 - cycleSz/2 - 1;
            res[0][midPos.ss] = mid + 'A';
            int in = 0;
            FOR(i,midPos.ss+1, 12)
            {
                res[0][i] = cycle[in++];
            }
            ROF(i,12,midPos.ss+1)
            {
                res[1][i] = cycle[in++];
            }

            reverse(ALL(lftSide));
            in=0;
            ROF(i,midPos.ss, 0)
            {
                if(in>=lftSide.size()) break;
                res[1][i] = lftSide[in++];
            }

            if(in<lftSide.size())
            {
                FOR(i,0,midPos.ss-1)
                {
                    if(in>=lftSide.size()) break;
                    res[0][i] = lftSide[in++];
                }
            }

            in=0;
            ROF(i,midPos.ss-1,0)
            {
                if(in>=rgtSide.size()) break;
                res[0][i] = rgtSide[in++];
            }
            if(in<rgtSide.size())
            {
                FOR(i,0,midPos.ss)
                {
                    if(in>=rgtSide.size()) break;
                    res[1][i] = rgtSide[in++];
                }
            }
        }

        FOR(i,0,1)
        {
            FOR(j,0,12)
            {
                printf("%c",res[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}




