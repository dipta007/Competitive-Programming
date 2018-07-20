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

int getId(char ch)
{
    if(ch == 'A') return 1;
    if(ch == 'T') return 10;
    if(ch == 'J') return 11;
    if(ch == 'Q') return 12;
    if(ch == 'K') return 13;
    return (ch - '0');
}

#define ui unsigned ll

ui dp[14][14][14][14][7];
int vis[14][14][14][14][7];

ui call(int one, int two, int three, int four, int last)
{
//    debug(one, two, three, four, last);
    if(one == 0 && two == 0 && three == 0 && four == 0) return 1;
    ui &ret = dp[one][two][three][four][last];
    if(vis[one][two][three][four][last] == 1) return ret;
    vis[one][two][three][four][last] = 1;

    ret = 0;
    if(one)
    {
        if(last == 2) ret += (ui)(one - 1) * call(one-1, two, three, four, 1);
        else ret += (ui)(one) * call(one-1, two, three, four, 1);
    }
    if(two)
    {
        if(last == 3) ret += (ui)2 * (two - 1) * call(one+1, two-1, three, four, 2);
        else ret += (ui)2 * two * call(one+1, two-1, three, four, 2);
    }
    if(three)
    {
        if(last == 4) ret += (ui)3 * (three - 1) * call(one, two+1, three-1, four, 3);
        else ret += (ui)3 * three * call(one, two+1, three-1, four, 3);
    }
    if(four)
    {
        ret += (ui)4 * four * call(one, two, three+1, four-1, 4);
    }
    return ret;
}

int freq[20];
int df[10];

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    CLR(vis);
    FOR(ci,1,t)
    {
        int n;
        cin >> n;

        CLR(freq);
        CLR(df);
        FOR(i,0,n-1)
        {
            string st;
            cin >> st;
            freq[ getId(st[0]) ]++;
        }


        FOR(i,0,13) df[ freq[i] ]++;

        debug(df[1], df[2], df[3], df[4])

        cout << "Case " << ci << ": " << call(df[1], df[2], df[3], df[4], 0) << endl;
    }

    return 0;
}


