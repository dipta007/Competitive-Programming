#include <bits/stdc++.h>
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
#define    ll	              long long
#define    ull 	              unsigned long long
#define    POPCOUNT           __builtin_popcount
#define    POPCOUNTLL         __builtin_popcountll
#define    RIGHTMOST          __builtin_ctzll
#define    LEFTMOST(x)        (63-__builtin_clzll((x)))
#define    sf scanf
#define    pf printf
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

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

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

#define MAX 600004
int bit[MAX];
void update ( int x, int v )
{
    while ( x < MAX )
    {
        bit[x] += v;
        x += x & (-x);
    }
}
int query ( int x )
{
    int res = 0;
    while ( x )
    {
        res += bit[x];
        x -= x & (-x);
    }
    return res;
}


struct data
{
    int x, y1 , y2, type;
    data() {}
    data(int xx, int yy1, int yy2, int tt)
    {
        x = xx, y1 = yy1, y2 = yy2, type = tt;
    }

    bool operator < (const data& d) const {
        if(x == d.x)
        {
            return type >= d.type;
        }
        return x < d.x;
    }
};


int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

    int n,m;
    while(~getII(n,m))
    {
        unordered_map < int , int > mp, rev;
        vector < data > vd;
        set <int> s;

        FOR(i,1,n)
        {
            data d;
            getII(d.x, d.y1);
            d.y2 = i;
            d.type = 1;

            s.insert(d.x);
            s.insert(d.y1);

            vd.PB(d);
        }
        FOR(i,1,m)
        {
            int x,y,a,b;
            getII(x,y);
            getII(a,b);
            s.insert(x);
            s.insert(y);
            s.insert(a);
            s.insert(b);

            data d;
            d.x = x, d.y1 = y, d.y2 = b, d.type = 0;
            vd.PB(d);
            d.x = a, d.y1 = y, d.y2 = b, d.type = 2;
            vd.PB(d);
        }

        int in = 1;
        for(auto v: s)
        {
            debug(v, in)
            rev[in] = v;
            mp[v] = in++;
        }

        FOR(i,0,n-1)
        {
//            debug(vd[i].x, mp[vd[i].x], mp[-10])
            vd[i].x = mp[vd[i].x];
            vd[i].y1 = mp[vd[i].y1];
        }

        FOR(i,n,(int)vd.size()-1)
        {
//            debug(vd[i].x, mp[vd[i].x], mp[-10])
            vd[i].x = mp[vd[i].x];
            vd[i].y1 = mp[vd[i].y1];
            vd[i].y2 = mp[vd[i].y2];
        }

        sort(ALL(vd));

        CLR(bit);
        int ans[n+4];
        FOR(i,0,(int)vd.size()-1)
        {
            int tt = vd[i].type;
            int x = vd[i].x;
            int y1 = vd[i].y1;
            int y2 = vd[i].y2;

            trace(tt, rev[x], rev[y1], rev[y2]);
            if(tt == 1)
            {
                ans[y2] = query(y1);
            }
            else if(tt == 0)
            {
                update(y1+1, 1);
                update(y2, -1);
            }
            else if(tt == 2)
            {
                update(y1+1, -1);
                update(y2, 1);
            }
        }

        FOR(i,1, n)
        {
            pf("%d\n", ans[i]);
        }


    }

    return 0;
}


//10 1
//1 0
//1 1
//1 2
//1 3
//1 4
//2 1
//2 2
//2 3
//2 4
//2 0
//1 1 3 3
