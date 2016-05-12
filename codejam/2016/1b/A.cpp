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

int main() {
    #ifdef dipta007
        READ("in.txt");
        WRITE("outM.txt");
    #endif // dipta007

    int t;
    getI(t);
    getchar();
    FOR(ci,1,t)
    {
        string st;
        getline(cin,st);
        map <char,int> mp;
        int len = st.size();
        FOR(i,0,len-1)
        {
            mp[st[i]]++;
        }
        vi v;
        while(1)
        {
            int sz = v.size();
            if(mp['G']>0)
            {
                mp['E']--;
                mp['I']--;
                mp['G']--;
                mp['H']--;
                mp['T']--;
                v.PB(8);
            }
            else if(mp['Z']>0)
            {
                mp['Z']--;
                mp['E']--;
                mp['R']--;
                mp['O']--;
                v.PB(0);
            }
            else if(mp['W']>0)
            {
                mp['T']--;
                mp['W']--;
                mp['O']--;
                v.PB(2);
            }
            else if(mp['U']>0)
            {
                mp['F']--;
                mp['O']--;
                mp['U']--;
                mp['R']--;
                v.PB(4);
            }
            else if(mp['X']>0)
            {
                mp['S']--;
                mp['I']--;
                mp['X']--;
                v.PB(6);
            }
            else if(mp['N']>0 && mp['S']>0 && mp['E']>=2 && mp['V']>0)
            {
                mp['S']--;
                mp['E']--;
                mp['V']--;
                mp['E']--;
                mp['N']--;
                v.PB(7);
            }
            else if(mp['H']>0 && mp['R']>0 && mp['T']>0 && mp['E']>=2)
            {
                mp['T']--;
                mp['H']--;
                mp['R']--;
                mp['E']--;
                mp['E']--;
                v.PB(3);
            }
            else if(mp['N']>0 && mp['O']>0 && mp['E']>0)
            {
                mp['O']--;
                mp['N']--;
                mp['E']--;
                v.PB(1);
            }
            else if(mp['V']>0 && mp['I']>0 && mp['F']>0 && mp['E']>0)
            {
                mp['F']--;
                mp['I']--;
                mp['V']--;
                mp['E']--;
                v.PB(5);
            }
            else if(mp['N']>=2 && mp['I']>0  && mp['E']>0)
            {
                mp['N']--;
                mp['I']--;
                mp['N']--;
                mp['E']--;
                v.PB(9);
            }

            if(sz==v.size()) break;
        }
        sort(ALL(v));
        printf("Case #%d: ",ci);
        FOR(i,0,(int)v.size()-1)
        {
            printf("%d",v[i]);
        }
        puts("");
    }

    return 0;
}



