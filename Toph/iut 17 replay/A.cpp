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
#define    bitCheck(a,k)     ((bool)(a&(1<<(k))))
#define    bitOff(a,k)       (a&(~(1<<(k))))
#define    bitOn(a,k)        (a|(1<<(k)))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    iseq(a,b)         (fabs(a-b)<EPS)
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    POPCOUNT           __builtin_popcount
#define    POPCOUNTLL         __builtin_popcountll
#define    RIGHTMOST          __builtin_ctzll
#define    LEFTMOST(x)        (63-__builtin_clzll((x)))
#define    UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())

template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

#ifdef dipta007
#define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1)
{
    cerr << name << " : " << arg1 << std::endl;
}
template < typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names+1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma+1, args...);
}
#else
#define debug(args...)  // Just strip off all debug tokens
#define trace(...)
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
///****************** template ends here ****************
int t,n,m;
vector<ll> v;

void makeNum(const string& s)
{
    ll num = 0;
    repI(i,s.size())
    {
        num *= 10;
        num += s[i]-'0';
    }
    if(num <= 1e12)
        v.push_back(num);
}

void insert(string s)
{
    string rev = s;
    reverse(ALL(rev));
    string num = s+rev;
    makeNum(num);
    if(s.size() != 6)
    {
        repI(i,10)
        {
            num = s+(char)(i+48)+rev;
            makeNum(num);
        }
    }
}
int tot;
void backtrack(int pos,string s)
{
    if(pos)insert(s);
    if(pos == 6)
    {
        return;
    }
    int mn = pos == 0?1:0;
    int mx = 9;
    FOR(i,mn,mx)
    backtrack(pos+1,s+(char)(i+48));
}
bool isPal(int num)
{
    stringstream ss;
    ss << num;
    string s;
    ss >> s;
    string rev = s;
    reverse(ALL(rev));
    return s == rev;
}

//vi res;
ll diff[2000004];
ll cum[2000016];
ll mod = 1000000007;

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    backtrack(0,"");
    rep(i,9)v.push_back(i);
    UNIQUE(v);
    sort(ALL(v));
    debug(v.size())
//    repI(i,120)debug(v[i])
//    debug(v.size())
//    int cnt = 0;
//    rep(i,1000000)if(isPal(i))cnt++;
//    debug(cnt);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        ll l,r;
        getLL(l,r);

        auto low = lower_bound(ALL(v), l) - v.begin();
        auto high = lower_bound(ALL(v), r) - v.begin();
        if(binary_search(ALL(v), r) == false) high--;
        int tot = (high - low + 1);

        ll age = l;
        ll pore;
        ll ans = 0;
        int in = 0;
        FOR(i,low,high)
        {

            diff[in++] = (v[i] - age+1);

//            debug(diff[in-1]);

            age = v[i]+1;
        }
        diff[in++] = (r - v[high] + 1);

        CLR(cum);
        for(int i=in-1; i>=0; i-=2)
        {
            cum[i] = (diff[i] + cum[i+2]) %mod;
        }
        for(int i=in-2; i>=0; i-=2)
        {
            cum[i] = (diff[i] + cum[i+2]) %mod;
        }

        ll res = 0;
        FOR(i,0,in-1)
        {
            res += ((ll)diff[i] * (ll)cum[i+1]) % mod;
            res %= mod;
        }

        printf("Case %d: %lld\n",ci, res);

//        debug(ans);
//        int lft =
    }

    return 0;
}

