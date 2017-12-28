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
int t,n,m;

string name[104];
int price[104][204];
int dp[204][204];
int path[204][204];
vi res;
vector < string > resname;

int call(int mnth, int last)
{
    if(mnth >= m) return 0;

    int &ret = dp[mnth][last];
    if(ret!=-1) return ret;

    ret = 0;
    ret = max(ret , call(mnth+1, last));

    path[mnth][last] = -1;
    FOR(i,0,n-1)
    {
        if(last==i) continue;

        int kk = price[last][mnth] - 100 - price[i][mnth] + call(mnth+1, i);
        if(kk > ret)
        {
            path[mnth][last] = i;
            ret = kk;
        }
    }
    return ret;
}

void dpPrint(int mnth, int last)
{
    if(mnth >= m) return;
    int kk = path[mnth][last];
    if(kk==-1) return dpPrint(mnth+1, last);

    resname.PB(name[kk]);
    res.PB(mnth);
    dpPrint(mnth+1, kk);
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    string ci;
    while( cin >> ci )
    {
        if(ci == "TheEnd")
        {
            cout << "TheEnd" << endl;
            break;
        }

//        int n,m;
        cin >> n >> m;

        FOR(i,0,n-1)
        {
            cin >> name[i];
            FOR(j,0,m-1)
            {
                cin >> price[i][j];
            }
//            debug(name[i])
        }

        SET(dp);
        int strt;
    {
        int res = INF;
        FOR(i,0,n-1)
        {
            int kk = price[i][0] - call(1,i);
//            debug("hjh",i,kk)
            if(kk < res)
            {
                res = kk;
                strt = i;
            }
        }

        cout << ci << endl;
        cout << "Tk " << res << endl;
    }

        res.clear();
        resname.clear();
        resname.PB(name[strt]);
        res.PB(0);
        dpPrint(1,strt);
        res.PB(m);

        repI(i, resname.size())
        {
            cout << resname[i] << " for " << res[i+1]- res[i] << " month(s)" << endl;
        }
        cout << endl;
    }

    return 0;
}


