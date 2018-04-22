#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);
int fx[]={0,0,-1,1,-1,1,1,-1};
int fy[]={1,-1,0,0,1,1,-1,-1};

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    pb(x)             push_back(x)
#define    For(i,N)          Forr(i,0,N)
#define    Forr(i,a,b)       FOR(i,a,(b-1))
#define    FOR(i,L,R) 	     for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R) 	     for (int i = (int)(L); i >= (int)(R); i--)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, x)         memset(p, x, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getF(n)           scanf("%lf",&n)
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	              vector < int >
#define    vii 	              vector < vector < int > >
#define    pii 	              pair< int, int >
#define    ff 	              first
#define    ss 	              second
#define    fi	              first
#define    si 	              second
#define    ll	              long long
#define    ull 	              unsigned long long
#define    ld                 long double
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
template <typename T> T power(T x, T e){T r = 1;while(e){r=(e&1)?r*x:r;x=x*x;e>>=1;} return r;}

#define dipta00
#ifdef dipta007
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
     #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
        template <typename Arg1>
        void __f(const char* name, Arg1&& arg1){
            cerr << name << " : " << arg1 << std::endl;
        }
        template <typename Arg1, typename... Args>
        void __f(const char* names, Arg1&& arg1, Args&&... args){
            const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
        }
#else
    #define debug(args...)  /// Just strip off all debug tokens
    #define trace(...) ///yeeeee
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************

const int MAX = (int)3e5;
const int N=(int)1e6+5;
const int mod=(int)1e9+7;
int main() {
    ios_base::sync_with_stdio(false);cout.setf(ios::fixed); cout.precision(10);cout.tie(nullptr); cin.tie(nullptr);
    #ifdef shaft
        //READ("in.txt");
        //WRITE("out.txt");
    #endif //Renegades

    int a,b;
    while(~getII(a,b))
    {
        int ta = a, tb = b;
        if(!a && !b) break;

        map <int, int> mp;
        mp[a] = 1;
        FOR(i,2,10000)
        {
            int xx = 0;
            while(a)
            {
                int kk = a % 10;
                xx += kk*kk;
                a /= 10;
            }
            if(mp[xx] != 0) break;
            a = xx;
            mp[xx] = i;
//            debug(xx);
        }

        int mn = INF;
        int flg = 0;
        if(mp[b] != 0)
        {
            mn = min(mn, mp[b] - 1 + 2);
            flg = 1;
        }
        FOR(i,1,10000)
        {
            int xx = 0;
            while(b)
            {
                int kk = b % 10;
                xx += kk*kk;
                b /= 10;
            }
//            debug(xx);
            if(mp[xx] != 0)
            {
                flg = 1;
                mn = min(mn, mp[xx] + i +1);
            }
            b = xx;
        }
        if(!flg) printf("%d %d 0\n",ta,tb);
        else printf("%d %d %d\n",ta,tb,mn);
    }

    return 0;
}

