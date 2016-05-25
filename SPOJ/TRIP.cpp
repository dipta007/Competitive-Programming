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

string s1,s2;
int dp[84][84];
int pri[84][84];

int call(int i,int j)
{
    if(i>=s1.size() || j>=s2.size()) return 0;

    int &ret= dp[i][j];
    if(ret!=-1) return ret;
    int o1,o2;

    if(s1[i]==s2[j])
    {
        pri[i][j]=0;
        return ret = 1+ call(i+1,j+1);
    }
    else
    {
        o1 = call(i+1,j);
        o2 = call(i,j+1);
    }
    if(o1>o2) pri[i][j]=1;
    else if(o2>o1) pri[i][j]=2;
    else pri[i][j]=3;

    return ret = max(o1,o2);
}

set <string> vs;
map <string,bool> processed[81][81];

void print(int i, int j, string st)
{
    if(processed[i][j].find(st)!=processed[i][j].end()) return;
    processed[i][j][st]=1;
    if(i>=s1.size() || j>=s2.size())
    {
        vs.insert(st);
        return;
    }

    if(pri[i][j]==0)
    {
        print(i+1,j+1,st+s1[i]);
    }
    else if(pri[i][j]==1)
    {
        print(i+1,j,st);
    }
    else if(pri[i][j]==2)
    {
        print(i,j+1,st);
    }
    else
    {
//        if(s1[i]<s2[j])
        {
            print(i+1,j,st);
            print(i,j+1,st);
        }
//        else
        {
//            print(i,j+1,st);
//            print(i+1,j,st);
        }
    }
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int t;
    getI(t);
    getchar();
    FOR(ci,1,t)
    {
        SET(dp);
        getline(cin,s1);
        getline(cin,s2);

        FOR(i,0,80)
        {
            FOR(j,0,80)
            {
                processed[i][j].clear();
            }
        }

        call(0,0);
        vs.clear();
        print(0,0,"");
        FOREACH(it,vs)
        {
            {
                printf("%s\n",it->c_str());
            }
        }
    }

    return 0;
}



