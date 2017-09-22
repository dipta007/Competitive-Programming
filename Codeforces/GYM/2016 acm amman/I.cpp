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

string st;
int n,m;

int check(int r,int c)
{
    int cnt=0;
    FOR(i,0,(int)st.size()-1)
    {
        if(st[i]=='>' && c<m) c++;
        else if(st[i]=='<' && c>1) c--;
        else if(st[i]=='^' && r<n) r++;
        else if(st[i]=='v' && r>1) r--;
        else cnt++;
    }
    return cnt;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    FOR(ci,1,t)
    {
        //int n,m;
        //string st;
        cin >> n >> m >> st;
        int x=0,y=0;
        int mnx=INF,mny=INF,mxx=-INF,mxy=-INF;
        FOR(i,0,(int)st.size()-1)
        {
            if(st[i]=='>') x++;
            else if(st[i]=='<') x--;
            else if(st[i]=='^') y++;
            else if(st[i]=='v') y--;
            mnx = min(mnx,x);
            mxx = max(mxx,x);
            mny = min(mny,y);
            mxy = max(mxy,y);
        }

        if(mxx<0) mxx=0;
        if(mxy<0) mxy=0;
        if(mnx>0) mnx=0;
        if(mny>0) mny=0;

        mxx = abs(mxx);
        mxy = abs(mxy);
        mnx = abs(mnx);
        mny = abs(mny);



        ///r upor & c bam
        int c = max(1, m-mxx);
        int r = max(1, n-mxy);
        int res = check(r,c);

        ///r nich & c bam
        c = max(1, m-mxx);
        r = min(n , 1+mny);
        res = min(res, check(r,c));

        ///r upor & c dan
        c = min(m, 1+mnx);
        r = max(1, n-mxy);
        res = min(res, check(r,c));

        ///r nich & c dan
        c = min(m, 1+mnx);
        r = min(n , 1+mny);
        res = min(res, check(r,c));

        cout << res << endl;
    }

    return 0;
}



