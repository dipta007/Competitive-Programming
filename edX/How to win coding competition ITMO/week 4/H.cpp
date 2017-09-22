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

#ifdef dipta
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

int n,adj[26][26];
//bool vis[(1<<25)+4][25];
//map <int, string> dp;
int tt;


//string call(int mask, int u)
//{
//    debug(__builtin_popcount(mask))
//    if(__builtin_popcount(mask)==n)
//    {
//        return "*";
//    }
//
//    if(vis[mask]==1) return dp[mask];
//    vis[mask]=1;
//
//    //string ret="#";
//    FOR(i,0,n-1)
//    {
//        if(bitCheck(mask,i)==0 && adj[u][i]==1)
//        {
//            string paisi = call(bitOn(mask,i), i);
//            if(paisi[paisi.size()-1]=='*')
//            {
//                paisi =  " -> " + NumberToString(i+1) + paisi;
//                return dp[mask]=paisi;
//            }
//        }
//    }
//    return "#";
//}
int flg;
void callNew(int mask, int u,string st)
{
    if(__builtin_popcount(mask)==n)
    {
        flg=0;
        printf("%s\n",st.c_str());
//        debug(st);
        return;
    }

    if(vis[mask][u]==1) return;
    vis[mask][u]=1;

    //string ret="#";
    FOR(i,0,n-1)
    {
        if(bitCheck(mask,i)==0 && adj[u][i]==1)
        {
            callNew(bitOn(mask,i), i, st + " -> " + NumberToString(i+1));
        }
    }
    return;
}

int flg;

int dp[(1<<25)+4];
vi path[(1<<25)+4];

int callFinal(int mask,int u)
{
    debug(__builtin_popcount(mask),n,u)
    if(__builtin_popcount(mask)==n)
    {
        return 1;
    }

    int &ret = dp[mask];
    if(ret!=-1) return ret;

    ret=0;
    FOR(i,0,n-1)
    {
        if(bitCheck(mask,i)==0 && adj[u][i]==1)
        {
            ret = callFinal(bitOn(mask,i), i) || ret;
            if(ret==1)
            {
                path[mask].PB(i);
//                return ret;
            }
        }
    }
    return ret;
}

void pathPrint(int mask,string st)
{
    debug(st)
    if(__builtin_popcount(mask)==n)
    {
        printf("%s\n",st.c_str());
        return;
    }
    FOR(i,0,(int)path[mask].size()-1)
    {
        int k = path[mask][i];
        pathPrint(bitOn(mask,k), st + " -> " + NumberToString(k+1));
    }
    path[mask].clear();
}

int main() {
//    #ifdef dipta007
        READ("hamiltonian.in");
        WRITE("hamiltonian.out");
//    #endif // dipta007

//    int n;
    while(~getI(n))
    {
//        CLR(vis);
        //SET(dp);
        getchar();
        CLR(adj);
        FOR(i,0,n-1)
        {
            string st;
            getline(cin,st);
            FOR(j,0,n-1)
            {
                if(st[j]=='1') adj[i][j]=1;
            }
        }


        flg=1;
        FOR(i,0,n-1)
        {
            SET(dp);
            if(callFinal(bitOn(0,i), i))
            {
//                pathPrint()
                debug(i)
                pathPrint(bitOn(0,i), NumberToString(i+1));
                flg=0;
            }
        }
//        FOR(i,0,n-1)
//        {
//            string get = NumberToString(i+1) + call(bitOn(0,i), i);
//            if(get[get.size()-1]=='*')
//            {
//                flg=0;
//                FOR(i,0,(int)get.size()-2)
//                {
//                    printf("%c",get[i]);
//                }
//                printf("\n");
//            }
//        }
        if(flg) printf("No paths\n");
    }

    return 0;
}




