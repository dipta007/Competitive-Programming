#pragma comment(linker, "/stack:640000000")
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

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

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
//int t,n,m;

ll dist[14][14];
unordered_map < ll, bool > mp;
int strt = 0;
int mid;
int n;
ll L;

ll get(int x, vi &v, int y)
{
    ll ans = dist[x][v[0]];
    FOR(i,1,(int)v.size()-1)
    {
        ans += dist[v[i-1]][v[i]];
    }
    ans += dist[v.back()][y];

    return ans;
}

void call1(int mask)
{
    vi v;
    FOR(i,0,n-1)
    {
        if(bitCheck(mask, i)==1) v.PB(i);
    }
    mp.clear();
    if(v.size()==0)
    {
        mp[dist[strt][mid]] = 1;
        return;
    }

    sort(ALL(v));

    do
    {

        ll now = get(strt, v, mid);
        mp[now] = 1;

    }while( next_permutation(ALL(v)) );
}

int call0(int mask)
{
    vi v;
    FOR(i,0,n-1)
    {
        if(bitCheck(mask, i)==0 && i!=strt && i!=mid) v.PB(i);
    }

    if(v.size()==0)
    {
        ll now = dist[mid][strt];
        if(mp[L-now]) return 1;
        return 0;
    }

    sort(ALL(v));

    do
    {

        ll now = get(mid, v, strt);
        debug(v[0], now)
        if(mp[L-now]) return 1;

    }while( next_permutation(ALL(v)) );

    return 0;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

//    int n;
//    ll L;
    while(~getI(n))
    {
        getL(L);

        repI(i,n) repI(j, n) getL(dist[i][j]);

//        int strt = 0;

        int flg = 0;
        FOR(m,1,n-1)
        {
            mid = m;
            int nn = n-2;
            int mm = nn/2;

//            unordered_map < ll, bool > mp;

//            int flg = 0;
debug(m)
            FOR(i,0,(1<<n)-1)
            {
                if(bitCheck(i, strt)==1 || bitCheck(i, mid)==1) continue;
                if(bitCount(i)!=mm) continue;

                debug(i)

                call1(i);
                if(call0(i))
                {
                    flg = 1;
                    break;
                }

                debug(m, i)
            }
            if(flg) break;
        }
        if(flg) printf("possible\n");
        else printf("impossible\n");
    }


    return 0;
}


