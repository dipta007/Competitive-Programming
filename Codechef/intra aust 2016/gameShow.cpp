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
#define    SZ(c) 	         (int)c.size()
#define    PB(x)             push_back(x)

#define    rep(i,n)          for(i=1;i<=n;i++)
#define    repI(i,n)         for(i=0;i<n;i++)
#define    F(i,L,R)	         for (int i = L; i < R; i++)
#define    FF(i,L,R) 	     for (int i = L; i <= R; i++)
#define    FR(i,L,R) 	     for (int i = L; i > R; i--)
#define    FRF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()

#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    CPY(d, s)         memcpy(d, s, sizeof(s))

#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    ui    unsigned int
#define    us 	 unsigned short
#define    ld 	 long double


template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }

//******************DELETE****************
#define shubhashis
#ifdef shubhashis
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

int bitOn(int N,int pos)
{
    return N=N | (1<<pos);
}
int bitOff(int N,int pos)
{
    return N=N & ~(1<<pos);
}
bool bitCheck(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

bool visit[1004][1004];
string dp[1004][1004];
int pri[1004][1004];
int n,m;

bool maxSt(string s1,string s2)
{
    if(s1.size()>s2.size()) return 1;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]>s2[i]) return 1;
    }
    return 0;
}

map <pair <int,string> ,int> mp;
string ans;

void call(int in,int ersd,string st)
{
    //debug(in,ersd,st)
    if(ersd>=m || in>=st.size())
    {
        if(ersd==m && maxSt(st,ans)) ans=st;
    }

    if(mp.find(MP(in,st))!=mp.end()) return;
    mp[MP(in,st)]=1;

    call(in+1,ersd,st);
    if(ersd<m)
    {
        string tmp=st;
        tmp.erase(tmp.begin()+in);
        call(in+1,ersd+1,tmp);
    }

}


//string call(int in,int ersd,string st)
//{
//    debug(st)
//    if(ersd>=m || in>=st.size())
//    {
//        if(ersd==m) return "";
//        else return "BAD";
//    }
//    //if(pri[in][ersd]!=-1) return dp[in][ersd];
//
//
//    string s1,s2;
//    s2=st[in]+call(in+1,ersd,st);
//    string tmp=st;
//    tmp.erase(tmp.begin()+in);
//    s1=call(in+1,ersd+1,tmp);
//
//    if(maxSt(s1,s2) && s1!="BAD")
//    {
//        dp[in][ersd]=s1;
//        pri[in][ersd]=1;
//    }
//    else
//    {
//        dp[in][ersd]=s2;
//        pri[in][ersd]=2;
//    }
//
//    return dp[in][ersd];
//}

void print(int in,int ersd,string st)
{
    if(ersd>=m || in>=n)
    {
        printf("%s\n",st.c_str());
        return;
    }
    if(pri[in][ersd]==1)
    {
        st.erase(st.begin()+in);
        print(in+1,ersd+1,st);
    }
    else
    {
        call(in+1,ersd,st);
    }
}

int main() {
    READ("in.txt");
    //WRITE("out.txt");

    int t;
    getI(t);
    for(int ci=1;ci<=t;ci++)
    {
        mp.clear();
        getII(n,m);
        getchar();
        string st;
        getline(cin,st);
        ans="";
        call(0,0,st);
        debug(ans)
        //print(0,0,st);

    }

    return 0;
}


