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

int visited[1004];
int dp[1004];
string stt[1004];
int n;

int call(int in)
{
    debug(in)
    if(visited[in]) return dp[in];
    if(in==n) return 1;
    visited[in]=1;
    dp[in]=0;

    string st = stt[in];
    int o1,o2;
    if(st[0]=='A')
    {
        o1= call(in+1);
        o2=o1;
    }
    else if(st[0]=='J')
    {
        stringstream ss(st);
        char c;
        int nn;
        ss >> c;
        ss >> nn;
        nn--;
        o1 = call(nn);
        o2=o1;
    }
    else if(st[0]=='C')
    {
        stringstream ss(st);
        char c;
        int nn;
        ss >> c;
        ss >> nn;
        nn--;
        o1 = call(nn);
        o2 = call(in+1);
    }
    if(o1==o2) return dp[in]=o1;
    else return dp[in]=2;
}

int main() {
    #ifdef dipta007
//        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int t;
    getI(t);
    FOR(ci,1,t)
    {
//        int n;
        getI(n);
        getchar();
//        int visited[n+4];
//        CLR(visited);
//        int flg=0; ///1 = cycle(never), 2=ALWAYS
//        string stt[n];
        FOR(i,0,n-1)
        {
            getline(cin,stt[i]);
        }
//        int in=0;
//        while(1)
//        {
//            debug(in)
//            string st = stt[in];
//            visited[in]=1;
//            if(st[0]=='A')
//            {
//                in++;
//            }
//            else if(st[0]=='J')
//            {
//                stringstream ss(st);
//                char c;
//                int nn;
//                ss >> c;
//                ss >> nn;
//                nn--;
//                if(visited[nn]==1)
//                {
//                    flg=1;
//                    break;
//                }
//                if(nn==n)
//                {
//                    if(flg==0) flg=2;
//                    break;
//                }
//                in=nn;
//            }
//            else if(st[0]=='C')
//            {
//                stringstream ss(st);
//                char c;
//                int nn;
//                ss >> c;
//                ss >> nn;
//                nn--;
//                if(visited[nn]==1)
//                {
//                    in++;
//                    flg=3;
//                }
//                else
//                {
//                    //flg=3;
//                    in=nn;
//                }
//            }
//            if(in==n)
//            {
//                if(flg==0) flg=2;
//                break;
//            }
//        }
        CLR(visited);
        int flg = call(0);
        flg++;
        map <int,string> mp;
        mp[1]="NEVER";
        mp[2]="ALWAYS";
        mp[3]="SOMETIMES";
        printf("%s\n",mp[flg].c_str());
    }

    return 0;
}


