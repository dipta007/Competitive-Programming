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
#define    getL(a)           scanf("%I64d",&a)
#define    getLL(a,b)        scanf("%I64d%I64d",&a,&b)
#define    getLLL(a,b,c)     scanf("%I64d%I64d%I64d",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getL(n)           scanf("%I64d",&n)
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
     #define debug(args...) {dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
//******************DELETE****************

const int MX=100004;
ll a[MX],n;
ll dp[MX][5];
vector <ll> vr;

ll call(int pos,int koto)
{

    if(koto>=4 || vr.size()==4)
    {
        sort(ALL(vr));
        ll a=vr[0];
        ll b=vr[1];
        ll c=vr[2];
        ll d=vr[3];

//        if(a==b && c==d) return a*c;
//        else if(a-1==b && c==d) return b*c;
//        else if(a==b-1 && c==d) return a*c;
//        else if(a==b && c-1==d) return a*d;
//        else if(a==b && c==d-1) return a*c;
//        else if(a-1==b && c-1==d) return b*d;
//        else if(a-1==b && c==d-1) return b*c;
//        else if(a==b-1 && c-1==d) return a*d;
//        else if(a==b-1 && c==d-1) return a*c;
//        else return 0;

        ll r1,r2;
        r1=labs(a-b);
        r2=labs(c-d);
        if(r1==0 && r2==0) return a*c;
        else if(r1==0 && r2==1) return (a*min(c,d));
        else if(r1==1 && r2==0) return (min(a,b)*c);
        else if(r1==1 && r2==1) return (min(a,b)*min(c,d));
        else return 0;
    }
    if(pos>=n) return 0;

    if(dp[pos][koto]!=-1) return dp[pos][koto];

    ll p1,p2,p3;
    p1=p2=p3=0;

    vr.PB(a[pos]);
    p1=call(pos+1,koto+1);
    vr.pop_back();

    p2=call(pos+1,koto);

    return dp[pos][koto]=max(p1,p2);
}


int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    while(~getI(n))
    {
        SET(dp);
        for(int i=0;i<n;i++)
            getL(a[i]);
        printf("%I64d\n",call(0,0));
    }

    return 0;
}

