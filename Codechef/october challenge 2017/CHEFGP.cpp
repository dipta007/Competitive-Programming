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

#define data pair < pair < int, pair < string, int > > , pair < int, pair < int, int > > >


data make(int v, string st, int x, int y, int a, int b)
{
    return MP( MP( v, MP(st,x) ) , MP(y, MP(a,b ) ) );
}

string solve(int x, int y, int a, int b)
{
    debug(x,y,a,b)
    priority_queue < data > pq;
    pq.push( make(0, "", 0, 0, a, b) );

    while(!pq.empty())
    {
        data d = pq.top();
        pq.pop();
        if(d.ss.ss.ff==0 && d.ss.ss.ss==0) return d.ff.ss.ff;

        /// a dei
        if(d.ff.ss.ss == x && d.ss.ss.ff)
        {
            pq.push( make(d.ff.ff - 1, d.ff.ss.ff + "*a", 1, 0, d.ss.ss.ff-1, d.ss.ss.ss) );
        }
        else if(d.ss.ss.ff)
        {
            pq.push( make(d.ff.ff, d.ff.ss.ff + "a", d.ff.ss.ss+1, 0, d.ss.ss.ff-1, d.ss.ss.ss) );
        }

        /// b dei
        if(d.ss.ff == y && d.ss.ss.ss)
        {
            pq.push( make(d.ff.ff - 1, d.ff.ss.ff + "*b", 0, 1, d.ss.ss.ff, d.ss.ss.ss-1) );
        }
        else if(d.ss.ss.ss)
        {
            pq.push( make(d.ff.ff, d.ff.ss.ff + "b", 0, d.ss.ff+1, d.ss.ss.ff, d.ss.ss.ss-1) );
        }
    }

}


int main() {
    #ifdef dipta007
        READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    FOR(ci,1,t)
    {
        string st;
        int x,y;
        cin >> st >> x >> y;
        string tmp1, tmp2;
        int r1,r2,a1,a2,b1,b2;
        tmp1 = tmp2 = "";
        r1 = r2 = a1 = a2 = b1 = b2 = 0;

        FOR(i,0,(int)st.size()-1)
        {
            if(st[i] == 'a') a1++, a2++;
            else b1++, b2++;
        }

//        cout << solve(x,y,a1,b1) << endl;
//        continue;

        int na = 0, nb = 0;

        int len = st.size()-1;


        int a = a1, b = b1;
        FOR(i,0,len)
        {
            /// a jodi b er theke besi thake
            if(a>b)
            {
                /// kintu a ar boshano jabe na
                if(na==x)
                {
                    na = 0;
                    /// b ase
                    if(b)
                    {
                        printf("b");
                        b--;
                        na = 0;
                        nb++;
                    }
                    /// b o nai
                    else
                    {
                        printf("*a");
                        a--;
                        na = 1;
                        nb = 0;
                    }
                }
                else
                {
                    printf("a");
                    nb = 0;
                    a--;
                    na++;
                }
            }
            else
            {
                if(nb==y)
                {
                    nb = 0;
                    if(a)
                    {
                        printf("a");
                        nb = 0;
                        a--;
                        na++;
                    }
                    else
                    {
                        printf("*b");
                        na = 0;
                        b--;
                        nb = 1;
                    }
                }
                else
                {
                    printf("b");
                    na = 0;
                    b--;
                    nb++;
                }
            }
        }
        printf("\n");
        continue;

        int ff = 1;
        FOR(i,0,len)
        {
            if(na==x)
            {
                na = 0;
                if(b1)
                {
                    ff = 0;
                    tmp1 += "b";
                    b1--;
                    nb++;
                }
                else
                {
                    tmp1 += "*";
                    r1++;
                    tmp1 += "a";
                    a1--;
                    na++;
                }
            }
            else if(a1)
            {
                tmp1 += "a";
                na++;
                a1--;
            }
            else if(b1)
            {
                if(nb==y)
                {
                    tmp1 += "*";
                    r1++;
                    nb = 0;
                }
                tmp1 += "b";
                nb++;
                na = 0;
                b1--;
            }
        }

        ff = 0;
        na = nb = 0;
        a1 = a2, b1 = b2;

        FOR(i,0,len)
        {
            if(nb==y)
            {
                nb = 0;
                if(a1)
                {
                    ff = 1;
                    tmp2 += "a";
                    a1--;
                    na++;
                }
                else
                {
                    tmp2 += "*";
                    r2++;
                    tmp2 += "b";
                    b1--;
                    nb++;
                }
            }
            else if(b1)
            {
                tmp2 += "b";
                nb++;
                b1--;
            }
            else if(a1)
            {
                if(na==x)
                {
                    tmp2 += "*";
                    na = 0;
                    r2++;
                }
                tmp2 += "a";
                na++;
                nb = 0;
                a1--;
            }
        }

        debug(r1,r2,tmp1, tmp2)
        if(r1 <= r2) cout << tmp1 << endl;
        else cout << tmp2 << endl;
    }

    return 0;
}



