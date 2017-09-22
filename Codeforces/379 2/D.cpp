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

#ifdef dipta00
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


#define p22 pair < pii , int >
vector < p22 > vp;

int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while(~getI(n))
    {
        vp.clear();
        int x,y;
        getII(x,y);
        vp.PB(MP(MP(x,y), 0));
        FOR(i,1,n)
        {
            getchar();
            char ch;
            int r,c;
            scanf("%c %d %d",&ch,&r,&c);
            debug(ch,r,c)
            if(ch=='B')
            {
                vp.PB(MP(MP(r,c), 1));
            }
            else if(ch=='R')
            {
                vp.PB(MP(MP(r,c), 2));
            }
            else if(ch=='Q')
            {
                vp.PB(MP(MP(r,c), 3));
            }
        }
        sort(ALL(vp));
        int in;
        FOR(i,0,n)
        {
            if(vp[i].ff.ff==x && vp[i].ff.ss==y)
            {
                in = i;
                break;
            }
        }

        int mark[10];
        CLR(mark);
        int flg=0;
        ROF(i,in-1,0)
        {
            int a = vp[i].ff.ff;
            int b = vp[i].ff.ss;
            int c = vp[i].ss;
            debug(a,b,c)
            if(c==1)
            {
                if(mark[7]==0 && b<y && abs(a-x)==abs(b-y))
                {
                    flg=1;
                }
                if(mark[1]==0 && b>y && abs(a-x)==abs(b-y))
                {
                    flg=1;
                }
            }
            else if(c==2)
            {
                if(mark[6]==0 && x==a)
                {
                    flg=1;
                }
                if(mark[0]==0 && y==b)
                {
                    flg=1;
                }
            }
            else
            {
                if(mark[7]==0 && b<y && abs(a-x)==abs(b-y))
                {
                    flg=1;
                }
                if(mark[1]==0 && b>y && abs(a-x)==abs(b-y))
                {
                    flg=1;
                }
                if(mark[6]==0 && x==a)
                {
                    flg=1;
                }
                if(mark[0]==0 && y==b)
                {
                    flg=1;
                }
            }
            if(flg) break;
            if(x==a) mark[6]=1;
            if(b<y && abs(a-x)==abs(b-y)) mark[7]=1;
            if(y==b) mark[0]=1;
            if(b>y && abs(a-x)==abs(b-y)) mark[1]=1;
        }

        if(flg)
        {
            printf("YES\n");
            continue;
        }

        FOR(i,in+1,n)
        {
            int a = vp[i].ff.ff;
            int b = vp[i].ff.ss;
            int c = vp[i].ss;
            debug(a,b,c)
            if(c==1)
            {
                if(mark[5]==0 && b<y && abs(a-x)==abs(b-y))
                {
                    flg=1;
                }
                if(mark[3]==0 && b>y && abs(a-x)==abs(b-y))
                {
                    flg=1;
                }
            }
            else if(c==2)
            {
                if(mark[2]==0 && x==a)
                {
                    flg=1;
                }
                if(mark[4]==0 && y==b)
                {
                    flg=1;
                }
            }
            else
            {
                if(mark[5]==0 && b<y && abs(a-x)==abs(b-y))
                {
                    flg=1;
                }
                if(mark[3]==0 && b>y && abs(a-x)==abs(b-y))
                {
                    flg=1;
                }
                if(mark[2]==0 && x==a)
                {
                    flg=1;
                }
                if(mark[4]==0 && y==b)
                {
                    flg=1;
                }
            }
            if(flg) break;
            if(x==a) mark[2]=1;
            if(b<y && abs(a-x)==abs(b-y)) mark[5]=1;
            if(y==b) mark[4]=1;
            if(b>y && abs(a-x)==abs(b-y)) mark[3]=1;
        }
        if(flg)
        {
            printf("YES\n");
        }
        else printf("NO\n");
    }

    return 0;
}



