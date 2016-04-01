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
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
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
#define    bitCheck(N,in)    ((bool)(a&(1<<(k))))
#define    bitOff(N,in)      (a&(~(1<<(k))))
#define    bitOn(N,in)       (a|(1<<(k)))
#define    iseq(a,b)          (fabs(a-b)<EPS)
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

vector < stack<char> > rankk,suit;

bool check(int pos, char r,char s)
{
    if(rankk[pos].top()==r) return 1;
    if(suit[pos].top()==s) return 1;
    return 0;
}

void process(string st)
{
    int len = st.size();

    for(int i=0; i<len; i+=3)
    {
        stack <char> r,s;
        r.push(st[i]);
        s.push(st[i+1]);

        rankk.PB(r);
        suit.PB(s);
    }
}

void postProcess()
{
    FOR(i,0,rankk.size()-1)
    {
//        debug(i,rankk[i].size(),rankk[i-3].size(),rankk[i-1].size())
        if( i>=3 && check(i-3, rankk[i].top(), suit[i].top()) )
        {
//            debug("*")
            rankk[i-3].push(rankk[i].top());
            suit[i-3].push(suit[i].top());
            rankk[i].pop();
            suit[i].pop();
            if(rankk[i].empty())
            {
                rankk.erase(rankk.begin()+i);
                suit.erase(suit.begin()+i);
            }
            i-=4;
        }
        else if(i>=1 && check(i-1, rankk[i].top(), suit[i].top()) )
        {
//            debug("**")
            rankk[i-1].push(rankk[i].top());
            suit[i-1].push(suit[i].top());
            rankk[i].pop();
            suit[i].pop();
            if(rankk[i].empty())
            {
                suit.erase(suit.begin()+i);
                rankk.erase(rankk.begin()+i);
            }
            i-=2;
        }
    }
}

int main()
{
#ifdef dipta007
    READ("in.txt");
    WRITE("out.txt");
#endif // dipta007

    string st1,st2;
    while(getline(cin,st1))
    {
        if(st1.size()==1) break;
        getline(cin,st2);
//        debug(st1);
//        debug(st2);

        rankk.clear();
        suit.clear();

        process(st1);
        process(st2);
        postProcess();

        if(rankk.size()==1)
            printf("1 pile remaining: ");
        else printf("%d piles remaining: ",rankk.size());
        for(int i=0; i<rankk.size(); i++)
        {
            if(i) printf(" ");
            printf("%d",rankk[i].size());
        }
        puts("");
    }

    return 0;
}




