#include <bits/stdc++.h>
using namespace std;

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
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
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	              vector < int >
#define    vii 	              vector < vector < int > >
#define    pii 	              pair< int, int >
#define    ff 	              first
#define    ss 	              second
#define    ll	              long long
#define    ull 	              unsigned long long
#define    sf scanf
#define    pf printf
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

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

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************

int t, n, m;

vector < string > vs;
int dist[111][111];

int dp[111][(1<<15)+16];
int path[111][(1<<15)+16];

string res = "Z";

int get(int x, int y)
{
    int lx = vs[x].size();
    int ly = vs[y].size();

    /// Partially matched
    int mx = min(lx, ly);
    FOR(i, lx-mx, lx)
    {
        int sz = lx - i;
        if(lx-sz >= 0 && (lx-sz) < lx && ly >= sz &&
           vs[x].substr(lx-sz, sz) == vs[y].substr(0, sz))
            return sz;
    }
    return 0;
}

void pre()
{
    CLR(dist);
    FOR(i,0,n-1)
    {
        FOR(j,0,n-1)
        {
            trace(i,j);
            if(i == j)
            {
                dist[i][j] = 0;
                continue;
            }
            dist[i][j] = (int)vs[j].size() - get(i, j);
        }
    }
}

int call(int in, int mask)
{
    int &ret = dp[in][mask];
    if(bitCount(mask) == n) return ret = 0;
    if(ret != -1) return ret;

    ret = INF;
    FOR(i,0,n-1)
    {
        if(bitCheck(mask, i) == 0)
        {
            int matched = dist[in][i];
            int now = matched + call( ((matched == 0) ? in : i), bitOn(mask, i));
            if(now < ret)
            {
                ret = now;
                path[in][mask] = i;
            }
        }
    }
    return ret;
}

void dpPrint(int in, int mask, string st)
{
    if(st > res) return;
    if(bitCount(mask) == n)
    {
        if(st < res) res = st;
        return;
    }

    int kk = path[in][mask];
    int mn = dp[kk][bitOn(mask, kk)] + dist[in][kk];

    FOR(i,0,n-1)
    {
        if(in == i) continue;
        if(bitCheck(mask, i) == 1) continue;
        int matched = dist[in][i];
        int now = matched + dp[i][ bitOn(mask, i) ];
        if(now == mn)
        {
            string tmp = "";
            tmp = vs[i].substr((int)vs[i].size() - matched);
            dpPrint( i , bitOn(mask, i), st + tmp);
        }
    }
    return;
}


int main() {
    #ifdef dipta007
        READ("in.txt");
       WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    FOR(ci,1,t)
    {
        cin >> n;
        vs.clear();

        FOR(i,1,n)
        {
            string st;
            cin >> st;
            vs.PB(st);
        }

        FOR(i,0,n-1)
        {
            FOR(j,0,n-1)
            {
                if(i == j) continue;
                if(vs[i].find(vs[j]) != string::npos)
                    vs[j] = "";
            }
        }

        vector < string > cleaned;
        FOR(i,0,n-1) if(vs[i] != "") cleaned.PB(vs[i]);
        vs.clear();
        vs = cleaned;
        n = vs.size();
        trace(n);

        pre();

        SET(dp);
        CLR(path);
        int mn = INF;
        FOR(i, 0, n-1)
        {
            int tmp = 0;
            int now = (int)vs[i].size() + call(i, bitOn(tmp, i) );
            mn = min(mn, now);
        }
        trace("Sad");

        res =  "Z";
        FOR(i,0,n-1)
        {
            int tmp = 0;
            int now = dp[i][bitOn(tmp, i)] + (int)vs[i].size();
            if(now == mn) dpPrint(i, bitOn(tmp, i), vs[i]);
        }

        cout << "Case " << ci << ": " << res << endl;
    }

    return 0;
}


